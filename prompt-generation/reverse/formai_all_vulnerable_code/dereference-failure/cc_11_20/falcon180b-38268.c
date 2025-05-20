//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int listen_fd, client_fd, server_fd;
    struct sockaddr_in listen_addr, client_addr, server_addr;
    char buffer[1024];
    int n;

    if (argc!= 3) {
        printf("Usage: %s <listen_port> <server_ip>:<server_port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &listen_addr.sin_addr);

    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_fd, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Proxy server started on port %s\n", argv[1]);

    while (1) {
        client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_fd == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_fd == -1) {
            printf("Error creating socket\n");
            exit(1);
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(atoi(argv[2]));
        inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

        if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            printf("Error connecting to server\n");
            exit(1);
        }

        printf("Connection established with server\n");

        while (1) {
            n = read(client_fd, buffer, sizeof(buffer));
            if (n == 0) {
                printf("Client disconnected\n");
                break;
            }

            if (n == -1) {
                printf("Error reading from client\n");
                exit(1);
            }

            write(server_fd, buffer, n);

            n = read(server_fd, buffer, sizeof(buffer));
            if (n == 0) {
                printf("Server disconnected\n");
                break;
            }

            if (n == -1) {
                printf("Error reading from server\n");
                exit(1);
            }

            write(client_fd, buffer, n);
        }

        close(client_fd);
        close(server_fd);
    }

    return 0;
}