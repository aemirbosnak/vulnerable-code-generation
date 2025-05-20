//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: thoughtful
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
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle client messages
void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';
        printf("Client %d: %s\n", client_socket, buffer);
        
        // Broadcasting message to all connected clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] != 0 && client_sockets[i] != client_socket) {
                send(client_sockets[i], buffer, n, 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Removing client socket on disconnect
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = 0;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_addr_len = sizeof(client_address);
    
    // Initialize client sockets
    memset(client_sockets, 0, sizeof(client_sockets));

    // Creating socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting up the server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Binding socket
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listening for clients
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat Server started on port %d\n", PORT);
    
    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_addr_len)) >= 0) {
            printf("New client connected: %d\n", client_socket);
            
            pthread_mutex_lock(&clients_mutex);
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = client_socket;
                    break;
                }
            }
            pthread_mutex_unlock(&clients_mutex);

            // Creating a thread for the new client
            pthread_t thread_id;
            if (pthread_create(&thread_id, NULL, handle_client, &client_socket) != 0) {
                perror("pthread_create failed");
                close(client_socket);
            }
        } else {
            perror("accept failed");
        }
    }

    return 0;
}