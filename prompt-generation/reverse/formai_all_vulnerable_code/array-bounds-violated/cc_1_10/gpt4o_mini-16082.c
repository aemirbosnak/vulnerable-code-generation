//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: shape shifting
// chat_server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void *client_handler(void *sockfd_ptr);

int main() {
    int server_fd, new_socket, client_socket[MAX_CLIENTS];
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pthread_t tid;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to the port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    // Accept clients
    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) >= 0) {
        printf("New client connected\n");
        pthread_create(&tid, NULL, client_handler, (void *)&new_socket);
    }

    if (new_socket < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void *client_handler(void *sockfd_ptr) {
    int sock = *(int*)sockfd_ptr;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the string

        // Process command to shift case
        if (strncmp(buffer, "SHIFT", 5) == 0) {
            for (int i = 5; i < read_size; i++) {
                if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                    buffer[i] -= 32; // Convert to uppercase
                } else if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                    buffer[i] += 32; // Convert to lowercase
                }
            }
            send(sock, buffer + 5, strlen(buffer) - 5, 0);
        } else {
            printf("Received: %s\n", buffer);
            send(sock, "Echo: ", 6, 0);
            send(sock, buffer, strlen(buffer), 0);
        }
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
    } else if (read_size == -1) {
        perror("recv failed");
    }

    close(sock);
    return NULL;
}