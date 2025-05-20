//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BACKLOG 10
#define MAX_CLIENTS 100
#define MAX_REQUEST_SIZE 1024
#define BUFFER_SIZE 4096
#define THREAD_COUNT 5

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;
pthread_t threads[THREAD_COUNT];

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Client disconnected\n");
            close(client_socket);
            pthread_exit(0);
        }

        printf("Received request: %s\n", buffer);

        // Process request here

        send(client_socket, "Response", strlen("Response"), 0);
    }

    return NULL;
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, handle_client, (void *) &client_sockets[i]);
    }

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            close(client_socket);
            printf("Server is full\n");
            continue;
        }

        client_sockets[num_clients] = client_socket;
        num_clients++;

        printf("Client connected\n");
    }

    return 0;
}