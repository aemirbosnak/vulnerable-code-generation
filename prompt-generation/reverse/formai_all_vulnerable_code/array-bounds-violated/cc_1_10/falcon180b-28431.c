//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    int client_count = 0;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen for connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        // Accept incoming connections
        int new_socket = accept(server_socket, (struct sockaddr *)&client_addr[client_count], sizeof(client_addr[client_count]));
        if (new_socket == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }
        client_count++;
        printf("Client %d connected\n", client_count);

        // Send welcome message
        send(new_socket, "Welcome to the C File Backup System\n", strlen("Welcome to the C File Backup System\n"), 0);

        // Add client socket to array
        client_socket[client_count] = new_socket;
    }

    return 0;
}