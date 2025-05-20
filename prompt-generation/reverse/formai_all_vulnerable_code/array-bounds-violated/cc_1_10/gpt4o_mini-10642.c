//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int client_sockets[MAX_CLIENTS];
int client_count = 0;

void *handle_client(void *arg) {
    int new_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(new_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Client %d sent: %s\n", new_socket, buffer);
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != new_socket) {
                send(client_sockets[i], buffer, bytes_read, 0);
            }
        }
    }

    // Remove client socket from list
    close(new_socket);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == new_socket) {
            client_sockets[i] = client_sockets[client_count - 1];
            client_count--;
            break;
        }
    }
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        printf("New client connected: %d\n", new_socket);

        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = new_socket;
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, &new_socket);
            pthread_detach(thread_id);  // detach thread to prevent memory leak
        } else {
            printf("Max clients reached. Rejecting client: %d\n", new_socket);
            close(new_socket);
        }
    }

    return 0;
}