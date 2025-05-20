//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void *handle_client(void *arg);
void broadcast_message(const char *message, int sender_socket);
void remove_client(int socket);

int client_sockets[MAX_CLIENTS];
int client_count = 0;

pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);
    
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Client accept failed");
            continue;
        }

        printf("New client connected: socket %d\n", client_socket);

        pthread_mutex_lock(&clients_mutex);
        client_sockets[client_count++] = client_socket;
        pthread_mutex_unlock(&clients_mutex);

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)(intptr_t)client_socket) != 0) {
            perror("Thread creation failed");
            close(client_socket);
        }
    }

    close(server_socket);
    return 0;
}

void *handle_client(void *arg) {
    int client_socket = (int)(intptr_t)arg;
    char message[BUFFER_SIZE];
    int bytes_received;

    while (1) {
        bytes_received = recv(client_socket, message, sizeof(message), 0);
        if (bytes_received <= 0) {
            printf("Client disconnected: socket %d\n", client_socket);
            remove_client(client_socket);
            break;
        }

        message[bytes_received] = '\0'; // Null terminate the received string
        printf("Received from client %d: %s\n", client_socket, message);
        broadcast_message(message, client_socket);
    }

    close(client_socket);
    return NULL;
}

void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void remove_client(int socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == socket) {
            client_sockets[i] = client_sockets[--client_count]; // Replace with last client
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}