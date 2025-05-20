//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void *client_handler(void *arg);
void broadcast_message(const char *message, int sender_sock);

int clients[MAX_CLIENTS];
int client_count = 0;

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server is listening on port %d...\n", PORT);

    while ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len))) {
        if (client_count < MAX_CLIENTS) {
            clients[client_count++] = new_socket;
            printf("New client connected, socket fd: %d, ip: %s, port: %d\n", 
                   new_socket, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, client_handler, (void *)&new_socket);
        } else {
            printf("Maximum clients reached. Connection refused.\n");
            close(new_socket);
        }
    }

    return 0;
}

void *client_handler(void *arg) {
    int socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';

        if (strcmp(buffer, "MAGIC_WORD\n") == 0) {
            send(socket, "🎩 You've unveiled the magic response! Keep chatting! 🎩\n", 56, 0);
        } else {
            printf("Client sent: %s", buffer);
            broadcast_message(buffer, socket);
        }
    }

    close(socket);
    return NULL;
}

void broadcast_message(const char *message, int sender_sock) {
    for (int i = 0; i < client_count; ++i) {
        if (clients[i] != sender_sock) {
            send(clients[i], message, strlen(message), 0);
        }
    }
}