//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: satisfied
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
int active_clients = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';
        
        // Send message to all clients
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < active_clients; i++) {
            if (client_sockets[i] != sock) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    // Close the socket and remove from active clients
    close(sock);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < active_clients; i++) {
        if (client_sockets[i] == sock) {
            for (int j = i; j < active_clients - 1; j++) {
                client_sockets[j] = client_sockets[j + 1];
            }
            active_clients--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t tid;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        // Accept a new client
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        // Store the client socket in the active clients array
        pthread_mutex_lock(&clients_mutex);
        client_sockets[active_clients++] = client_socket;
        pthread_mutex_unlock(&clients_mutex);

        // Create a thread to handle the client
        pthread_create(&tid, NULL, handle_client, (void *)&client_socket);
    }

    // Close server socket
    close(server_socket);
    return 0;
}