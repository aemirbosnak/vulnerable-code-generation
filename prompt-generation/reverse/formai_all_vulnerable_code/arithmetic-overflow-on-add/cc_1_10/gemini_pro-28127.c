//GEMINI-pro DATASET v1.0 Category: Networking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Defines the maximum length of the message that can be sent or received
#define MAX_MESSAGE_LENGTH 1024

// Creates a socket and returns the socket descriptor
int create_socket() {
    int socket_descriptor;

    // Creates a socket for IPv4, TCP, and stores the socket descriptor in socket_descriptor
    socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    // Checks if the socket was created successfully
    if (socket_descriptor == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    return socket_descriptor;
}

// Binds the socket to a specific IP address and port
void bind_socket(int socket_descriptor, char *ip_address, int port) {
    struct sockaddr_in server_address;

    // Initializes the server_address structure with zeros
    memset(&server_address, 0, sizeof(server_address));

    // Sets the server_address family to IPv4
    server_address.sin_family = AF_INET;

    // Sets the server_address IP address
    server_address.sin_addr.s_addr = inet_addr(ip_address);

    // Sets the server_address port
    server_address.sin_port = htons(port);

    // Binds the socket to the server_address
    if (bind(socket_descriptor, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }
}

// Listens for incoming connections on the socket
void listen_for_connections(int socket_descriptor) {
    // Sets the socket to listen for incoming connections
    if (listen(socket_descriptor, 5) == -1) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }
}

// Accepts an incoming connection on the socket and returns the socket descriptor for the new connection
int accept_connection(int socket_descriptor) {
    int new_socket_descriptor;
    struct sockaddr_in client_address;
    socklen_t client_address_length = sizeof(client_address);

    // Accepts an incoming connection and stores the socket descriptor for the new connection in new_socket_descriptor
    new_socket_descriptor = accept(socket_descriptor, (struct sockaddr *) &client_address, &client_address_length);

    // Checks if the connection was accepted successfully
    if (new_socket_descriptor == -1) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    return new_socket_descriptor;
}

// Sends a message to a client over a socket
void send_message(int socket_descriptor, char *message) {
    // Sends the message to the client over the socket
    if (send(socket_descriptor, message, strlen(message), 0) == -1) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }
}

// Receives a message from a client over a socket and returns the message
char *receive_message(int socket_descriptor) {
    char *message;
    int message_length;

    // Receives the message length from the client
    if (recv(socket_descriptor, &message_length, sizeof(int), 0) == -1) {
        perror("Error receiving message length");
        exit(EXIT_FAILURE);
    }

    // Allocates memory for the message
    message = malloc(message_length + 1);

    // Receives the message from the client
    if (recv(socket_descriptor, message, message_length, 0) == -1) {
        perror("Error receiving message");
        exit(EXIT_FAILURE);
    }

    // Null-terminates the message
    message[message_length] = '\0';

    return message;
}

// Closes a socket
void close_socket(int socket_descriptor) {
    // Closes the socket
    if (close(socket_descriptor) == -1) {
        perror("Error closing socket");
        exit(EXIT_FAILURE);
    }
}

// Main function
int main(int argc, char **argv) {
    int server_socket_descriptor, client_socket_descriptor;
    char *message;

    // Checks if the correct number of arguments are provided
    if (argc != 3) {
        printf("Usage: %s <ip address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Creates a socket
    server_socket_descriptor = create_socket();

    // Binds the socket to the specified IP address and port
    bind_socket(server_socket_descriptor, argv[1], atoi(argv[2]));

    // Listens for incoming connections
    listen_for_connections(server_socket_descriptor);

    // Accepts an incoming connection
    client_socket_descriptor = accept_connection(server_socket_descriptor);

    // Receives a message from the client
    message = receive_message(client_socket_descriptor);

    // Prints the received message
    printf("Received message: %s\n", message);

    // Sends a message to the client
    send_message(client_socket_descriptor, "Hello from the server!");

    // Closes the client socket
    close_socket(client_socket_descriptor);

    // Closes the server socket
    close_socket(server_socket_descriptor);

    return 0;
}