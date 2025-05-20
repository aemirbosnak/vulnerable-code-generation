//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int listen_socket, client_socket, server_socket;
    struct sockaddr_in listen_addr, client_addr, server_addr;
    char buffer[1024];
    int buffer_len;

    if (argc!= 3) {
        printf("Usage: %s <port> <host>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &listen_addr.sin_addr);

    if (bind(listen_socket, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Proxy server started on port %s\n", argv[1]);

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket == -1) {
            printf("Error creating socket\n");
            close(client_socket);
            continue;
        }

        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(atoi(argv[1]));
        inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

        if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            printf("Error connecting to server\n");
            close(client_socket);
            close(server_socket);
            continue;
        }

        while (1) {
            buffer_len = recv(client_socket, buffer, sizeof(buffer), 0);
            if (buffer_len <= 0) {
                printf("Client disconnected\n");
                close(client_socket);
                close(server_socket);
                break;
            }

            send(server_socket, buffer, buffer_len, 0);

            buffer_len = recv(server_socket, buffer, sizeof(buffer), 0);
            if (buffer_len <= 0) {
                printf("Server disconnected\n");
                close(client_socket);
                close(server_socket);
                break;
            }

            send(client_socket, buffer, buffer_len, 0);
        }
    }

    return 0;
}