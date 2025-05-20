//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// Socket constants
#define SERVER_PORT 8080 // A bustling port for our server
#define MAX_MESSAGE_SIZE 1024 // Ample space for our messages

// Server magic
void server() {
    // Initialize our server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind our server to the port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Get ready to listen for clients
    if (listen(server_socket, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Endless loop for serving clients
    while (1) {
        // Accept incoming connections
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        // Read from the client
        char message[MAX_MESSAGE_SIZE];
        memset(message, 0, sizeof(message));
        if (read(client_socket, message, MAX_MESSAGE_SIZE) < 0) {
            perror("read");
            close(client_socket);
            continue;
        }

        // Modify the message with a touch of servidor magic
        int message_length = strlen(message);
        for (int i = 0; i < message_length; i++) {
            message[i] = toupper(message[i]);
        }

        // Send the modified message back to the client
        if (write(client_socket, message, message_length) < 0) {
            perror("write");
            close(client_socket);
            continue;
        }

        // Bid farewell to the client
        close(client_socket);
    }

    // Close the socket
    close(server_socket);
}

// Client charm
void client() {
    // Create a socket to connect to the server
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(SERVER_PORT);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    char message[] = "Greetings from the client!";
    if (write(client_socket, message, strlen(message)) < 0) {
        perror("write");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // Read the modified message from the server
    char server_message[MAX_MESSAGE_SIZE];
    memset(server_message, 0, sizeof(server_message));
    if (read(client_socket, server_message, MAX_MESSAGE_SIZE) < 0) {
        perror("read");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    // Display the modified message
    printf("Server response: %s\n", server_message);

    // Close the socket
    close(client_socket);
}

// The grand finale
int main() {
    // Decide whether to run as server or client
    int role;
    printf("Choose your destiny:\n1. Server\n2. Client\n");
    scanf("%d", &role);

    // Unleash the magic
    switch (role) {
        case 1:
            server();
            break;
        case 2:
            client();
            break;
        default:
            printf("Invalid role. Try again!\n");
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}