//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>

#define PORT 8888
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void broadcast_message(const char *message, int sender) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (clients[i] != 0 && clients[i] != sender) {
            send(clients[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void *client_handler(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    
    while (1) {
        ssize_t nbytes = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
        if (nbytes <= 0) {
            break;
        }
        buffer[nbytes] = '\0';
        printf("Client: %s\n", buffer);
        broadcast_message(buffer, client_socket);
    }
    
    close(client_socket);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i) {
        if (clients[i] == client_socket) {
            clients[i] = 0; // Remove client
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    printf("Client disconnected.\n");
    return NULL;
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(client_addr);
    
    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    // Listen for connections
    listen(server_socket, 3);
    printf("Chat server started on port %d.\n", PORT);
    
    while (1) {
        int new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);
        printf("New client connected.\n");
        
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; ++i) {
            if (clients[i] == 0) {
                clients[i] = new_socket;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        pthread_t tid;
        if (pthread_create(&tid, NULL, &client_handler, (void *)&new_socket) != 0) {
            perror("pthread_create failed");
        }
    }
    
    close(server_socket);
    return 0;
}