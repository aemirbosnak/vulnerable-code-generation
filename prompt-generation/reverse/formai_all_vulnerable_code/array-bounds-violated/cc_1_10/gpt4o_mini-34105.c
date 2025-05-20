//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t client_count_mutex;

void *handle_client(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;

    // Add the new client socket to the array
    pthread_mutex_lock(&client_count_mutex);
    client_sockets[client_count++] = sock;
    pthread_mutex_unlock(&client_count_mutex);

    // Communication loop
    while ((read_size = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the received message

        // Broadcast message to all clients
        pthread_mutex_lock(&client_count_mutex);
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != sock) { // Don't send the message to the sender
                send(client_sockets[i], buffer, read_size, 0);
            }
        }
        pthread_mutex_unlock(&client_count_mutex);
    }

    // Remove the socket from the array and decrement client count
    pthread_mutex_lock(&client_count_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == sock) {
            client_sockets[i] = client_sockets[client_count - 1]; // Replace with the last client
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&client_count_mutex);
    close(sock);
    return 0;
}

int main() {
    int server_socket, new_client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    pthread_mutex_init(&client_count_mutex, NULL);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
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
    listen(server_socket, 3);
    printf("Chat server is running on port %d. Waiting for connections...\n", PORT);

    while (1) {
        // Accept an incoming connection
        new_client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (new_client_socket < 0) {
            perror("Accept failed");
            continue;
        }
        printf("New client connected: socket %d\n", new_client_socket);

        // Create a thread for the new client
        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, handle_client, (void *)&new_client_socket) != 0) {
            perror("Could not create thread");
            close(new_client_socket);
        }
    }

    // Clean up
    close(server_socket);
    pthread_mutex_destroy(&client_count_mutex);
    return 0;
}