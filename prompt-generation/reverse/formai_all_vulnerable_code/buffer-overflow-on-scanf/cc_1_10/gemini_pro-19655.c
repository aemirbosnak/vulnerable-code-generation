//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

// Define the server's address and port
#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 5000

// Define the maximum size of the message that can be sent or received
#define MAX_MESSAGE_SIZE 1024

// Create a new socket for communication
int create_socket() {
    int sockfd;

    // Create a new socket using the IPv4 protocol and the TCP transport protocol
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Check if the socket was successfully created
    if (sockfd == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    return sockfd;
}

// Connect to the server using the specified address and port
int connect_to_server(int sockfd) {
    struct sockaddr_in server_address;

    // Set the server's address and port
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Failed to connect to server");
        exit(1);
    }

    return 0;
}

// Send a message to the server
int send_message(int sockfd, char *message) {
    int bytes_sent;

    // Send the message to the server
    bytes_sent = send(sockfd, message, strlen(message), 0);

    // Check if the message was successfully sent
    if (bytes_sent == -1) {
        perror("Failed to send message");
        exit(1);
    }

    return bytes_sent;
}

// Receive a message from the server
int receive_message(int sockfd, char *message) {
    int bytes_received;

    // Receive a message from the server
    bytes_received = recv(sockfd, message, MAX_MESSAGE_SIZE, 0);

    // Check if the message was successfully received
    if (bytes_received == -1) {
        perror("Failed to receive message");
        exit(1);
    }

    return bytes_received;
}

// Close the socket
int close_socket(int sockfd) {
    // Close the socket
    if (close(sockfd) == -1) {
        perror("Failed to close socket");
        exit(1);
    }

    return 0;
}

// Main function
int main() {
    int sockfd;
    char message[MAX_MESSAGE_SIZE];

    // Create a new socket
    sockfd = create_socket();

    // Connect to the server
    connect_to_server(sockfd);

    // Send a message to the server
    printf("Enter a message to send to the server: ");
    scanf("%s", message);
    send_message(sockfd, message);

    // Receive a message from the server
    receive_message(sockfd, message);
    printf("Received message from server: %s\n", message);

    // Close the socket
    close_socket(sockfd);

    return 0;
}