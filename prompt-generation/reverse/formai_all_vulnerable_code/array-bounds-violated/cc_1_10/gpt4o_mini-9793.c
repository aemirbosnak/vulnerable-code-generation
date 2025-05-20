//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: authentic
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
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0'; // Null-terminate string
        printf("Client %d: %s", client_socket, buffer);
        pthread_mutex_lock(&clients_mutex);
        for(int i = 0; i < MAX_CLIENTS; i++) {
            if(clients[i] != 0 && clients[i] != client_socket) {
                send(clients[i], buffer, n, 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }
    
    // Handle client disconnection
    pthread_mutex_lock(&clients_mutex);
    for(int i = 0; i < MAX_CLIENTS; i++) {
        if(clients[i] == client_socket) {
            clients[i] = 0; // Mark client as disconnected
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);

    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Initialize clients array
    memset(clients, 0, sizeof(clients));

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind Failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen Failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat Server started on port %d\n", PORT);

    while (1) {
        // Accept a client
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept Failed");
            continue;
        }

        // Check for available slot in clients array
        pthread_mutex_lock(&clients_mutex);
        int i;
        for(i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i] == 0) {
                clients[i] = client_socket;
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);

        if (i == MAX_CLIENTS) {
            printf("Max clients connected, connection rejected\n");
            close(client_socket);
            continue;
        }

        // Create a thread to handle client
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)&client_socket) != 0) {
            perror("Thread Creation Failed");
            close(client_socket);
            clients[i] = 0; // Mark client as disconnected
        } else {
            pthread_detach(tid); // Automatically free resources when finished
        }

        printf("New client connected: %d\n", client_socket);
    }

    return 0;
}