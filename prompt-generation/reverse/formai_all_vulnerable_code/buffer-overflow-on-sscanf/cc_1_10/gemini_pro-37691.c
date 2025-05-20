//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

// Structure to store client information
typedef struct client {
    int socket;
    char name[256];
} client;

// Array to store connected clients
client clients[MAX_CLIENTS];

// Mutex to protect the clients array
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle client connections
void *handle_client(void *arg) {
    // Get the client socket
    int client_socket = *(int *)arg;

    // Get the client name
    char name[256];
    recv(client_socket, name, sizeof(name), 0);

    // Lock the clients array
    pthread_mutex_lock(&clients_mutex);

    // Add the client to the array
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].socket == 0) {
            clients[i].socket = client_socket;
            strcpy(clients[i].name, name);
            break;
        }
    }

    // Unlock the clients array
    pthread_mutex_unlock(&clients_mutex);

    // Send a welcome message to the client
    char welcome_message[256];
    sprintf(welcome_message, "Welcome to the smart home, %s!", name);
    send(client_socket, welcome_message, strlen(welcome_message), 0);

    // Loop to handle client requests
    while (1) {
        // Receive the client request
        char request[256];
        int recv_len = recv(client_socket, request, sizeof(request), 0);

        // If the client has disconnected, break the loop
        if (recv_len == 0) {
            break;
        }

        // Parse the client request
        char command[256];
        char argument[256];
        sscanf(request, "%s %s", command, argument);

        // Handle the client request
        if (strcmp(command, "turn_on") == 0) {
            // Send a message to the smart home to turn on the light
            char turn_on_message[256];
            sprintf(turn_on_message, "turn_on %s", argument);
            send(client_socket, turn_on_message, strlen(turn_on_message), 0);
        } else if (strcmp(command, "turn_off") == 0) {
            // Send a message to the smart home to turn off the light
            char turn_off_message[256];
            sprintf(turn_off_message, "turn_off %s", argument);
            send(client_socket, turn_off_message, strlen(turn_off_message), 0);
        } else if (strcmp(command, "quit") == 0) {
            // Break the loop to close the client connection
            break;
        }
    }

    // Close the client socket
    close(client_socket);

    // Lock the clients array
    pthread_mutex_lock(&clients_mutex);

    // Remove the client from the array
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].socket == client_socket) {
            clients[i].socket = 0;
            strcpy(clients[i].name, "");
            break;
        }
    }

    // Unlock the clients array
    pthread_mutex_unlock(&clients_mutex);

    // Return NULL to indicate that the thread has finished
    return NULL;
}

int main() {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Set the socket options
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Bind the socket to the port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    // Listen for client connections
    listen(server_socket, MAX_CLIENTS);

    // Loop to handle client connections
    while (1) {
        // Accept a client connection
        int client_socket = accept(server_socket, NULL, NULL);

        // Create a new thread to handle the client connection
        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, &client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}