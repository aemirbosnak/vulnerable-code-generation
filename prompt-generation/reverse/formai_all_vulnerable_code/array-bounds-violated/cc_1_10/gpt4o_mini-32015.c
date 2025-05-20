//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: mathematical
#include <stdio.h>         // For standard input and output
#include <stdlib.h>       // For memory allocation and exit
#include <string.h>       // For string operations
#include <unistd.h>       // For standard symbolic constants and types
#include <arpa/inet.h>    // For internet operations
#include <pthread.h>      // For using threads

#define PORT 8080         // Define the port number
#define MAX_CLIENTS 10    // Maximum number of clients allowed
#define BUFFER_SIZE 256    // Size of the buffer for messages

// Global variables
int clients[MAX_CLIENTS];     // Array to hold client socket descriptors
pthread_mutex_t clients_mutex; // Mutex for client array

// Function to handle each client
void *handle_client(void *arg) {
    int sock = *(int *)arg;       // Obtain the client socket descriptor
    char buffer[BUFFER_SIZE];      // Buffer for incoming messages
    int bytes_read;

    while ((bytes_read = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null terminate the received message
        printf("Client %d: %s\n", sock, buffer); // Print the message

        // Broadcast the received message to all connected clients
        pthread_mutex_lock(&clients_mutex); // Lock the mutex
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] != 0 && clients[i] != sock) {
                send(clients[i], buffer, bytes_read, 0); // Send to other clients
            }
        }
        pthread_mutex_unlock(&clients_mutex); // Unlock the mutex
    }

    // Client disconnected
    close(sock);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == sock) {
            clients[i] = 0; // Remove client from the array
            break;
        }
    }
    return NULL;
}

// Main function
int main() {
    int server_sock, new_sock;
    struct sockaddr_in server_addr, client_addr; // Address structures
    socklen_t addr_size;
    
    // Initialize clients array and mutex
    memset(clients, 0, sizeof(clients));
    pthread_mutex_init(&clients_mutex, NULL);

    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the server address
    server_addr.sin_family = AF_INET;   // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Any incoming address
    server_addr.sin_port = htons(PORT);  // Port number

    // Bind the socket
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    // Accept clients in an infinite loop
    while (1) {
        addr_size = sizeof(client_addr);
        // Accept a new client
        if ((new_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_size)) < 0) {
            perror("Accept failed");
            continue; // Skip this iteration
        }

        // Find an empty slot for the new client
        pthread_mutex_lock(&clients_mutex); // Lock the mutex
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == 0) {
                clients[i] = new_sock; // Add the client to the array
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex); // Unlock the mutex

        // Create a new thread to handle the client
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)&new_sock) != 0) {
            perror("Failed to create thread");
        }
    }

    // Cleanup
    close(server_sock);
    pthread_mutex_destroy(&clients_mutex);
    return 0;
}