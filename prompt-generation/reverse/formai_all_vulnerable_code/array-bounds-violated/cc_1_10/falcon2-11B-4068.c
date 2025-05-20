//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

// Function to send a message to a client
void send_message(int sockfd, char* message) {
    send(sockfd, message, strlen(message), 0);
}

// Function to receive a message from a client
char* receive_message(int sockfd) {
    char buffer[100];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        perror("Error receiving message");
        return NULL;
    }
    buffer[bytes_received] = '\0';
    return buffer;
}

// Main function
int main(int argc, char* argv[]) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Create a struct sockaddr_in to store server address information
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(5000); // Server port number
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Server IP address

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Error listening for connections");
        return 1;
    }

    // Accept a connection from a client
    int client_sockfd = accept(sockfd, NULL, NULL);
    if (client_sockfd < 0) {
        perror("Error accepting connection");
        return 1;
    }

    // Send a welcome message to the client
    send_message(client_sockfd, "Welcome to the chat server!");

    // Receive a message from the client
    char* message = receive_message(client_sockfd);
    if (message == NULL) {
        perror("Error receiving message");
        return 1;
    }

    // Print the received message
    printf("Received message: %s\n", message);

    // Send a response message to the client
    send_message(client_sockfd, "Thank you for connecting!");

    // Close the client socket
    close(client_sockfd);

    // Close the server socket
    close(sockfd);

    return 0;
}