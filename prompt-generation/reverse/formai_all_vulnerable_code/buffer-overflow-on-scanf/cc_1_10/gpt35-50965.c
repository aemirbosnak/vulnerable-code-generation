//FormAI DATASET v1.0 Category: Client Server Application ; Style: multivariable
// This is a simple client-server program that lets the client connect to the server and send a message
// The server receives the message and sends it back to the client
// Both the client and server programs will execute in parallel

// Required header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Constants
#define PORT 5000
#define BUFFER_SIZE 1024

// Function prototypes
void startServer();
void startClient();

int main(int argc, char **argv) {
    int choice;

    // Take user input on whether to start the server or the client
    printf("Enter 1 to start the server, 2 to start the client: ");
    scanf("%d", &choice);

    if (choice == 1)
        startServer();
    else if (choice == 2)
        startClient();
    else
        printf("Invalid choice. Please try again.\n");

    return 0;
}

void startServer() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t address_size;
    char buffer[BUFFER_SIZE];

    // Create a socket on the server side
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("ERROR: Could not create socket.\n");
        exit(1);
    }

    // Compose the server address
    memset(&server_address, '\0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("ERROR: Could not bind socket to server address.\n");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        printf("ERROR: Could not listen for incoming connections.\n");
        exit(1);
    }

    printf("Server started. Waiting for incoming connections...\n");

    // Accept incoming connection requests
    address_size = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *) &client_address, &address_size);
    if (client_socket < 0) {
        printf("ERROR: Could not accept incoming connection.\n");
        exit(1);
    }

    printf("Client connected. Waiting for message...\n");

    // Receive message from client
    memset(buffer, '\0', BUFFER_SIZE);
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        printf("ERROR: Could not receive message from client.\n");
        exit(1);
    }

    printf("Received message from client: %s\n", buffer);

    // Send message back to client
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        printf("ERROR: Could not send message back to client.\n");
        exit(1);
    }

    // Close sockets
    close(client_socket);
    close(server_socket);
}

void startClient() {
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];

    // Create a socket on the client side
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        printf("ERROR: Could not create socket.\n");
        exit(1);
    }

    // Compose the server address
    memset(&server_address, '\0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(PORT);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("ERROR: Could not connect to server.\n");
        exit(1);
    }

    printf("Connected to server. Enter message to send: ");
    memset(buffer, '\0', BUFFER_SIZE);
    fgets(buffer, BUFFER_SIZE, stdin);

    // Send message to server
    if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
        printf("ERROR: Could not send message to server.\n");
        exit(1);
    }

    // Receive message from server
    memset(buffer, '\0', BUFFER_SIZE);
    if (recv(client_socket, buffer, BUFFER_SIZE, 0) < 0) {
        printf("ERROR: Could not receive message from server.\n");
        exit(1);
    }

    printf("Received message from server: %s\n", buffer);

    // Close socket
    close(client_socket);
}