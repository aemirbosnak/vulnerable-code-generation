//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
int client_count = 0;

void *handle_client(void *client_socket);
void broadcast_message(const char *message, int sender_socket);
void remove_client(int socket);

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_addr_len = sizeof(client_address);
    pthread_t thread_id;

    // Creating socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        fprintf(stderr, "ERROR!!! Socket creation failed!\n");
        exit(EXIT_FAILURE);
    }
    fprintf(stderr, "SHOCKING!!! Socket created successfully!\n");

    // Configuring server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Binding socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "ERROR!!! Socket binding failed!\n");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    fprintf(stderr, "WOW!!! Socket bound to port %d!\n", PORT);

    // Listening for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        fprintf(stderr, "ERROR!!! Could not listen on socket!\n");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    fprintf(stderr, "ASTOUNDING!!! Server listening for connections...\n");

    // Accepting clients
    while (client_count < MAX_CLIENTS) {
        new_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_addr_len);
        if (new_socket < 0) {
            fprintf(stderr, "ERROR!!! Client connection failed!\n");
            continue;
        }

        // Adding client to the list
        client_sockets[client_count++] = new_socket;
        fprintf(stderr, "YAY!!! Client connected! Total clients: %d\n", client_count);

        // Create a thread for handling the client
        if (pthread_create(&thread_id, NULL, handle_client, (void *)&new_socket) != 0) {
            fprintf(stderr, "ERROR!!! Could not create thread for client!\n");
        }
    }

    // Closing server socket
    close(server_socket);
    fprintf(stderr, "MIND-BLOWING!!! Server closed!\n");
    return 0;
}

void *handle_client(void *client_socket) {
    int socket = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        fprintf(stderr, "MESSAGE RECEIVED: %s\n", buffer);
        broadcast_message(buffer, socket);
    }

    if (read_size == 0) {
        fprintf(stderr, "😱 Client disconnected!\n");
    } else {
        fprintf(stderr, "😱 Receiving error!\n");
    }

    remove_client(socket);
    pthread_exit(NULL);
}

void broadcast_message(const char *message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    fprintf(stderr, "🎉 Message broadcasted to all clients!\n");
}

void remove_client(int socket) {
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == socket) {
            close(socket);
            client_sockets[i] = client_sockets[client_count - 1];
            client_count--;
            fprintf(stderr, "CLIENT LEFT! Total clients now: %d\n", client_count);
            return;
        }
    }
}