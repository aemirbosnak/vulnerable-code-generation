//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 5000
#define MAX_CLIENTS 10

struct client {
    int socket;
    char username[256];
};

struct server {
    int socket;
    int num_clients;
    struct client clients[MAX_CLIENTS];
};

void send_message(struct server *server, char *message) {
    for (int i = 0; i < server->num_clients; i++) {
        send(server->clients[i].socket, message, strlen(message), 0);
    }
}

void handle_client(struct server *server, struct client *client) {
    char buffer[256];
    while (1) {
        int n = recv(client->socket, buffer, sizeof(buffer), 0);
        if (n == 0) {
            // Client disconnected
            printf("%s disconnected.\n", client->username);
            // Remove client from server
            for (int i = 0; i < server->num_clients; i++) {
                if (server->clients[i].socket == client->socket) {
                    server->clients[i] = server->clients[server->num_clients - 1];
                    server->num_clients--;
                    break;
                }
            }
            close(client->socket);
            break;
        } else if (n < 0) {
            // Error receiving message
            perror("recv");
            break;
        } else {
            // Message received
            buffer[n] = '\0';
            printf("%s: %s\n", client->username, buffer);
            send_message(server, buffer);
        }
    }
}

void start_server() {
    int server_socket;
    struct sockaddr_in server_address;

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind server socket to address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Create server struct
    struct server server;
    server.socket = server_socket;
    server.num_clients = 0;

    printf("Server started on port %d.\n", PORT);

    // Main server loop
    while (1) {
        // Accept incoming connections
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        // Add client to server
        if (server.num_clients < MAX_CLIENTS) {
            server.clients[server.num_clients].socket = client_socket;
            // Receive username from client
            char username[256];
            int n = recv(client_socket, username, sizeof(username), 0);
            if (n == 0) {
                // Client disconnected
                printf("Client disconnected.\n");
                close(client_socket);
                continue;
            } else if (n < 0) {
                // Error receiving message
                perror("recv");
                close(client_socket);
                continue;
            } else {
                // Username received
                username[n] = '\0';
                strcpy(server.clients[server.num_clients].username, username);
                printf("%s joined the chat.\n", username);
                server.num_clients++;
            }

            // Send welcome message to client
            char welcome_message[256];
            sprintf(welcome_message, "Welcome to the chat, %s!\n", username);
            send(client_socket, welcome_message, strlen(welcome_message), 0);
        } else {
            // Server full
            char error_message[256];
            sprintf(error_message, "Server full. Please try again later.\n");
            send(client_socket, error_message, strlen(error_message), 0);
            close(client_socket);
        }

        // Handle client in separate thread
        pthread_t thread;
        pthread_create(&thread, NULL, (void *) handle_client, &server);
    }

    // Close server socket
    close(server_socket);
}

int main() {
    start_server();
    return 0;
}