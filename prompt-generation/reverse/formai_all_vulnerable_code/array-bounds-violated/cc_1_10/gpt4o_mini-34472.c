//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: accurate
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
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg);
void broadcast_message(char *message, int sender_fd);
void add_client(int client_fd);
void remove_client(int client_fd);

int main() {
    int server_fd, client_fd, address_len;
    struct sockaddr_in server_addr, client_addr;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    address_len = sizeof(client_addr);
    
    while (1) {
        // Accept client connections
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&address_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: fd=%d\n", client_fd);
        
        pthread_t tid;
        add_client(client_fd);
        if (pthread_create(&tid, NULL, handle_client, (void *)&client_fd) != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }
    
    return 0;
}

void *handle_client(void *arg) {
    int client_fd = *(int*)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client_fd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the string
        printf("Client %d: %s\n", client_fd, buffer);
        broadcast_message(buffer, client_fd);
    }

    printf("Client %d disconnected\n", client_fd);
    remove_client(client_fd);
    close(client_fd);
    return NULL;
}

void broadcast_message(char *message, int sender_fd) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] != sender_fd) {
            send(clients[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void add_client(int client_fd) {
    pthread_mutex_lock(&clients_mutex);
    clients[client_count++] = client_fd;
    pthread_mutex_unlock(&clients_mutex);
}

void remove_client(int client_fd) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] == client_fd) {
            clients[i] = clients[--client_count]; // Replace with the last element
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}