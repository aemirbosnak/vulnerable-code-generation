//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

void* process_message(void* client_socket);

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket option failed");
        exit(EXIT_FAILURE);
    }

    // Defining the server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("🛰️ Server is online and awaiting connections on port %d...\n", PORT);

    while (1) {
        // Accepting a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Connection acceptance failed");
            exit(EXIT_FAILURE);
        }

        printf("👤 A new client has connected!\n");
        
        // Creating a new thread to handle the client
        pthread_t tid;
        if (pthread_create(&tid, NULL, process_message, (void*)&new_socket) != 0) {
            perror("Failed to create thread");
            close(new_socket);
            continue;
        }
        
        // Detaching the thread to allow it to clean up after itself
        pthread_detach(tid);
    }

    return 0;
}

void* process_message(void* client_socket) {
    int sock = *(int*)client_socket;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Setting up a futuristic response
    char* response_prefix = "💾 AI RESPONSE: ";
    
    while ((bytes_read = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the received string

        // Transforming message into a futuristic greeting
        char transformed_message[BUFFER_SIZE];
        snprintf(transformed_message, sizeof(transformed_message), "%sWelcome to the future! You said: %s", response_prefix, buffer);
        
        printf("📩 Received from client: %s\n", buffer);
        
        // Sending back the transformed message
        send(sock, transformed_message, strlen(transformed_message), 0);
    }

    printf("🔌 Client disconnected.\n");
    close(sock);
    return NULL;
}