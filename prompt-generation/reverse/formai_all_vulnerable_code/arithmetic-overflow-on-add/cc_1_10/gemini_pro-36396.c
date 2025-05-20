//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Client structure
typedef struct {
    int socket;
    char username[32];
} Client;

// Server structure
typedef struct {
    int server_socket;
    Client clients[MAX_CLIENTS];
    int num_clients;
} Server;

// Function to create a new client
Client* create_client(int socket, char* username) {
    Client* client = malloc(sizeof(Client));
    client->socket = socket;
    strcpy(client->username, username);
    return client;
}

// Function to add a new client to the server
void add_client(Server* server, Client* client) {
    server->clients[server->num_clients++] = *client;
}

// Function to remove a client from the server
void remove_client(Server* server, int socket) {
    for (int i = 0; i < server->num_clients; i++) {
        if (server->clients[i].socket == socket) {
            server->num_clients--;
            for (int j = i; j < server->num_clients; j++) {
                server->clients[j] = server->clients[j + 1];
            }
            break;
        }
    }
}

// Function to send a message to all clients
void broadcast_message(Server* server, char* message) {
    for (int i = 0; i < server->num_clients; i++) {
        send(server->clients[i].socket, message, strlen(message), 0);
    }
}

// Function to handle a new client connection
void handle_connection(Server* server, int socket) {
    char buffer[BUFFER_SIZE];
    char username[32];

    // Receive the username from the client
    recv(socket, username, sizeof(username), 0);

    // Create a new client
    Client* client = create_client(socket, username);

    // Add the client to the server
    add_client(server, client);

    // Broadcast a welcome message to all clients
    char welcome_message[BUFFER_SIZE];
    sprintf(welcome_message, "%s has joined the chat!", username);
    broadcast_message(server, welcome_message);

    // Loop until the client disconnects
    while (1) {
        // Receive a message from the client
        int num_bytes = recv(socket, buffer, sizeof(buffer), 0);

        // If the client disconnected, remove it from the server
        if (num_bytes == 0) {
            remove_client(server, socket);
            break;
        }

        // Broadcast the message to all clients
        char message[BUFFER_SIZE];
        sprintf(message, "%s: %s", username, buffer);
        broadcast_message(server, message);
    }

    // Close the client socket
    close(socket);
}

// Function to start the server
void start_server(Server* server) {
    // Create a new socket
    server->server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Set the socket options
    int opt = 1;
    setsockopt(server->server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    // Bind the socket to the port
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    bind(server->server_socket, (struct sockaddr*)&address, sizeof(address));

    // Listen for new connections
    listen(server->server_socket, MAX_CLIENTS);

    // Loop until the server is stopped
    while (1) {
        // Accept a new connection
        int socket = accept(server->server_socket, NULL, NULL);

        // Handle the new connection in a separate thread
        pthread_t thread;
        pthread_create(&thread, NULL, (void*)&handle_connection, server);
    }

    // Close the server socket
    close(server->server_socket);
}

// Main function
int main() {
    // Create a new server
    Server server;

    // Start the server
    start_server(&server);

    return 0;
}