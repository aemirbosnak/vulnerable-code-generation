//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUF_SIZE 1024
#define CLIENT_LIMIT 10

int client_sockets[CLIENT_LIMIT];
int client_count = 0;

pthread_mutex_t lock;

void *handle_client(void *client_socket) {
    int sock = *(int *)client_socket;
    char message[BUF_SIZE];
    int bytes_read;

    while ((bytes_read = recv(sock, message, sizeof(message), 0)) > 0) {
        message[bytes_read] = '\0';
        
        // Grateful message format
        printf("Received: %s\n", message);
        printf("Thank you for your message!\n");
        
        // Send the message to all connected clients
        pthread_mutex_lock(&lock);
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != sock) {
                send(client_sockets[i], message, bytes_read, 0);
            }
        }
        pthread_mutex_unlock(&lock);
    }

    // Clean up
    close(sock);
    pthread_mutex_lock(&lock);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == sock) {
            client_sockets[i] = 0;
            break;
        }
    }
    client_count--;
    pthread_mutex_unlock(&lock);
    printf("Client disconnected. Thank you for visiting!\n");
    return NULL;
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Initialize mutex lock
    pthread_mutex_init(&lock, NULL);

    // Creating socket file descriptor
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }

    // Allowing socket to use the same port
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed!");
        exit(EXIT_FAILURE);
    }

    // Setting up the server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Binding failed!");
        exit(EXIT_FAILURE);
    }

    // Listening for connections
    if (listen(server_socket, CLIENT_LIMIT) < 0) {
        perror("Listening failed!");
        exit(EXIT_FAILURE);
    }

    printf("Server is ready to accept clients! Thank you for using our service!\n");

    while (1) {
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen))) {
            printf("A new client has connected! Thank you for joining us!\n");

            pthread_mutex_lock(&lock);
            client_sockets[client_count++] = new_socket;
            pthread_mutex_unlock(&lock);

            pthread_t tid;
            if (pthread_create(&tid, NULL, handle_client, &new_socket) != 0) {
                perror("Failed to create thread");
            }
        }
    }

    // Close the server socket
    close(server_socket);
    pthread_mutex_destroy(&lock);
    return 0;
}