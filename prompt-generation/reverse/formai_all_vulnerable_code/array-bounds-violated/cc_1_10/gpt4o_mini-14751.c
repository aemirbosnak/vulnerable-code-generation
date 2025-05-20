//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

int client_sockets[MAX_CLIENTS];
int current_client_count = 0;
pthread_mutex_t lock;

void *handle_client(void *arg) {
    int client_socket = *((int *) arg);
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while((bytes_read = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0'; // null-terminate the string
        printf("Received: %s\n", buffer);

        // Broadcast the message to all other clients
        pthread_mutex_lock(&lock);
        for(int i = 0; i < current_client_count; i++) {
            if (client_sockets[i] != client_socket) {
                send(client_sockets[i], buffer, bytes_read, 0);
            }
        }
        pthread_mutex_unlock(&lock);
    }

    // Handle client disconnection
    pthread_mutex_lock(&lock);
    for(int i = 0; i < current_client_count; i++) {
        if (client_sockets[i] == client_socket) {
            client_sockets[i] = client_sockets[current_client_count - 1];
            current_client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&lock);
    close(client_socket);
    printf("Client disconnected\n");
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Initialize socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    pthread_mutex_init(&lock, NULL);
    printf("Server listening on port %d\n", PORT);

    while(1) {
        // Accept a new client
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        pthread_mutex_lock(&lock);
        if (current_client_count < MAX_CLIENTS) {
            client_sockets[current_client_count] = client_socket;
            current_client_count++;
            printf("New client connected, current clients: %d\n", current_client_count);
        } else {
            printf("Max clients reached. Connection rejected.\n");
            close(client_socket);
        }
        pthread_mutex_unlock(&lock);

        // Create a new thread for the client
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)&client_socket) != 0) {
            perror("Thread creation failed");
            close(client_socket);
        }
        pthread_detach(tid); // Detach thread to handle its cleanup automatically
    }

    // Cleanup
    close(server_socket);
    pthread_mutex_destroy(&lock);
    return 0;
}