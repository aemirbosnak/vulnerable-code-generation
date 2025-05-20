//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_count = 0;
pthread_mutex_t count_mutex;

void *client_handler(void *client_socket) {
    int sock = *(int*)client_socket;
    char buffer[BUFFER_SIZE];
    int n;

    // Infinite loop to receive messages from the client
    while ((n = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0'; // Null-terminate the received string
        printf("Client says: %s\n", buffer);
        
        // Echo the message back to the client
        send(sock, buffer, n, 0);
    }

    // Close the socket and decrement client count
    pthread_mutex_lock(&count_mutex);
    client_count--;
    pthread_mutex_unlock(&count_mutex);
    close(sock);
    return NULL;
}

int main() {
    int server_fd, client_sock, addr_len;
    struct sockaddr_in address;
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Set server address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server started. Waiting for clients...\n");
    pthread_mutex_init(&count_mutex, NULL);
    
    while (1) {
        // Accept incoming client connection
        addr_len = sizeof(address);
        if ((client_sock = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addr_len))<0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        pthread_mutex_lock(&count_mutex);
        if (client_count < MAX_CLIENTS) {
            client_count++;
            printf("Client connected. Total clients: %d\n", client_count);
            pthread_t client_thread;
            // Create a new thread to handle the client
            if (pthread_create(&client_thread, NULL, client_handler, (void*)&client_sock) != 0) {
                perror("Thread creation failed");
                exit(EXIT_FAILURE);
            }
            pthread_detach(client_thread); // Detach the thread to allow it to run independently
        } else {
            printf("Max clients reached. Closing connection.\n");
            close(client_sock);
        }
        pthread_mutex_unlock(&count_mutex);
    }
    
    // Cleanup
    close(server_fd);
    pthread_mutex_destroy(&count_mutex);
    return 0;
}