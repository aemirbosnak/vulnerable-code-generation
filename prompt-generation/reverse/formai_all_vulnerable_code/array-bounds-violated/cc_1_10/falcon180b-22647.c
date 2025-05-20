//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: minimalist
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            close(client_socket);
            break;
        }
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);
        send(client_socket, buffer, strlen(buffer), 0);
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to bind socket\n");
        close(server_socket);
        return 1;
    }

    if (listen(server_socket, BACKLOG) == -1) {
        printf("Failed to listen on socket\n");
        close(server_socket);
        return 1;
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Failed to accept connection\n");
            continue;
        }
        printf("Client connected\n");
        handle_client(client_socket);
    }

    close(server_socket);
    return 0;
}