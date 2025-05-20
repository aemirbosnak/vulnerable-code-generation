//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 10
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int server_socket;
    int client_socket[MAX_CLIENTS];
    int opt = 1;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr[MAX_CLIENTS];
    int addrlen;
    int client_count;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options on the socket
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Fill in server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen on the socket
    if (listen(server_socket, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Accept a new connection
        addrlen = sizeof(client_addr[0]);
        if ((client_socket[client_count] = accept(server_socket, (struct sockaddr *)&client_addr[client_count], &addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_addr[client_count].sin_addr), ntohs(client_addr[client_count].sin_port));

        // Add the new socket to the list of clients
        client_count++;
    }

    // Close the socket
    close(server_socket);

    return 0;
}