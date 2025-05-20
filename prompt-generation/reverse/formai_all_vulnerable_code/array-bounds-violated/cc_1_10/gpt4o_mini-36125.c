//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

static int client_count = 0;
static int client_sockets[MAX_CLIENTS];

void *handle_client(void *arg);
void broadcast_message(const char *message, int sender_socket);

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Prepare server address
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
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d...\n", PORT);

    while (1) {
        // Accept new clients
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }

        // Add new client socket to the array
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count] = new_socket;
            client_count++;
            printf("New client connected. Total clients: %d\n", client_count);

            // Create a new thread for the client
            pthread_t tid;
            pthread_create(&tid, NULL, handle_client, (void *)&new_socket);
            pthread_detach(tid);
        } else {
            printf("Max clients reached. Connection rejected.\n");
            close(new_socket);
        }
    }

    return 0;
}

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    // Notify the new client
    char welcome_msg[] = "Welcome to the chat server!\n";
    send(client_socket, welcome_msg, sizeof(welcome_msg), 0);

    // Handle incoming messages from the client
    while ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';  // Null terminate the string
        printf("Client: %s", buffer);
        broadcast_message(buffer, client_socket);
    }

    // Client disconnected
    printf("Client disconnected.\n");
    close(client_socket);
    return NULL;
}

void broadcast_message(const char *message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}