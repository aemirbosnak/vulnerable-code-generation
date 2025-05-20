//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096
#define BACKLOG 20

int main(int argc, char *argv[]) {
    int listen_fd, client_fd, status, proxy_fd;
    struct addrinfo hints, *server_info, *p;
    struct sockaddr_storage client_addr;
    socklen_t addr_size;
    char buffer[MAX_BUFFER_SIZE];
    char *hostname, *port;

    if (argc != 2) {
        fprintf(stderr, "Usage: ./proxy port\n");
        exit(EXIT_FAILURE);
    }
    // get port number
    port = argv[1];

    // initialize hints to zero and set desired settings
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    // get address info for server
    if ((status = getaddrinfo(NULL, port, &hints, &server_info)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    // loop through all results and bind to the first available
    for (p = server_info; p != NULL; p = p->ai_next) {
        if ((listen_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("server: socket");
            continue;
        }

        if (bind(listen_fd, p->ai_addr, p->ai_addrlen) == -1) {
            close(listen_fd);
            perror("server: bind");
            continue;
        }

        break;
    }
    freeaddrinfo(server_info);

    if (p == NULL) {
        fprintf(stderr, "server: failed to bind\n");
        exit(EXIT_FAILURE);
    }

    // start listening for clients
    if (listen(listen_fd, BACKLOG) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("Proxy listening on port %s...\n", port);

    // loop to handle client requests
    while (1) {
        addr_size = sizeof client_addr;
        if ((client_fd = accept(listen_fd, (struct sockaddr *) &client_addr, &addr_size)) == -1) {
            perror("accept");
            continue;
        }

        inet_ntop(client_addr.ss_family, &(((struct sockaddr_in *)&client_addr)->sin_addr), buffer, MAX_BUFFER_SIZE);
        printf("Client at %s connected\n", buffer);

        // fork to handle request
        if (fork() == 0) {      
            // read request from client
            recv(client_fd, buffer, MAX_BUFFER_SIZE, 0);
            printf("Received request from client:\n%s\n", buffer);

            // parse request to get hostname and port
            hostname = strstr(buffer, "Host: ") + strlen("Host: ");
            hostname = strtok(hostname, "\r\n");
            printf("Hostname: %s\n", hostname);
            port = strstr(buffer, "Host: ") + strlen("Host: ");
            port = strstr(port, ":") + 1;
            if (port == NULL) {
                port = "80";
            }
            else {
                port = strtok(port, "\r\n");
                printf("Port: %s\n", port);
            }

            // get address info for requested server
            if ((status = getaddrinfo(hostname, port, &hints, &server_info)) != 0) {
                fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
                exit(EXIT_FAILURE);
            }

            // loop through all results and connect to the first available
            for (p = server_info; p != NULL; p = p->ai_next) {
                if ((proxy_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
                    perror("client: socket");
                    continue;
                }

                if (connect(proxy_fd, p->ai_addr, p->ai_addrlen) == -1) {
                    close(proxy_fd);
                    perror("client: connect");
                    continue;
                }

                break;
            }
            freeaddrinfo(server_info);

            if (p == NULL) {
                fprintf(stderr, "client: failed to connect\n");
                exit(EXIT_FAILURE);
            }

            // send request to requested server
            send(proxy_fd, buffer, strlen(buffer), 0);
            printf("Sent request to server:\n%s\n", buffer);

            // receive response from requested server and send it back to client
            while ((status = recv(proxy_fd, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
                send(client_fd, buffer, status, 0);
            }
            close(proxy_fd);
            close(client_fd);
            printf("Connection closed\n");

            exit(EXIT_SUCCESS);
        }
        else {
            close(client_fd);
        }
    }

    return 0;
}