//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <errno.h>

// Custom data structure for client information
typedef struct client {
    int socket;
    char* name;
    time_t last_activity;
} client_t;

// Global variables
int server_socket;
int num_clients = 0;
client_t* clients[100];

// Function declarations
void sigint_handler(int sig);
int add_client(int socket, char* name);
int remove_client(int socket);
void broadcast_message(char* message);
void handle_client(int socket);

int main() {
    // Register signal handler for SIGINT (Ctrl+C)
    signal(SIGINT, sigint_handler);

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set socket options
    int optval = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind server socket to address and port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(5000);
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, 100) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Main loop
    while (1) {
        // Accept incoming connection
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Set client socket to non-blocking mode
        if (fcntl(client_socket, F_SETFL, fcntl(client_socket, F_GETFL) | O_NONBLOCK) == -1) {
            perror("fcntl");
            close(client_socket);
            continue;
        }

        // Read client name
        char name[100];
        int bytes_received = recv(client_socket, name, sizeof(name), 0);
        if (bytes_received == -1) {
            perror("recv");
            close(client_socket);
            continue;
        }
        name[bytes_received] = '\0';

        // Add client to list of clients
        if (!add_client(client_socket, name)) {
            close(client_socket);
            continue;
        }

        // Handle client in a separate thread
        handle_client(client_socket);
    }

    // Cleanup
    close(server_socket);
    for (int i = 0; i < num_clients; i++) {
        close(clients[i]->socket);
        free(clients[i]->name);
        free(clients[i]);
    }

    return EXIT_SUCCESS;
}

// Signal handler for SIGINT (Ctrl+C)
void sigint_handler(int sig) {
    // Cleanup and exit
    close(server_socket);
    for (int i = 0; i < num_clients; i++) {
        close(clients[i]->socket);
        free(clients[i]->name);
        free(clients[i]);
    }
    exit(0);
}

// Add a client to the list of clients
int add_client(int socket, char* name) {
    // Check if client list is full
    if (num_clients >= 100) {
        return 0;
    }

    // Create new client struct
    client_t* client = malloc(sizeof(client_t));
    if (client == NULL) {
        perror("malloc");
        return 0;
    }

    // Initialize client struct
    client->socket = socket;
    client->name = strdup(name);
    client->last_activity = time(NULL);

    // Add client to list of clients
    clients[num_clients] = client;
    num_clients++;

    // Broadcast new client's name to all other clients
    char message[100];
    sprintf(message, "%s has joined the chat", name);
    broadcast_message(message);

    return 1;
}

// Remove a client from the list of clients
int remove_client(int socket) {
    // Find client in list of clients
    int index = -1;
    for (int i = 0; i < num_clients; i++) {
        if (clients[i]->socket == socket) {
            index = i;
            break;
        }
    }

    // If client not found, return 0
    if (index == -1) {
        return 0;
    }

    // Remove client from list of clients
    free(clients[index]->name);
    free(clients[index]);
    for (int i = index; i < num_clients - 1; i++) {
        clients[i] = clients[i + 1];
    }
    num_clients--;

    // Broadcast client's departure to all other clients
    char message[100];
    sprintf(message, "%s has left the chat", clients[index]->name);
    broadcast_message(message);

    return 1;
}

// Broadcast a message to all clients
void broadcast_message(char* message) {
    for (int i = 0; i < num_clients; i++) {
        send(clients[i]->socket, message, strlen(message), 0);
    }
}

// Handle a client in a separate thread
void handle_client(int socket) {
    while (1) {
        // Receive message from client
        char message[100];
        int bytes_received = recv(socket, message, sizeof(message), 0);
        if (bytes_received == -1) {
            if (errno == EAGAIN) {
                // No data available, continue to next client
                continue;
            } else {
                perror("recv");
                break;
            }
        } else if (bytes_received == 0) {
            // Client has closed connection, remove from list of clients
            if (!remove_client(socket)) {
                break;
            }
            break;
        }

        // Update client's last activity time
        clients[num_clients]->last_activity = time(NULL);

        // Broadcast message to all other clients
        char new_message[100];
        sprintf(new_message, "%s: %s", clients[num_clients]->name, message);
        broadcast_message(new_message);
    }

    // Close client socket
    close(socket);
}