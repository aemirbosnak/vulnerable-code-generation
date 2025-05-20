//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: thoughtful
/* This program creates a simple TCP/IP client and server using sockets in C. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(2);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(3);
    }

    printf("Server listening on port %d\n", PORT);

    int client_socket;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            exit(4);
        }

        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        while (1) {
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0) {
                printf("Client disconnected\n");
                close(client_socket);
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Client sent message: %s\n", buffer);

            if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
                printf("Error sending message\n");
                close(client_socket);
                break;
            }
        }
    }

    close(server_socket);
    return 0;
}