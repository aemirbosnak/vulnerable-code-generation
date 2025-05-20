//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket, bytes_received, bytes_sent;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int client_count = 0;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server started on port %d\n", SERVER_PORT);

    while (1) {
        printf("Waiting for client connection...\n");
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            printf("Error accepting client connection\n");
            continue;
        }

        client_count++;
        printf("Client %d connected\n", client_count);

        while (1) {
            bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                printf("Client %d disconnected\n", client_count);
                close(client_socket);
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Client %d sent: %s\n", client_count, buffer);

            bytes_sent = send(client_socket, buffer, strlen(buffer), 0);
            if (bytes_sent <= 0) {
                printf("Error sending data to client\n");
                break;
            }
        }
    }

    close(server_socket);
    return 0;
}