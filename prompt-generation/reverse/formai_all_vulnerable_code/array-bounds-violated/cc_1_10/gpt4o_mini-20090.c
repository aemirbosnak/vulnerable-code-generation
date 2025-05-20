//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8888
#define MAX_CLIENTS 10
#define MESSAGE_SIZE 256

static int client_sockets[MAX_CLIENTS];
static int client_count = 0;
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char message[MESSAGE_SIZE];

    while (1) {
        int bytes_received = recv(sock, message, MESSAGE_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Client disconnected.\n");
            break;
        }

        message[bytes_received] = '\0';
        printf("Message received: %s\n", message);

        pthread_mutex_lock(&count_mutex);
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != sock) {
                send(client_sockets[i], message, bytes_received, 0);
            }
        }
        pthread_mutex_unlock(&count_mutex);
    }

    close(sock);
    pthread_mutex_lock(&count_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == sock) {
            client_sockets[i] = client_sockets[--client_count]; // Remove current socket
            break;
        }
    }
    pthread_mutex_unlock(&count_mutex);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        // Accept a new client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        printf("New client connected: %d\n", client_socket);

        pthread_mutex_lock(&count_mutex);
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = client_socket;
            pthread_mutex_unlock(&count_mutex);
            pthread_t thread;
            pthread_create(&thread, NULL, handle_client, (void *)&client_socket);
            pthread_detach(thread);  // Automatically clean up the thread resources
        } else {
            pthread_mutex_unlock(&count_mutex);
            printf("Max clients reached. Connection refused: %d\n", client_socket);
            close(client_socket);
        }
    }

    // Close server socket
    close(server_socket);
    return 0;
}