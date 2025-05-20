//Falcon-180B DATASET v1.0 Category: Networking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 10

// Function to print error message and exit
void error(char *msg) {
    perror(msg);
    exit(1);
}

// Function to handle client requests
void handle_client(int client_socket) {
    char buffer[1024];
    int bytes_received;

    // Receive data from client
    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        // Process data
        buffer[bytes_received] = '\0';
        printf("Received data: %s\n", buffer);

        // Send response to client
        send(client_socket, "Response", strlen("Response"), 0);
    }

    // Close client socket
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_size;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("socket() failed");
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("bind() failed");
    }

    // Listen for client connections
    if (listen(server_socket, BACKLOG) < 0) {
        error("listen() failed");
    }

    printf("Server listening on port %d\n", PORT);

    // Accept client connections
    while (1) {
        // Accept connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_size)) < 0) {
            error("accept() failed");
        }

        // Handle client request
        handle_client(client_socket);
    }

    return 0;
}