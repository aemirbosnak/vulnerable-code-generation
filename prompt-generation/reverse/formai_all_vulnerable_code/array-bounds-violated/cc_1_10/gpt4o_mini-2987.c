//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int client_sockets[MAX_CLIENTS];
pthread_mutex_t client_sockets_mutex;

void *client_handler(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';  // Null-terminate the received data
        printf("Received: %s\n", buffer);

        // Broadcast the message to all connected clients
        pthread_mutex_lock(&client_sockets_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] != 0 && client_sockets[i] != sock) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
        pthread_mutex_unlock(&client_sockets_mutex);
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
    } else {
        perror("recv failed");
    }

    close(sock);
    return 0;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t thread_id;

    // Initialize client socket array to zero
    memset(client_sockets, 0, sizeof(client_sockets));
    pthread_mutex_init(&client_sockets_mutex, NULL);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d. Waiting for connections...\n", PORT);

    while ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len))) {
        printf("New client connected\n");

        // Store client socket in the array
        pthread_mutex_lock(&client_sockets_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = new_socket;
                break;
            }
        }
        pthread_mutex_unlock(&client_sockets_mutex);

        // Create a new thread for the client
        if (pthread_create(&thread_id, NULL, client_handler, (void *)&new_socket) < 0) {
            perror("Could not create thread");
            return 1;
        }
    }

    // Close the server socket
    if (new_socket < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    close(server_fd);
    pthread_mutex_destroy(&client_sockets_mutex);
    return 0;
}