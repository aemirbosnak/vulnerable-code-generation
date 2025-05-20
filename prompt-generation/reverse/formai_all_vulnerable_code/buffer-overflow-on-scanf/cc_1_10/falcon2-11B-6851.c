//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Global variables
int port = 8080;
int backlog = 5;
int num_clients = 0;
char buffer[256];
int server_socket;
char *ip_address = "127.0.0.1";

// Function declarations
void handle_client(int client_socket);

// Main function
int main(int argc, char *argv[]) {
    // Initialize socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(1);
    }
    
    // Set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &(char[]){1}, sizeof(char)) == -1) {
        perror("Setsockopt failed");
        exit(1);
    }
    
    // Bind socket to IP address and port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(ip_address);
    
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Bind failed");
        exit(1);
    }
    
    // Listen for incoming connections
    if (listen(server_socket, backlog) == -1) {
        perror("Listen failed");
        exit(1);
    }
    
    printf("Server listening on port %d...\n", port);
    
    while (1) {
        // Accept new client connection
        struct sockaddr_in client_address;
        socklen_t client_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_len);
        
        if (client_socket == -1) {
            perror("Accept failed");
            exit(1);
        }
        
        printf("New client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // Create a thread to handle the client
        pthread_t client_thread;
        pthread_create(&client_thread, NULL, handle_client, (void *)client_socket);
        
        // Increment number of clients
        num_clients++;
    }
    
    return 0;
}

// Client handler function
void handle_client(int client_socket) {
    char client_name[256];
    char *endptr;
    
    printf("Enter your name: ");
    scanf("%s", client_name);
    
    // Send name to client
    send(client_socket, client_name, strlen(client_name), 0);
    
    // Receive messages from client
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        
        // Receive message from client
        if (recv(client_socket, buffer, sizeof(buffer), 0) <= 0) {
            perror("Receive failed");
            exit(1);
        }
        
        printf("Received message from %s: %s\n", client_name, buffer);
        
        // Send message to other clients
        for (int i = 0; i < num_clients; i++) {
            if (i!= client_socket) {
                memset(buffer, 0, sizeof(buffer));
                
                snprintf(buffer, sizeof(buffer), "From %s: %s", client_name, buffer);
                
                send(i, buffer, strlen(buffer), 0);
            }
        }
    }
}