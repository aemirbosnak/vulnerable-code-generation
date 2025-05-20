//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t client_count_mutex;

void *handle_client(void *arg) {
    int client_socket = *((int *)arg);
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client [%d] says: %s\n", client_socket, buffer);

        // Broadcast message to all clients
        pthread_mutex_lock(&client_count_mutex);
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != client_socket) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
        pthread_mutex_unlock(&client_count_mutex);
    }

    close(client_socket);
    
    // Remove client from the list
    pthread_mutex_lock(&client_count_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == client_socket) {
            for (int j = i; j < client_count - 1; j++) {
                client_sockets[j] = client_sockets[j + 1];
            }
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&client_count_mutex);
    return NULL;
}

void start_server() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);
    
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    listen(server_socket, MAX_CLIENTS);
    printf("Server is listening on port %d...\n", SERVER_PORT);
    
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        pthread_mutex_lock(&client_count_mutex);
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = client_socket;
            pthread_t thread;
            pthread_create(&thread, NULL, handle_client, (void *)&client_socket);
        } else {
            printf("Max clients reached. Connection refused.\n");
            close(client_socket);
        }
        pthread_mutex_unlock(&client_count_mutex);
    }
}

int main() {
    pthread_mutex_init(&client_count_mutex, NULL);
    start_server();
    pthread_mutex_destroy(&client_count_mutex);
    return 0;
}