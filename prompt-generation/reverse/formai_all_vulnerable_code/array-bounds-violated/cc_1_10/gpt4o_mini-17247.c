//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 100

int clients[MAX_CLIENTS];
int client_count = 0;

void* handle_client(void* client_socket) {
    int sock = *(int*)client_socket;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_read = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (bytes_read <= 0) {
            printf("Connection closed or error occurred.\n");
            break;
        }

        buffer[bytes_read] = '\0'; // Ensure null-termination

        // Paranoia: Check for unwanted content
        if (strstr(buffer, "exit") != NULL) {
            printf("Exiting due to command from client.\n");
            break;
        }

        printf("Received from client: %s", buffer);
        
        // Echo back to client
        if (send(sock, buffer, bytes_read, 0) <= 0) {
            perror("Send failed");
            break;
        }
    }

    close(sock);
    return NULL;
}

void add_client(int sock) {
    if (client_count >= MAX_CLIENTS) {
        fprintf(stderr, "Maximum client limit reached\n");
        return;
    }
    clients[client_count++] = sock;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options to allow reuse of the address
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Forcefully attach socket to the port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);
    
    while (1) {
        // Accept a new client connection
        if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            continue; // Avoid exiting the server on failure
        }
        
        printf("New client connected\n");

        // Add client to the list
        add_client(new_socket);
        
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void*)&new_socket) != 0) {
            perror("Thread creation failed");
            close(new_socket);
        }
    }

    // Clean up on exit (never reached in this example)
    close(server_fd);
    return 0;
}