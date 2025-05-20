//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void *handle_client(void *arg);
void send_message_to_all_clients(char *message);

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t client_mutex;

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Initialize mutex
    pthread_mutex_init(&client_mutex, NULL);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set up address struct
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listening for clients
    if (listen(server_fd, 3) < 0) {
        perror("Listening error");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server started. Waiting for clients...\n");

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accepting failed");
            continue;
        }

        pthread_mutex_lock(&client_mutex);
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = new_socket;
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void*)&new_socket);
            printf("Client connected. Total clients: %d\n", client_count);
            pthread_detach(thread_id);
        } else {
            printf("Max clients reached. Denying connection.\n");
            close(new_socket);
        }
        pthread_mutex_unlock(&client_mutex);
    }

    close(server_fd);
    return 0;
}

void *handle_client(void *arg) {
    int socket = *((int*)arg);
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // null-terminate received message
        printf("Received message: %s\n", buffer);
        send_message_to_all_clients(buffer);
    }

    // Remove client from the array and free the socket
    pthread_mutex_lock(&client_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == socket) {
            client_sockets[i] = client_sockets[--client_count];
            break;
        }
    }
    pthread_mutex_unlock(&client_mutex);
    close(socket);
    printf("Client disconnected. Total clients: %d\n", client_count);
    return NULL;
}

void send_message_to_all_clients(char *message) {
    pthread_mutex_lock(&client_mutex);
    for (int i = 0; i < client_count; i++) {
        if (send(client_sockets[i], message, strlen(message), 0) < 0) {
            perror("Send failed");
        }
    }
    pthread_mutex_unlock(&client_mutex);
}