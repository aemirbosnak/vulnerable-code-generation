//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: beginner-friendly
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
pthread_mutex_t lock;

void *handle_client(void *arg) {
    int sock = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Client %d: %s\n", sock, buffer);

        // Broadcast the message to all other connected clients
        pthread_mutex_lock(&lock);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] != 0 && client_sockets[i] != sock) {
                send(client_sockets[i], buffer, bytes_read, 0);
            }
        }
        pthread_mutex_unlock(&lock);
    }

    // Remove client from the list on disconnect
    pthread_mutex_lock(&lock);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == sock) {
            client_sockets[i] = 0;
            printf("Client %d disconnected.\n", sock);
            break;
        }
    }
    pthread_mutex_unlock(&lock);
    close(sock);
    return NULL;
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    
    // Initialize client_sockets array
    memset(client_sockets, 0, sizeof(client_sockets));
    
    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind the socket
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed!");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("Listen failed!");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        addr_size = sizeof(client_addr);
        if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_size)) < 0) {
            perror("Accept failed!");
            continue;
        }
        
        // Add the new client to the array
        pthread_mutex_lock(&lock);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = client_sock;
                printf("Client %d connected.\n", client_sock);
                break;
            }
        }
        pthread_mutex_unlock(&lock);

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)&client_sock) != 0) {
            perror("Could not create thread!");
            exit(EXIT_FAILURE);
        }
        pthread_detach(thread_id);
    }

    // Cleanup
    pthread_mutex_destroy(&lock);
    close(server_sock);
    return 0;
}