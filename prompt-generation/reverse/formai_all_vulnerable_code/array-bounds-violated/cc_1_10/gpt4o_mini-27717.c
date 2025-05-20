//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int client_count = 0;

void *handle_client(void *arg) {
    int client_sock = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(client_sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';
        printf("Client: %s", buffer);
        for (int i = 0; i < client_count; ++i) {
            if (clients[i] != client_sock) {
                send(clients[i], buffer, n, 0);
            }
        }
    }

    close(client_sock);
    for (int i = 0; i < client_count; ++i) {
        if (clients[i] == client_sock) {
            clients[i] = clients[client_count - 1];
            client_count--;
            break;
        }
    }
    return NULL;
}

int main() {
    int server_fd, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
  
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation failed");
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

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);
  
    while (1) {
        client_sock = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("Accept failed");
            continue;
        }

        if (client_count < MAX_CLIENTS) {
            clients[client_count++] = client_sock;
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *)&client_sock);
            pthread_detach(thread_id);
            printf("New client connected\n");
        } else {
            printf("Maximum clients reached. Client rejected.\n");
            close(client_sock);
        }
    }
    close(server_fd);
    return 0;
}