//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

void send_message(int socket) {
    char message[BUF_SIZE];
    
    printf("Enter message to send (type 'exit' to quit): ");
    while (fgets(message, sizeof(message), stdin)) {
        // Remove the newline character from the input
        message[strcspn(message, "\n")] = 0;

        if (strcmp(message, "exit") == 0) {
            break;
        }

        send(socket, message, strlen(message), 0);
        printf("Message sent: %s\n", message);
        printf("Enter message to send (type 'exit' to quit): ");
    }
}

void receive_message(int socket) {
    char buffer[BUF_SIZE];
    int n;

    while ((n = recv(socket, buffer, BUF_SIZE - 1, 0)) > 0) {
        buffer[n] = '\0'; // Null-terminate the received string
        printf("Message received: %s\n", buffer);

        // Send the same message back (echo)
        send(socket, buffer, n, 0);
    }
}

int main() {
    int sock;
    struct sockaddr_in server_addr;

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    printf("Socket created successfully.\n");

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sock);
        exit(EXIT_FAILURE);
    }
    printf("Bind successful.\n");

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("Listen failed");
        close(sock);
        exit(EXIT_FAILURE);
    }
    printf("Listening for connections...\n");

    while (1) {
        int new_socket;
        socklen_t addr_len = sizeof(server_addr);
        
        // Accept a connection
        if ((new_socket = accept(sock, (struct sockaddr *)&server_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }
        printf("Client connected. Socket fd: %d\n", new_socket);

        // Create a child process to handle communication with the client
        if (fork() == 0) {
            close(sock); // Close the original socket in the child process

            // Handle communication
            send_message(new_socket);
            receive_message(new_socket);

            printf("Client disconnected.\n");
            close(new_socket);
            exit(0);
        }
        close(new_socket); // Close the child's copy of the socket
    }

    // Close the main socket (not reachable in this example)
    close(sock);
    return 0;
}