//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

int client_sockets[MAX_CLIENTS];
int client_count = 0;

// Function to send message to all clients
void broadcast_message(char *message, int sender_socket) {
    for(int i = 0; i < client_count; i++) {
        if(client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}

// Function to handle client communication
void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE + 50];
    
    while(1) {
        int recv_size = recv(client_socket, buffer, sizeof(buffer), 0);
        if(recv_size <= 0) {
            break; // Connection closed or error
        }
        
        buffer[recv_size] = '\0'; // Null-terminate the received message
        
        snprintf(message, sizeof(message), "Client %d: %s", client_socket, buffer);
        printf("%s", message);
        
        // Broadcast message to other clients
        broadcast_message(message, client_socket);
    }
    
    // Handle client disconnection
    close(client_socket);
    return NULL;
}

// Main function for the server
int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Initialize the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Set server address structure
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    printf("Chat server started on port %d...\n", PORT);
    
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }
        
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = client_socket;
            printf("New client connected: %d\n", client_socket);
            
            pthread_t tid;
            if (pthread_create(&tid, NULL, handle_client, (void *)&client_socket) != 0) {
                perror("Thread creation failed");
                close(client_socket);
                client_count--;
            }
        } else {
            printf("Max client limit reached. Connection refused: %d\n", client_socket);
            close(client_socket);
        }
    }
    
    // Clean up
    close(server_socket);
    return 0;
}