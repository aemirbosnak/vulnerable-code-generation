//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 5

// Function to handle client communication
void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the received string
        printf("Client: %s", buffer);
        // Echo the message back to the client
        send(client_socket, buffer, bytes_read, 0);
    }
    
    // Close the socket and exit the thread
    close(client_socket);
    printf("Client disconnected.\n");
    return NULL;
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    pthread_t client_thread[MAX_CLIENTS];
    int thread_count = 0;

    // Create the server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        // Accept a new client connection
        if ((client_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
            perror("Accept failed");
            continue; // Try accepting the next connection
        }

        printf("New client connected.\n");

        // Create a separate thread to handle the client
        if (pthread_create(&client_thread[thread_count++], NULL, handle_client, (void *)&client_socket) != 0) {
            perror("Thread creation failed");
            close(client_socket);
        }

        // Limit the number of concurrent threads
        if (thread_count >= MAX_CLIENTS) {
            for (int i = 0; i < MAX_CLIENTS; ++i) {
                pthread_join(client_thread[i], NULL);
            }
            thread_count = 0; // Reset thread count after joining
        }
    }

    // Close the server socket and clean up
    close(server_fd);
    return 0;
}