//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

void *handle_client(void *client_socket);
void broadcast_message(char *message, int sender_socket);
int client_sockets[MAX_CLIENTS];

pthread_mutex_t client_list_lock;

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int opt = 1;

    // Initialize the client_sockets array
    memset(client_sockets, 0, sizeof(client_sockets));

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Unable to create socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Prepare server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    // Initialize mutex
    pthread_mutex_init(&client_list_lock, NULL);

    while (1) {
        // Accept a client
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        printf("Client connected: %d\n", client_socket);

        // Create a new thread for the client
        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, handle_client, (void *)(long)client_socket) != 0) {
            perror("Failed to create thread");
            close(client_socket);
        }
        pthread_detach(client_thread); // Automatically reclaim the thread resources when it exits
    }

    close(server_socket);
    pthread_mutex_destroy(&client_list_lock);
    return 0;
}

void *handle_client(void *client_socket) {
    int sock = (int)(long)client_socket;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(sock, buffer, sizeof(buffer)-1, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Received from %d: %s\n", sock, buffer);
        
        // Broadcast the message to all clients
        broadcast_message(buffer, sock);
    }

    if (bytes_read == 0) {
        printf("Client %d disconnected\n", sock);
    } else {
        perror("recv failed");
    }

    close(sock);
    return NULL;
}

void broadcast_message(char *message, int sender_socket) {
    pthread_mutex_lock(&client_list_lock);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] > 0 && client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&client_list_lock);
}