//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CONNECTIONS 100
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Gratefully acknowledging the client
    send(client_socket, "Welcome to the Grateful Firewall!\n", 37, 0);
    printf("Client connected!\n");

    // Loop to read messages from client
    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer)-1, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        printf("Received: %s", buffer);

        // Simple logic to demonstrate filtering
        if (strstr(buffer, "BLOCK_THIS") != NULL) {
            printf("Blocked a message containing blocked phrase!\n");
            send(client_socket, "Your message was blocked.\n", 27, 0);
        } else {
            // Echo back the message
            send(client_socket, buffer, bytes_read, 0);
        }
    }

    // Close the socket after handling the client
    printf("Client disconnected.\n");
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    
    // Creating the server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket");
        return EXIT_FAILURE;
    }
    printf("Socket created successfully!\n");

    // Prepare the sockaddr_in structure with server details
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        return EXIT_FAILURE;
    }
    printf("Bind successful to port %d!\n", PORT);

    // Listening for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("Listen failed");
        close(server_socket);
        return EXIT_FAILURE;
    }
    printf("Listening for incoming connections...\n");

    // Accepting clients in a loop
    while (1) {
        printf("Waiting for a client to connect...\n");
        
        // Accept a client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Failed to accept client");
            continue;
        }

        // Handle the client in a separate function
        handle_client(client_socket);
    }

    // Close the server socket (unreachable code in this setup)
    close(server_socket);
    return EXIT_SUCCESS;
}