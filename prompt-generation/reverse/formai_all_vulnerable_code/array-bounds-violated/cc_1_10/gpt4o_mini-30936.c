//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 5

void *client_handler(void *client_socket);
void handle_error(const char *msg);

int main() {
    int server_fd, client_socket, opt = 1;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    
    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        handle_error("Socket creation failed");
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        handle_error("setsockopt");
    }

    // Define the address of the server
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        handle_error("Bind failed");
    }

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        handle_error("Listen failed");
    }
    
    printf("Server listening on port %d\n", PORT);

    while (1) {
        // Accept an incoming connection
        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) < 0) {
            handle_error("Accept failed");
        }

        printf("New connection established on socket %d\n", client_socket);
        
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, client_handler, (void *)&client_socket) != 0) {
            handle_error("Thread creation failed");
        }
        pthread_detach(thread_id);  // Detach the thread to handle cleanup automatically
    }

    close(server_fd);
    return 0;
}

void *client_handler(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Communicate with the client
    while ((bytes_read = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_read] = '\0';  // Null-terminate the string
        printf("Received from client: %s", buffer);
        
        // Echo back the message to the client
        send(sock, buffer, bytes_read, 0);
    }

    if (bytes_read == 0) {
        printf("Client disconnected\n");
    } else {
        handle_error("Receive failed");
    }

    close(sock);
    return NULL;
}

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}