//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 1234

// Function to create a new TCP/IP socket
int create_socket(int port) {
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Function to bind a socket to a port
void bind_socket(int sockfd, char *ip_address, int port) {
    struct sockaddr_in server_address;

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip_address);
    server_address.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("ERROR on binding");
        exit(EXIT_FAILURE);
    }
}

// Function to listen for incoming connections
void listen_for_connections(int sockfd, int backlog) {
    if (listen(sockfd, backlog) < 0) {
        perror("ERROR on listening");
        exit(EXIT_FAILURE);
    }
}

// Function to accept an incoming connection
int accept_connection(int sockfd) {
    int new_socket;
    struct sockaddr_in client_address;
    socklen_t client_length = sizeof(client_address);

    new_socket = accept(sockfd, (struct sockaddr *) &client_address, &client_length);
    if (new_socket < 0) {
        perror("ERROR on accept");
        exit(EXIT_FAILURE);
    }
    return new_socket;
}

// Function to send a message to the client
void send_message(int sockfd, char *message) {
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("ERROR on sending message");
        exit(EXIT_FAILURE);
    }
}

// Function to receive a message from the client
char *receive_message(int sockfd) {
    char buffer[1024];
    int n = 0;

    while (1) {
        n = recv(sockfd, buffer, 1024, 0);
        if (n < 0) {
            perror("ERROR on receiving message");
            exit(EXIT_FAILURE);
        }
        if (n == 0) {
            break;
        }
        buffer[n] = '\0';
        return buffer;
    }
    return NULL;
}

// Function to close the socket
void close_socket(int sockfd) {
    close(sockfd);
}

// Main function
int main() {
    int sockfd, new_socket, n;
    char buffer[1024];

    // Create a socket
    sockfd = create_socket(PORT);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the port
    bind_socket(sockfd, "127.0.0.1", PORT);

    // Listen for connections
    listen_for_connections(sockfd, 5);

    // Accept the first connection
    new_socket = accept_connection(sockfd);
    if (new_socket < 0) {
        perror("ERROR on accept");
        exit(EXIT_FAILURE);
    }

    // Receive the message from the client
    n = receive_message(new_socket);
    printf("Client message: %s\n", n);

    // Send a message to the client
    send_message(new_socket, "Server message: Hello, client!");

    // Close the socket
    close_socket(new_socket);

    return 0;
}