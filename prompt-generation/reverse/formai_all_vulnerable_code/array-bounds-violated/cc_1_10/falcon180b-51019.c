//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int server_socket, new_socket, client_socket[MAX_CLIENTS], max_socket, addrlen;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    int opt = 1;
    int i = 0;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set options on the socket
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        exit(2);
    }

    // Initialize server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind the socket to an address and port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(3);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        printf("Error listening on socket\n");
        exit(4);
    }

    printf("Server is listening on port 8080\n");

    while (1) {
        // Accept a new connection
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr[i], (socklen_t*)&addrlen)) < 0) {
            printf("Error accepting connection\n");
            exit(5);
        }

        // Add the new socket to the list of clients
        client_socket[i] = new_socket;
        i++;

        // Send welcome message to client
        send(new_socket, "Welcome to the server!\n", strlen("Welcome to the server!\n"), 0);
    }

    return 0;
}