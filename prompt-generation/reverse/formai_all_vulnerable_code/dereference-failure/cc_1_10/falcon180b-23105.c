//Falcon-180B DATASET v1.0 Category: Networking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int g_socket;
struct sockaddr_in g_server_addr;
int g_server_port;

pthread_t g_client_threads[MAX_CLIENTS];
int g_num_clients;

void* handle_client(void* arg) {
    int client_socket = *(int*)arg;
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            close(client_socket);
            pthread_exit(NULL);
        }
        printf("Client %d sent: %s\n", client_socket, buffer);
        send(client_socket, buffer, strlen(buffer), 0);
    }
}

void accept_connections() {
    while (1) {
        int client_socket = accept(g_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }
        if (g_num_clients >= MAX_CLIENTS) {
            close(client_socket);
            printf("Server is full. Cannot accept more connections.\n");
            continue;
        }
        g_client_threads[g_num_clients] = malloc(sizeof(pthread_t));
        pthread_create(g_client_threads[g_num_clients], NULL, handle_client, (void*)&client_socket);
        g_num_clients++;
    }
}

int main() {
    g_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (g_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    g_server_addr.sin_family = AF_INET;
    g_server_addr.sin_port = htons(g_server_port);
    g_server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(g_socket, (struct sockaddr*)&g_server_addr, sizeof(g_server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(g_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started on port %d\n", g_server_port);

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, accept_connections, NULL);

    while (1) {
        sleep(1000);
    }

    return 0;
}