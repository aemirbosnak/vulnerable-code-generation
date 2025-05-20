//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    int opt = 1;
    char buffer[BUFFER_SIZE];
    int buffer_len;
    int client_count = 0;

    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set options on server socket
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        exit(1);
    }

    // Bind server socket to localhost:8080
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen on server socket
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port 8080\n");

    while (1) {
        // Accept connection from client
        if ((client_socket[client_count] = accept(server_socket, (struct sockaddr *)&client_addr[client_count], sizeof(client_addr[client_count]))) == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr[client_count].sin_addr), ntohs(client_addr[client_count].sin_port));
        client_count++;

        // Send welcome message to client
        if (send(client_socket[client_count], "Welcome to the server!\n", strlen("Welcome to the server!\n"), 0) == -1) {
            printf("Error sending data to client\n");
            exit(1);
        }
    }

    return 0;
}