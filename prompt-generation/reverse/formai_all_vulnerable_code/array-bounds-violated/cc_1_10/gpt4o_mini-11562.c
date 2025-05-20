//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int read_size;

    // Receive a message from client
    read_size = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    
    if (read_size < 0) {
        perror("recv failed");
        close(client_socket);
        return;
    }
    
    buffer[read_size] = '\0'; // Null-terminate the received string

    printf("Client says: %s\n", buffer);

    // Graciously respond to the client
    const char *response = "Thank you for your message!";
    send(client_socket, response, strlen(response), 0);

    printf("Sent response to client: %s\n", response);
    
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }
    
    // Prepare server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Start listening for clients
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    printf("Grateful server is listening on port %d...\n", PORT);

    while (1) {
        // Accept a client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // continue waiting for new clients
        }

        printf("Client connected!\n");

        // Handle client in a gracious manner
        handle_client(client_socket);
    }

    // Cleanup
    close(server_socket);
    return EXIT_SUCCESS;
}

// Client Code (To be run separately)
void run_client(const char *server_ip) {
    int client_socket;
    struct sockaddr_in server_addr;
    const char *message = "Hello, gracious server!";

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    // Prepare the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(client_socket);
        return;
    }

    // Send message to server
    send(client_socket, message, strlen(message), 0);
    printf("Sent to server: %s\n", message);

    // Receive response from server
    char buffer[BUFFER_SIZE];
    int read_size;
    read_size = recv(client_socket, buffer, sizeof(buffer) - 1, 0);

    if (read_size > 0) {
        buffer[read_size] = '\0'; // Null-terminate the received string
        printf("Server says: %s\n", buffer);
    }

    // Cleanup
    close(client_socket);
}

// To compile the server: gcc -o server server.c
// To run the server: ./server
// To compile the client: gcc -o client client.c
// To run the client: ./client <server_ip>