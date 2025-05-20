//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in address;
} client_t;

client_t *clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void send_message_to_all_clients(char *message, int sender_sockfd) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i]->sockfd != sender_sockfd) {
            if (send(clients[i]->sockfd, message, strlen(message), 0) < 0) {
                perror("Failed to send message");
            }
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(client->sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Received message: %s\n", buffer);
        send_message_to_all_clients(buffer, client->sockfd);
    }

    if (read_size == 0) {
        printf("Client disconnected: %d\n", client->sockfd);
        close(client->sockfd);
    } else {
        perror("Recv failed");
    }

    free(client);
    return NULL;
}

int main() {
    int listener_sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(client_addr);
    pthread_t tid;

    listener_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listener_sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listener_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(listener_sockfd);
        return 1;
    }

    if (listen(listener_sockfd, 10) < 0) {
        perror("Listen failed");
        close(listener_sockfd);
        return 1;
    }

    printf("Chat server started on port %d. Grateful for your presence!\n", PORT);

    while (1) {
        client_t *client = (client_t *)malloc(sizeof(client_t));
        if (!client) {
            perror("Failed to allocate memory for new client");
            continue;
        }

        client->sockfd = accept(listener_sockfd, (struct sockaddr *)&client_addr, &addr_size);
        if (client->sockfd < 0) {
            perror("Failed to accept incoming connection");
            free(client);
            continue;
        }

        printf("New connection accepted. Connected clients: %d\n", client_count + 1);

        // Store client in array
        pthread_mutex_lock(&clients_mutex);
        clients[client_count++] = client;
        pthread_mutex_unlock(&clients_mutex);

        if (pthread_create(&tid, NULL, handle_client, (void *)client) != 0) {
            perror("Failed to create thread");
            free(client);
        }
    }

    close(listener_sockfd);
    return 0;
}