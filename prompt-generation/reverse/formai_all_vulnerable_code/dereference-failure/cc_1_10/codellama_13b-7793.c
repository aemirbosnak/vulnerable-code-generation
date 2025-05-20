//Code Llama-13B DATASET v1.0 Category: Client Server Application ; Style: all-encompassing
// Client Server Application Example
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define constants
#define MAX_BUFFER 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

// Define struct for client and server
struct client {
    int sock;
    char buffer[MAX_BUFFER];
};

struct server {
    int sock;
    char buffer[MAX_BUFFER];
};

// Function to create client
void create_client(struct client *client) {
    // Create socket
    client->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client->sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to server
    if (connect(client->sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        exit(1);
    }

    // Print client information
    printf("Client connected with server\n");
}

// Function to create server
void create_server(struct server *server) {
    // Create socket
    server->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Bind socket
    if (bind(server->sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen to socket
    if (listen(server->sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    // Print server information
    printf("Server started and listening\n");
}

// Function to receive message from client
void receive_message(struct client *client) {
    // Read message from client
    int n = read(client->sock, client->buffer, MAX_BUFFER);
    if (n < 0) {
        perror("read failed");
        exit(1);
    }

    // Print received message
    printf("Message received: %s\n", client->buffer);
}

// Function to send message to client
void send_message(struct client *client) {
    // Write message to client
    int n = write(client->sock, client->buffer, strlen(client->buffer));
    if (n < 0) {
        perror("write failed");
        exit(1);
    }

    // Print sent message
    printf("Message sent: %s\n", client->buffer);
}

// Function to close client socket
void close_client(struct client *client) {
    // Close client socket
    close(client->sock);

    // Print client information
    printf("Client disconnected\n");
}

// Function to close server socket
void close_server(struct server *server) {
    // Close server socket
    close(server->sock);

    // Print server information
    printf("Server stopped\n");
}

int main() {
    // Create client and server
    struct client client;
    struct server server;

    // Create client
    create_client(&client);

    // Create server
    create_server(&server);

    // Receive message from client
    receive_message(&client);

    // Send message to client
    send_message(&client);

    // Close client socket
    close_client(&client);

    // Close server socket
    close_server(&server);

    return 0;
}