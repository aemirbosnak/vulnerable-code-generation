//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_connection(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Welcome message to the client
    const char *welcome_message = "Greetings from Server! Send a message to receive a response.";
    send(client_socket, welcome_message, strlen(welcome_message), 0);

    // Receive the message from the client
    bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        perror("Failed to receive data");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    buffer[bytes_received] = '\0'; // Null-terminate the received string
    printf("Client: %s\n", buffer);

    // Respond back to client
    const char *response_message = "Message received. Good day!";
    send(client_socket, response_message, strlen(response_message), 0);
    
    // Close the connection
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_length = sizeof(client_addr);

    // Create the socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the PORT
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    // Accept and handle incoming connection
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_length))) {
        printf("Connection established with client.\n");
        handle_connection(client_socket);
    }

    if (client_socket < 0) {
        perror("Accept failed");
    }

    // Close the server socket
    close(server_socket);
    return 0;
}