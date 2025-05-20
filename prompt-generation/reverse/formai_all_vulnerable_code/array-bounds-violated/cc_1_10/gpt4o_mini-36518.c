//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

void *client_handler(void *arg);
void send_message_to_all(char *message, int sender_socket);

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t addr_len = sizeof(client_address);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY; // Accept connections from any address
    server_address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        // Accept new client
        new_socket = accept(server_socket, (struct sockaddr *)&client_address, &addr_len);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }

        printf("New client connected! Socket fd is %d.\n", new_socket);

        // Add to clients list
        pthread_mutex_lock(&clients_mutex);
        client_sockets[client_count++] = new_socket;
        pthread_mutex_unlock(&clients_mutex);

        // Create thread for each client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, client_handler, (void *)&new_socket) != 0) {
            perror("Could not create thread");
        }
    }

    close(server_socket);
    return 0;
}

void *client_handler(void *arg) {
    int sock = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    // Communication loop
    while ((read_size = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the string
        printf("Received: %s", buffer); // Print message to console
        
        // Broadcast message to other clients
        send_message_to_all(buffer, sock);
    }

    // Client disconnected
    if (read_size == 0) {
        printf("Client disconnected. Socket fd is %d.\n", sock);
    } else {
        perror("Recv failed");
    }

    // Remove client from list
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == sock) {
            client_sockets[i] = client_sockets[--client_count]; // Remove client
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    close(sock);
    return NULL;
}

void send_message_to_all(char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        // Do not send the message to the sender
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}