//Code Llama-13B DATASET v1.0 Category: Chat server ; Style: Claude Shannon
/*
 * C Chat Server
 *
 * This program implements a chat server using a Claude Shannon style.
 * It allows multiple clients to connect and exchange messages.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 100
#define MAX_BUFFER_SIZE 1024

// Structure to store client information
typedef struct {
    int socket_fd;
    struct sockaddr_in address;
} client_t;

// Global variables
int server_fd;
client_t clients[MAX_CLIENTS];
int num_clients = 0;

// Function to initialize the server
void init_server(int port) {
    // Create the server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Set the address and port for the server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    // Bind the server socket to the address and port
    bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address));

    // Listen for incoming connections
    listen(server_fd, MAX_CLIENTS);
}

// Function to add a client to the list
void add_client(int client_fd, struct sockaddr_in client_address) {
    // Check if the client list is full
    if (num_clients >= MAX_CLIENTS) {
        printf("Client list is full\n");
        return;
    }

    // Add the client to the list
    clients[num_clients].socket_fd = client_fd;
    clients[num_clients].address = client_address;
    num_clients++;
}

// Function to handle a client connection
void handle_client(int client_fd) {
    // Receive the client's message
    char buffer[MAX_BUFFER_SIZE];
    recv(client_fd, buffer, MAX_BUFFER_SIZE, 0);

    // Print the client's message
    printf("Received message from client: %s\n", buffer);

    // Send the message to all other clients
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].socket_fd != client_fd) {
            send(clients[i].socket_fd, buffer, strlen(buffer), 0);
        }
    }
}

int main(int argc, char *argv[]) {
    // Initialize the server
    init_server(atoi(argv[1]));

    // Main loop
    while (1) {
        // Accept an incoming connection
        struct sockaddr_in client_address;
        int client_fd = accept(server_fd, (struct sockaddr *)&client_address, sizeof(client_address));

        // Add the client to the list
        add_client(client_fd, client_address);

        // Handle the client connection
        handle_client(client_fd);
    }

    // Close the server socket
    close(server_fd);

    return 0;
}