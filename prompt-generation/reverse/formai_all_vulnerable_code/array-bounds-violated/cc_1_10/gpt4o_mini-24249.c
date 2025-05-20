//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

void *handle_client(void *client_socket);
void error_exit(const char *msg);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error_exit("Socket creation failed");
    }

    // Setup the server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_exit("Binding failed");
    }

    // Start listening for connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        error_exit("Listening failed");
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Accept a new client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        printf("New connection accepted\n");

        // Create a new thread to handle the client
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)(intptr_t)client_socket) != 0) {
            perror("Failed to create thread");
        } else {
            // Detach the thread so it can clean up after itself when done
            pthread_detach(tid);
        }
    }

    // Close the server socket (although this code will never be reached)
    close(server_socket);
    return 0;
}

void *handle_client(void *client_socket) {
    int sock = (int)(intptr_t)client_socket;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    // Clear the buffer
    memset(buffer, 0, sizeof(buffer));

    // Communicate with the client
    while ((bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        // Null terminate buffer to safely print
        buffer[bytes_received] = '\0';
        printf("Received: %s", buffer);

        // Echo the message back to the client
        send(sock, buffer, bytes_received, 0);

        // Clear the buffer for the next message
        memset(buffer, 0, sizeof(buffer));
    }

    if (bytes_received < 0) {
        perror("Receive failed");
    } else {
        printf("Client disconnected\n");
    }

    // Close the client socket
    close(sock);
    return NULL;
}

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}