//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CONNECTIONS 10

void *handle_client(void *arg);
void broadcast_message(const char *message, int sender_socket);
void remove_client(int socket);

int client_sockets[MAX_CONNECTIONS];
int client_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t addr_len = sizeof(client_address);

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        fprintf(stderr, "Failed to create socket. Exiting...\n");
        return EXIT_FAILURE;
    }
    printf("Socket created successfully!\n");

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Binding failed. Exiting...\n");
        close(server_socket);
        return EXIT_FAILURE;
    }
    printf("Binding successful on port %d!\n", PORT);

    // Start listening
    if (listen(server_socket, 3) < 0) {
        fprintf(stderr, "Listening failed. Exiting...\n");
        close(server_socket);
        return EXIT_FAILURE;
    }
    printf("Waiting for connections...\n");

    while (1) {
        new_socket = accept(server_socket, (struct sockaddr *)&client_address, &addr_len);
        if (new_socket < 0) {
            fprintf(stderr, "Failed to accept connection.\n");
            continue;
        }
        printf("New connection established!\n");

        pthread_mutex_lock(&mutex);
        client_sockets[client_count++] = new_socket;
        pthread_mutex_unlock(&mutex);

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)&new_socket) != 0) {
            fprintf(stderr, "Could not create thread.\n");
        }
    }

    close(server_socket);
    return 0;
}

void *handle_client(void *arg) {
    int socket = *(int *)arg;
    char message[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(socket, message, BUFFER_SIZE, 0)) > 0) {
        message[read_size] = '\0'; // Ensure null-termination
        printf("Received message: %s", message);
        broadcast_message(message, socket);
    }

    if (read_size == 0) {
        printf("Client disconnected.\n");
    } else {
        perror("recv failed");
    }

    remove_client(socket);
    close(socket);
    pthread_exit(NULL);
}

void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&mutex);
}

void remove_client(int socket) {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == socket) {
            for (int j = i; j < client_count - 1; j++) {
                client_sockets[j] = client_sockets[j + 1];
            }
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&mutex);
    printf("Client removed from the chat.\n");
}