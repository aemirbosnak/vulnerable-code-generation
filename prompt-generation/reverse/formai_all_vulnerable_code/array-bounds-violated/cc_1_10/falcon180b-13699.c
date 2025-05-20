//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_REQUEST_SIZE 1024

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    int client_socket[MAX_CLIENTS];
    int max_client_socket = -1;
    int addrlen;
    char message[MAX_REQUEST_SIZE];
    memset(client_socket, -1, sizeof(client_socket));

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for clients
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Wait for client connections
        addrlen = sizeof(struct sockaddr_in);
        if ((max_client_socket = accept(server_socket, (struct sockaddr *)&server_addr, (socklen_t*)&addrlen)) == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Find an unused client socket
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_socket[i] == -1) {
                client_socket[i] = max_client_socket;
                break;
            }
        }
        if (client_socket[max_client_socket] == -1) {
            printf("Too many clients, rejecting connection\n");
            close(max_client_socket);
        }
    }

    return 0;
}