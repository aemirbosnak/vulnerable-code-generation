//FormAI DATASET v1.0 Category: Client Server Application ; Style: detailed
// This is a simple C client-server program that implements a chat between a client and a server.
// The server listens for incoming connections, accepts them, and forwards any messages it receives to all connected clients.
// The clients connect to the server, send messages to it, and receive messages from it.
// Communication is done over TCP/IP using the sockets API.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define BUF_SIZE 1024

// Function prototypes
void *handle_client(void *sock_desc);

// Global variables
int client_socks[10]; // Array to hold client socket descriptors
int num_clients = 0;  // Number of connected clients

int main(int argc, char *argv[]) {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    pthread_t client_thread;
    
    // Create server socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }
    
    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(5000);
    
    // Bind server to address
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding server socket to address");
        exit(EXIT_FAILURE);
    }
    
    // Start listening for incoming connections
    if (listen(server_sock, 10) < 0) {
        perror("Error listening for incoming connections");
        exit(EXIT_FAILURE);
    }
    
    printf("Server started...\n");
    
    while (1) {
        // Accept incoming connection
        socklen_t client_addr_len = sizeof(client_addr);
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
            perror("Error accepting client connection");
            continue;
        }
        
        // Add client socket to array
        client_socks[num_clients++] = client_sock;
        
        // Create a thread to handle the client
        if (pthread_create(&client_thread, NULL, handle_client, (void *)&client_sock) != 0) {
            perror("Error creating client thread");
            exit(EXIT_FAILURE);
        }
    }
    
    return 0;
}

// Thread function to handle a client
void *handle_client(void *sock_desc) {
    int client_sock = *(int *)sock_desc;
    char buffer[BUF_SIZE];
    ssize_t nBytes;

    // Loop to receive incoming messages from client and broadcast to all other clients
    while ((nBytes = recv(client_sock, buffer, BUF_SIZE, 0)) > 0) {
        buffer[nBytes] = '\0';

        // Broadcast message to all other clients
        for (int i = 0; i < num_clients; i++) {
            if (client_socks[i] != client_sock) {
                if (send(client_socks[i], buffer, strlen(buffer), 0) != strlen(buffer)) {
                    perror("Error sending message to client");
                }
            }
        }
    }

    // Remove client socket from array
    for (int i = 0; i < num_clients; i++) {
        if (client_socks[i] == client_sock) {
            memmove(client_socks + i, client_socks + i + 1, (num_clients - i - 1) * sizeof(int));
            num_clients--;
            break;
        }
    }

    // Close client socket
    close(client_sock);
    
    return NULL;
}