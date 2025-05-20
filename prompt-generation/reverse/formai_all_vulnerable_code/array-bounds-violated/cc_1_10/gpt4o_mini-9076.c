//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    ssize_t msg_len;
    
    while (1) {
        memset(buffer, 0, sizeof(buffer)); // Clear the buffer
        msg_len = recv(sock, buffer, sizeof(buffer) - 1, 0);
        
        // Error handling for recv
        if (msg_len <= 0) {
            if (msg_len == 0) { 
                perror("Client disconnected unexpectedly.");
            } else {
                perror("recv failed");
            }
            break;
        }
        
        buffer[msg_len] = '\0'; // Null terminate the received string
        printf("Received message: %s", buffer);

        pthread_mutex_lock(&client_mutex);
        // Loop to send the message to all client sockets
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] != 0) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
        pthread_mutex_unlock(&client_mutex);
    }

    // Clean up the socket
    close(sock);
    pthread_mutex_lock(&client_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == sock) {
            client_sockets[i] = 0;
            break;
        }
    }
    pthread_mutex_unlock(&client_mutex);
    return NULL;
}

int main() {
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);

    // Initialize client sockets
    memset(client_sockets, 0, sizeof(client_sockets));

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Configure address structure
    address.sin_family = AF_INET; // IPv4
    address.sin_addr.s_addr = INADDR_ANY; // Accept connections from any address
    address.sin_port = htons(PORT); // Port number

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d...\n", PORT);

    while (1) {
        int new_socket;
        
        // Accept new connections
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) < 0) {
            perror("Accept failed");
            continue; // Ignore the error and continue waiting for connections
        }

        // Assign new socket to the clients array
        pthread_mutex_lock(&client_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = new_socket;
                printf("New client connected on socket %d\n", new_socket);
                pthread_t thread_id;
                pthread_create(&thread_id, NULL, handle_client, (void *)&new_socket);
                pthread_detach(thread_id); // Detach the thread
                break;
            }
        }
        pthread_mutex_unlock(&client_mutex);
    }

    close(server_fd);
    return 0;
}