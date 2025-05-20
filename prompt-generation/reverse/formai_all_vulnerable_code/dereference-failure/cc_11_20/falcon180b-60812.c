//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char **argv) {
    int listen_fd, client_fd, port;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <host>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);
    if (port <= 0 || port > 65535) {
        fprintf(stderr, "Invalid port number\n");
        exit(1);
    }

    if (inet_pton(AF_INET, argv[2], &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid host address\n");
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        fprintf(stderr, "Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        printf("Waiting for connection...\n");
        client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_fd == -1) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, MAX_LINE);
            ssize_t bytes_received = recv(client_fd, buffer, MAX_LINE, 0);
            if (bytes_received <= 0) {
                if (bytes_received == 0) {
                    printf("Client disconnected\n");
                } else {
                    fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
                }
                close(client_fd);
                break;
            }

            printf("Received: %s", buffer);

            ssize_t bytes_sent = send(client_fd, buffer, strlen(buffer), 0);
            if (bytes_sent <= 0) {
                if (bytes_sent == 0) {
                    printf("Client disconnected\n");
                } else {
                    fprintf(stderr, "Error sending data: %s\n", strerror(errno));
                }
                close(client_fd);
                break;
            }
        }
    }

    close(listen_fd);
    return 0;
}