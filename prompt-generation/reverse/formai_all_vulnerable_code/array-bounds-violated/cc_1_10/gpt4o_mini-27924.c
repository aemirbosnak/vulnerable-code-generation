//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void handleClient(int client_socket);
void broadcastMessage(char *message, int sender_socket);

int client_sockets[MAX_CLIENTS];
int client_count = 0;

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    
    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server started on port %d. Waiting for clients...\n", PORT);
    
    while (1) {
        // Accept new clients
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Client accept failed");
            continue;
        }
        
        // Add to client sockets
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = client_socket;
            printf("Client connected: %d\n", client_socket);
        } else {
            printf("Max clients connected. Rejecting new client: %d\n", client_socket);
            close(client_socket);
        }

        // Handle the new client in a separate thread
        if (fork() == 0) {
            handleClient(client_socket);
            exit(0);
        }
    }
    
    close(server_socket);
    return 0;
}

void handleClient(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;
    
    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0';  // Null-terminate the received string
        printf("Received message from client %d: %s\n", client_socket, buffer);
        
        // Broadcast the message to all clients except the sender
        broadcastMessage(buffer, client_socket);
    }
    
    if (bytes_read == 0) {
        printf("Client %d disconnected\n", client_socket);
    } else {
        perror("Recv failed");
    }

    // Remove client socket
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == client_socket) {
            for (int j = i; j < client_count - 1; j++) {
                client_sockets[j] = client_sockets[j + 1];
            }
            client_count--;
            break;
        }
    }
    
    close(client_socket);
}

void broadcastMessage(char *message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}