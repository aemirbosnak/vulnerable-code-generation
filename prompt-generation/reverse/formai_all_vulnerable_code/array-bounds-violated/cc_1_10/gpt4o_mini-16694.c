//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Function to handle communication with a connected client
void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    int read_size;

    // Send a welcome message to the client
    const char *welcome_msg = "Welcome to the chat server!\n";
    write(client_sock, welcome_msg, strlen(welcome_msg));

    // Continuously communicate with the client
    while ((read_size = recv(client_sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the received string
        printf("Client: %s", buffer); // Print client's message

        // Echo the message back to the client
        write(client_sock, buffer, read_size);
    }

    if (read_size == 0) {
        printf("Client disconnected.\n");
    } else if (read_size == -1) {
        perror("recv failed");
    }

    close(client_sock);
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Set the server to listening mode
    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d. Waiting for connections...\n", PORT);

    // Accept and handle multiple clients
    while (1) {
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        printf("New client connected: %s\n", inet_ntoa(client_addr.sin_addr));

        // Create a new process to handle the client
        if (fork() == 0) {
            // Child process
            close(server_sock); // Close the listening socket in the child
            handle_client(client_sock);
            exit(0);
        } else {
            // Parent process
            close(client_sock); // Parent closes the connected socket
        }
    }

    // Clean up (this code will never be reached in normal execution)
    close(server_sock);
    return 0;
}