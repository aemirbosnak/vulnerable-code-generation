//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Client code
void client() {
    int client_socket;
    struct sockaddr_in server_address;
    char buffer[1024];

    // Create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send data to server
    strcpy(buffer, "Hello from client");
    send(client_socket, buffer, strlen(buffer), 0);

    // Receive data from server
    recv(client_socket, buffer, sizeof(buffer), 0);

    // Print data received from server
    printf("Received from server: %s\n", buffer);

    // Close the socket
    close(client_socket);
}

// Server code
void server() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length;
    char buffer[1024];

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    // Accept incoming connection
    client_address_length = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
    if (client_socket < 0) {
        perror("Error accepting connection");
        exit(1);
    }

    // Receive data from client
    recv(client_socket, buffer, sizeof(buffer), 0);

    // Print data received from client
    printf("Received from client: %s\n", buffer);

    // Send data to client
    strcpy(buffer, "Hello from server");
    send(client_socket, buffer, strlen(buffer), 0);

    // Close the socket
    close(client_socket);
}

int main() {
    // Determine whether to run as client or server
    char role;
    printf("Enter your role (c for client, s for server): ");
    scanf(" %c", &role);

    // Run the corresponding function
    switch (role) {
        case 'c':
            client();
            break;
        case 's':
            server();
            break;
        default:
            printf("Invalid role entered\n");
            break;
    }

    return 0;
}