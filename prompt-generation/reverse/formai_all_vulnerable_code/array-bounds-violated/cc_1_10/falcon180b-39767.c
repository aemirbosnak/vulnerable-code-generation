//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    int addr_size, i, client_count = 0;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(3000);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind server address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen on socket
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server started on port 3000\n");

    while (1) {
        // Accept client connections
        addr_size = sizeof(client_addr[0]);
        client_socket[client_count] = accept(server_socket, (struct sockaddr *)&client_addr[client_count], &addr_size);
        if (client_socket[client_count] == -1) {
            printf("Error accepting client connection\n");
            exit(1);
        }

        // Send welcome message to client
        send(client_socket[client_count], "Welcome to the server!\n", strlen("Welcome to the server!\n"), 0);

        // Increment client count
        client_count++;
    }

    return 0;
}