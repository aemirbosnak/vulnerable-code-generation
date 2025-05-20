//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8888
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

char *clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg);
void broadcast(const char *message, int sender_index);

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    while (client_count < MAX_CLIENTS) {
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len);
        if (client_fd < 0) {
            perror("Accept failed");
            continue;
        }

        // Add client to clients array
        pthread_mutex_lock(&clients_mutex);
        clients[client_count] = malloc(BUFFER_SIZE);
        if (clients[client_count] == NULL) {
            perror("Memory allocation failed");
            close(client_fd);
            continue;
        }
        snprintf(clients[client_count], BUFFER_SIZE, "Client_%d", client_count);
        printf("%s connected\n", clients[client_count]);
        client_count++;
        pthread_mutex_unlock(&clients_mutex);

        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, (void *)(long)client_fd) != 0) {
            perror("Could not create thread");
        }
    }

    close(server_fd);
    return 0;
}

void *handle_client(void *arg) {
    int client_fd = (int)(long)arg;
    char buffer[BUFFER_SIZE];
    int received;

    while ((received = recv(client_fd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[received] = '\0';
        printf("Received: %s\n", buffer);
        broadcast(buffer, client_fd);
    }

    if (received <= 0) {
        printf("Client disconnected\n");
    }

    close(client_fd);
    return NULL;
}

void broadcast(const char *message, int sender_index) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (strcmp(clients[i], message) != 0) {
            send(i + 1, message, strlen(message), 0); // Send to all clients except sender
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}