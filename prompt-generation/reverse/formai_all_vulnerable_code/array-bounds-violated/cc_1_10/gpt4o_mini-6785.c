//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *handle_client(void *client_socket) {
    int new_socket = *(int *)client_socket;
    free(client_socket);
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(new_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0';  // Null-terminate the received data
        printf("Received: %s", buffer);
        send(new_socket, buffer, bytes_read, 0);  // Echo back the message
    }

    if (bytes_read < 0) {
        perror("recv failed");
    } else {
        printf("Client disconnected.\n");
    }

    close(new_socket);
    return NULL;
}

int main() {
    int server_socket, *new_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t addr_len = sizeof(client_address);
    pthread_t thread_id;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Configure server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        new_socket = malloc(sizeof(int));
        if (new_socket == NULL) {
            perror("Unable to allocate memory for new socket");
            continue;
        }
        *new_socket = accept(server_socket, (struct sockaddr *)&client_address, &addr_len);
        if (*new_socket < 0) {
            perror("Accept failed");
            free(new_socket);
            continue;
        }
        
        printf("New connection: socket fd is %d, ip is: %s, port: %d\n",
               *new_socket, inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // Create a new thread to handle the client
        if (pthread_create(&thread_id, NULL, handle_client, (void *)new_socket) != 0) {
            perror("Thread creation failed");
            close(*new_socket);
            free(new_socket);
        } else {
            pthread_detach(thread_id);  // Detach the thread to avoid memory leaks
        }
    }

    close(server_socket);
    return 0;
}