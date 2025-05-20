//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_QUOTES 5

const char *quotes[MAX_QUOTES] = {
    "Life is what happens when you're busy making other plans.",
    "Get busy living or get busy dying.",
    "The only impossible journey is the one you never begin.",
    "In the end, we only regret the chances we didn't take.",
    "Life is really simple, but we insist on making it complicated."
};

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Loop to handle multiple requests from the client
    while (1) {
        bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) {
            break; // Connection closed or error occurred
        }
        buffer[bytes_received] = '\0';

        if (strcmp(buffer, "GET_QUOTE") == 0) {
            // Randomly select a quote to send to the client
            int random_index = rand() % MAX_QUOTES;
            send(client_socket, quotes[random_index], strlen(quotes[random_index]), 0);
        } else if (strcmp(buffer, "EXIT") == 0) {
            break; // Client requested to exit
        } else {
            const char *error_message = "Unknown command.";
            send(client_socket, error_message, strlen(error_message), 0);
        }
    }

    close(client_socket);
    exit(0);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    server_addr.sin_port = htons(PORT); // Convert to network byte order

    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        // Accept a new client connection
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            close(server_socket);
            exit(EXIT_FAILURE);
        }

        // Create a new process to handle the client
        if (fork() == 0) {
            // Child process
            close(server_socket); // Close listening socket in the child
            handle_client(client_socket);
        }
        close(client_socket); // Parent process closes the connected socket
    }

    close(server_socket);
    return 0;
}