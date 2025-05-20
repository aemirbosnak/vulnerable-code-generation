//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket[MAX_CLIENTS], max_socket;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    int opt = 1;
    int addrlen = sizeof(struct sockaddr_in);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set options on the socket
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Error setting socket options\n");
        exit(1);
    }

    // Bind the socket to an address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Accept a new connection
        if ((client_socket[max_socket] = accept(server_socket, (struct sockaddr *)&client_addr[max_socket], (socklen_t*)&addrlen)) < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr[max_socket].sin_addr), ntohs(client_addr[max_socket].sin_port));

        // Increment the maximum socket
        max_socket++;

        // If we've reached the maximum number of clients, start dropping connections
        if (max_socket == MAX_CLIENTS) {
            close(client_socket[0]);
            printf("Maximum number of clients reached. Dropping connection from %s:%d\n", inet_ntoa(client_addr[0].sin_addr), ntohs(client_addr[0].sin_port));
        }
    }

    return 0;
}