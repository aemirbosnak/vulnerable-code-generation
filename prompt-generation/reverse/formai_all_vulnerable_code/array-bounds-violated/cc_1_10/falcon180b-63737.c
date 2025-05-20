//Falcon-180B DATASET v1.0 Category: Chat server ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_LENGTH 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char message[MAX_MESSAGE_LENGTH];
    int client_count = 0;

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind server address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    // Listen for clients
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening\n");
        return 1;
    }

    while (1) {
        printf("Waiting for clients...\n");

        // Accept client connections
        int client_size = sizeof(client_addr[0]);
        client_socket[client_count] = accept(server_socket, (struct sockaddr *)&client_addr[client_count], &client_size);

        if (client_socket[client_count] == -1) {
            printf("Error accepting client\n");
            return 1;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr[client_count].sin_addr), ntohs(client_addr[client_count].sin_port));

        client_count++;
    }

    return 0;
}