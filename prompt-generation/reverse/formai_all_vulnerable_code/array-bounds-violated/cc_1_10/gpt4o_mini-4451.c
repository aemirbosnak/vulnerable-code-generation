//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg);
void send_message(const char *msg, int sender_fd);
void add_client(int client_fd);
void remove_client(int client_fd);

int main() {
    int server_fd, new_client_fd;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set Socket Options Failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    
    printf("Chat Server is running on port %d...\n", PORT);

    while (1) {
        // Accept client connection
        if ((new_client_fd = accept(server_fd, (struct sockaddr *)&address, &addrlen)) < 0) {
            perror("Accept failed");
            continue; // Avoid stopping the server
        }

        pthread_mutex_lock(&clients_mutex);
        if (client_count < MAX_CLIENTS) {
            clients[client_count++] = new_client_fd;
            pthread_t client_thread;
            pthread_create(&client_thread, NULL, handle_client, (void *)(long)new_client_fd);
            pthread_detach(client_thread);
        } else {
            printf("Max clients connected. Rejecting new client.\n");
            close(new_client_fd);
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    return 0;
}

void *handle_client(void *arg) {
    int client_fd = (int)(long)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client_fd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate string
        printf("Received: %s\n", buffer);
        send_message(buffer, client_fd);
    }

    if (bytes_read == 0) {
        printf("Client disconnected.\n");
    } else if (bytes_read < 0) {
        perror("Receive failed");
    }

    remove_client(client_fd);
    close(client_fd);
    return NULL;
}

void send_message(const char *msg, int sender_fd) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] != sender_fd) {
            send(clients[i], msg, strlen(msg), 0);
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
            clients[i] = clients[--client_count]; // Replace with last client
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}