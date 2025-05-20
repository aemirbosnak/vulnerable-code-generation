//FormAI DATASET v1.0 Category: Chat server ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8000
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int clients_count = 0;
int clients[MAX_CLIENTS];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void broadcast(char *message, int sender_id) {
    for (int i = 0; i < clients_count; i++) {
        if (clients[i] != sender_id) {
            send(clients[i], message, strlen(message), 0);
        }
    }
}

void *handle_client(void *args) {
    int client_socket = *((int*) args);
    char buffer[BUFFER_SIZE];
    int read_size;

    pthread_mutex_lock(&mutex);
    clients[clients_count++] = client_socket;
    pthread_mutex_unlock(&mutex);

    printf("Client connected: %d\n", client_socket);

    while ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        broadcast(buffer, client_socket);
    }

    pthread_mutex_lock(&mutex);
    for (int i = 0; i < clients_count; i++) {
        if (clients[i] == client_socket) {
            while (i < clients_count - 1) {
                clients[i] = clients[i+1];
                i++;
            }
            break;
        }
    }
    clients_count--;
    pthread_mutex_unlock(&mutex);

    printf("Client disconnected: %d\n", client_socket);
    close(client_socket);
}

int main(int argc, char const *argv[]) {
    int server_socket, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    pthread_t thread;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *) &address, addrlen) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        if ((new_socket = accept(server_socket, (struct sockaddr *) &address, (socklen_t*) &addrlen)) < 0) {
            perror("Accept failed");
            continue;
        }

        if (pthread_create(&thread, NULL, handle_client, (void*) &new_socket) < 0) {
            perror("Thread creation failed");
            continue;
        }
    }

    return 0;
}