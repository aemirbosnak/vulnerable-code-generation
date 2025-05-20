//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <sys/socket.h>
#include <netdb.h>

#define BACKLOG 10
#define BUFSIZE 8096

int main(int argc, char *argv[]) {
    int sockfd, clientfd;
    struct sockaddr_in serv_addr, client_addr;
    char buffer[BUFSIZE];
    ssize_t bytes_read;

    // Check for correct input format
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }

    // Bind socket
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));
    memset(&serv_addr.sin_zero, 0, sizeof(serv_addr.sin_zero));
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr)) == -1) {
        perror("bind");
        close(sockfd);
        return 1;
    }

    // Listen for connections
    if (listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        close(sockfd);
        return 1;
    }

    printf("Simple HTTP Proxy listening on port %d...\n", atoi(argv[1]));

    // Main accept loop
    while (1) {
        socklen_t client_len = sizeof(struct sockaddr_in);
        if ((clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len)) == -1) {
            perror("accept");
            continue;
        }

        printf("Received connection from %s on socket %d\n", inet_ntoa(client_addr.sin_addr), clientfd);

        // Fork child process to handle request
        if (!fork()) {
            close(sockfd);
            memset(&buffer[0], 0, BUFSIZE);

            bytes_read = read(clientfd, buffer, BUFSIZE);

            printf("Received request:\n%s\n", buffer);

            // Parse the request
            char *request_method = strtok(buffer, " ");
            char *requested_resource = strtok(NULL, " ");
            char *http_version = strtok(NULL, "\r\n");

            if (!request_method || !requested_resource || !http_version) {
                // Malformed request
                write(clientfd, "HTTP/1.1 400 Bad Request\r\n", 26);
                close(clientfd);
                return 1;
            }

            // Create new socket to forward request to remote server
            int remote_sockfd;
            if ((remote_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
                perror("socket");
                write(clientfd, "HTTP/1.1 500 Internal Server Error\r\n", 37);
                close(clientfd);
                return 1;
            }

            struct hostent *server_info;
            struct sockaddr_in remote_server;

            server_info = gethostbyname(requested_resource);
            if (server_info == NULL) {
                perror("gethostbyname");
                write(clientfd, "HTTP/1.1 404 Not Found\r\n", 24);
                close(remote_sockfd);
                close(clientfd);
                return 1;
            }

            memset(&remote_server, 0, sizeof(remote_server));
            remote_server.sin_family = AF_INET;
            remote_server.sin_port = htons(80);
            remote_server.sin_addr = *((struct in_addr *)server_info->h_addr);

            printf("Forwarding request to remote host: %s...\n", requested_resource);

            if (connect(remote_sockfd, (struct sockaddr *)&remote_server, sizeof(struct sockaddr)) == -1) {
                perror("connect");
                write(clientfd, "HTTP/1.1 500 Internal Server Error\r\n", 37);
                close(remote_sockfd);
                close(clientfd);
                return 1;
            }

            // Forward the request to the remote server and receive the response
            ssize_t write_bytes, read_bytes;
            char remote_buffer[BUFSIZE];

            write_bytes = write(remote_sockfd, buffer, bytes_read);
            if (write_bytes == -1) {
                perror("write");
                close(remote_sockfd);
                close(clientfd);
                return 1;
            }

            read_bytes = read(remote_sockfd, remote_buffer, BUFSIZE);
            if (read_bytes == -1) {
                perror("read");
                close(remote_sockfd);
                close(clientfd);
                return 1;
            }

            printf("Received response from remote host:\n%s\n", remote_buffer);

            // Forward the response to the client
            ssize_t write_remote_bytes;

            write_remote_bytes = write(clientfd, remote_buffer, read_bytes);
            if (write_remote_bytes == -1) {
                perror("write");
                close(remote_sockfd);
                close(clientfd);
                return 1;
            }

            // Cleanup and close sockets
            close(remote_sockfd);
            close(clientfd);
            exit(0);
        }

        // Parent process just closes the client socket and moves on to handle next connection
        close(clientfd);
    }

    close(sockfd);
    return 0;
}