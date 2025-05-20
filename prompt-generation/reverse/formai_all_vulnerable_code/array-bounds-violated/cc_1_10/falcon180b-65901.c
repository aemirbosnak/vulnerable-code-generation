//Falcon-180B DATASET v1.0 Category: Chat server ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], client_address_size;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    int opt = 1;
    int max_clients = 0;

    printf("Chat Server started on port %d\n", PORT);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket");
        exit(1);
    }

    // Set options on the socket
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Error setting socket options");
        exit(1);
    }

    // Bind the socket to an address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        printf("Error listening on socket");
        exit(1);
    }

    while (1) {
        // Accept a new connection
        client_address_size = sizeof(client_addr[max_clients]);
        if ((client_socket[max_clients] = accept(server_socket, (struct sockaddr *)&client_addr[max_clients], &client_address_size)) < 0) {
            printf("Error accepting connection");
            exit(1);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr[max_clients].sin_addr), ntohs(client_addr[max_clients].sin_port));

        // Add the new socket to the list of clients
        client_socket[max_clients] = accept(server_socket, (struct sockaddr *)&client_addr[max_clients], &client_address_size);
        max_clients++;
    }

    return 0;
}