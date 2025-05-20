//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

void *client_handler(void *client_socket);
void broadcast_message(char *message, int sender_socket);

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t client_count_mutex;

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t thread_id;

    // Initialize mutex
    pthread_mutex_init(&client_count_mutex, NULL);

    // Creating socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listening for connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        // Accepting a new client
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        printf("New client connected: %d\n", client_socket);
        
        // Add client socket to the list
        pthread_mutex_lock(&client_count_mutex);
        client_sockets[client_count++] = client_socket;
        pthread_mutex_unlock(&client_count_mutex);
        
        // Create a thread for handling the client
        if (pthread_create(&thread_id, NULL, client_handler, (void *)&client_socket) != 0) {
            perror("Thread creation failed");
        }
    }

    // Cleanup
    close(server_socket);
    pthread_mutex_destroy(&client_count_mutex);
    return 0;
}

void *client_handler(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';  // Null-terminate the received data
        printf("Received from %d: %s", sock, buffer);
        broadcast_message(buffer, sock);
    }

    if (read_size == 0) {
        printf("Client %d disconnected\n", sock);
    } else {
        perror("Receive failed");
    }

    // Remove socket from the client list
    pthread_mutex_lock(&client_count_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == sock) {
            client_sockets[i] = client_sockets[--client_count];  // Replace with last socket
            break;
        }
    }
    pthread_mutex_unlock(&client_count_mutex);

    close(sock);
    return NULL;
}

void broadcast_message(char *message, int sender_socket) {
    pthread_mutex_lock(&client_count_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&client_count_mutex);
}