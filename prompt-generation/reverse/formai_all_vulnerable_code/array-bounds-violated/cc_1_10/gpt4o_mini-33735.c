//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

// Client structure to hold client details
typedef struct {
    int socket;
    struct sockaddr_in address;
} Client;

// Function to send a message to all clients
void broadcast_message(const char *message, int sender_socket, Client clients[], int client_count) {
    for(int i = 0; i < client_count; i++) {
        if (clients[i].socket != sender_socket) {
            send(clients[i].socket, message, strlen(message), 0);
        }
    }
}

// Client handler for managing individual client connections
void *client_handler(void *arg) {
    char buffer[BUFFER_SIZE];
    Client client = *(Client *)arg;
    int len;

    while((len = recv(client.socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[len] = '\0'; // Null-terminate the received message
        printf("Message from client %d: %s", client.socket, buffer);
        // Broadcast the received message to all other clients
        broadcast_message(buffer, client.socket, NULL, 0); // Broadcasting with NULL clients for now
    }

    close(client.socket);
    printf("Client %d disconnected.\n", client.socket);
    return NULL;
}

int main() {
    int server_socket, new_socket, client_count = 0;
    struct sockaddr_in server_address, client_address;
    Client clients[MAX_CLIENTS];
    pthread_t tid;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
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

    printf("Server is listening on port %d...\n", PORT);

    while (client_count < MAX_CLIENTS) {
        socklen_t addr_len = sizeof(client_address);
        // Accept a new client connection
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_address, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        clients[client_count].socket = new_socket;
        clients[client_count].address = client_address;
        client_count++;

        printf("Client %d connected.\n", new_socket);

        // Create a new thread for each client
        if (pthread_create(&tid, NULL, client_handler, (void *)&clients[client_count - 1]) != 0) {
            perror("Thread creation failed");
            close(new_socket);
            client_count--;
        }
    }

    // Closing server socket
    close(server_socket);
    return 0;
}