//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the port number for the server
#define PORT 8080

// Create a socket for the server
int create_server_socket() {
    int server_socket;
    struct sockaddr_in server_address;

    // Create a socket for the server
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Could not bind socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Could not listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    return server_socket;
}

// Create a socket for the client
int create_client_socket() {
    int client_socket;
    struct sockaddr_in server_address;

    // Create a socket for the client
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(PORT);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Could not connect to server");
        exit(EXIT_FAILURE);
    }

    return client_socket;
}

// Send a message to the server
void send_message(int socket, char *message) {
    int length = strlen(message);

    // Send the length of the message
    if (send(socket, &length, sizeof(length), 0) == -1) {
        perror("Could not send message length");
        exit(EXIT_FAILURE);
    }

    // Send the message
    if (send(socket, message, length, 0) == -1) {
        perror("Could not send message");
        exit(EXIT_FAILURE);
    }
}

// Receive a message from the server
char *receive_message(int socket) {
    int length;

    // Receive the length of the message
    if (recv(socket, &length, sizeof(length), 0) == -1) {
        perror("Could not receive message length");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the message
    char *message = malloc(length + 1);
    if (message == NULL) {
        perror("Could not allocate memory for message");
        exit(EXIT_FAILURE);
    }

    // Receive the message
    if (recv(socket, message, length, 0) == -1) {
        perror("Could not receive message");
        exit(EXIT_FAILURE);
    }

    // Terminate the message with a null character
    message[length] = '\0';

    return message;
}

int main() {
    int server_socket, client_socket;
    char *message;

    // Create the server socket
    server_socket = create_server_socket();

    // Create the client socket
    client_socket = create_client_socket();

    // Receive a message from the client
    message = receive_message(client_socket);

    // Print the message
    printf("Received message: %s\n", message);

    // Send a message to the client
    send_message(client_socket, "Hello from the server!");

    // Close the client socket
    close(client_socket);

    // Close the server socket
    close(server_socket);

    return 0;
}