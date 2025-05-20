//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: safe
// chat_server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void *client_handler(void *socket_desc);
void broadcast_message(const char *message, int sender_socket, int clients[], int client_count);

int clients[MAX_CLIENTS];
int client_count = 0;

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind the socket
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Chat server started on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        if (client_count < MAX_CLIENTS) {
            clients[client_count++] = new_socket;
            pthread_t thread_id;
            if (pthread_create(&thread_id, NULL, client_handler, (void *)&new_socket) < 0) {
                perror("Could not create thread");
                exit(EXIT_FAILURE);
            }
        } else {
            printf("Maximum clients reached. Connection rejected.\n");
            close(new_socket);
        }
    }

    close(server_fd);
    return 0;
}

void *client_handler(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Received message: %s", buffer);
        broadcast_message(buffer, sock, clients, client_count);
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
    } else if (read_size < 0) {
        perror("Recv error");
    }

    close(sock);
    return 0;
}

void broadcast_message(const char *message, int sender_socket, int clients[], int client_count) {
    for (int i = 0; i < client_count; i++) {
        if (clients[i] != sender_socket) {
            send(clients[i], message, strlen(message), 0);
        }
    }
}