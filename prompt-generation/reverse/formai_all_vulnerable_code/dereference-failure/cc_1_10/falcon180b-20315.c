//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Function to handle client connections
void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Client %d sent: %s\n", client_socket, buffer);
        send(client_socket, buffer, strlen(buffer), 0);
    }
    close(client_socket);
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Socket creation failed: %s\n", strerror(errno));
        return 1;
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Bind failed: %s\n", strerror(errno));
        return 1;
    }

    // Listen for connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        printf("Listen failed: %s\n", strerror(errno));
        return 1;
    }

    while (1) {
        int client_socket;
        socklen_t client_size;

        // Accept connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&server_addr, &client_size)) < 0) {
            printf("Accept failed: %s\n", strerror(errno));
            return 1;
        }

        // Handle client connection
        printf("Client %d connected\n", client_socket);
        handle_client(client_socket);
    }

    close(server_socket);
    return 0;
}