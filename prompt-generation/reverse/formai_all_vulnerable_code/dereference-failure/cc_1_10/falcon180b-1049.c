//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket, port;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // Bind server socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen on server socket
    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %d\n", port);

    while (1) {
        // Accept client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Forward data between client and server
        while (1) {
            memset(buffer, 0, BUFFER_SIZE);

            ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0) {
                printf("Client disconnected\n");
                close(client_socket);
                break;
            }

            ssize_t bytes_sent = send(server_socket, buffer, bytes_received, 0);

            if (bytes_sent <= 0) {
                printf("Server disconnected\n");
                close(client_socket);
                close(server_socket);
                exit(1);
            }
        }
    }

    close(server_socket);
    return 0;
}