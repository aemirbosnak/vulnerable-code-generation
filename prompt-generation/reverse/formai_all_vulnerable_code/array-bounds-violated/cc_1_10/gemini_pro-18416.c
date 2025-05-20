//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Define the port number for the server
#define PORT 8080

// Define the maximum size of the buffer for the incoming message
#define MAX_BUFFER_SIZE 1024

// Create a socket and bind it to the specified port
int create_and_bind_socket(int port) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the specified port
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Listen for incoming connections on the specified socket
void listen_for_connections(int sockfd) {
    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("Error listening for connections");
        exit(EXIT_FAILURE);
    }
}

// Accept an incoming connection on the specified socket
int accept_connection(int sockfd) {
    // Accept an incoming connection
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    int clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (clientfd == -1) {
        perror("Error accepting connection");
        exit(EXIT_FAILURE);
    }

    return clientfd;
}

// Receive a message from the specified socket
char *receive_message(int sockfd) {
    // Create a buffer for the incoming message
    char buffer[MAX_BUFFER_SIZE];

    // Receive a message from the socket
    int bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error receiving message");
        exit(EXIT_FAILURE);
    }

    // Terminate the buffer with a null character
    buffer[bytes_received] = '\0';

    // Return the received message
    return strdup(buffer);
}

// Send a message to the specified socket
void send_message(int sockfd, char *message) {
    // Send the message to the socket
    int bytes_sent = send(sockfd, message, strlen(message), 0);
    if (bytes_sent == -1) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }
}

// Close the specified socket
void close_socket(int sockfd) {
    // Close the socket
    if (close(sockfd) == -1) {
        perror("Error closing socket");
        exit(EXIT_FAILURE);
    }
}

// Main function
int main() {
    // Create a socket and bind it to the specified port
    int server_sockfd = create_and_bind_socket(PORT);

    // Listen for incoming connections on the socket
    listen_for_connections(server_sockfd);

    // Accept an incoming connection on the socket
    int client_sockfd = accept_connection(server_sockfd);

    // Receive a message from the client
    char *message = receive_message(client_sockfd);

    // Print the received message
    printf("Received message: %s\n", message);

    // Send a message to the client
    send_message(client_sockfd, "Hello from the server!");

    // Close the client socket
    close_socket(client_sockfd);

    // Close the server socket
    close_socket(server_sockfd);

    // Free the allocated memory for the received message
    free(message);

    return 0;
}