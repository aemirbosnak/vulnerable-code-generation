//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Socket defines
#define SERVER_PORT 8080
#define SERVER_ADDR "127.0.0.1"
#define MAX_BUFFER 1024

// Client function
void client() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);
    servaddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    char *msg = "Hello from the client!";
    if (send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    // Receive a message from the server
    char buffer[MAX_BUFFER];
    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }

    // Print the message from the server
    printf("Message from server: %s\n", buffer);

    // Close the socket
    close(sockfd);
}

// Server function
void server() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to the address and port
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept an incoming connection
    struct sockaddr_in cliaddr;
    int addrlen = sizeof(cliaddr);
    int newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &addrlen);
    if (newsockfd < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Receive a message from the client
    char buffer[MAX_BUFFER];
    if (recv(newsockfd, buffer, MAX_BUFFER, 0) < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }

    // Print the message from the client
    printf("Message from client: %s\n", buffer);

    // Send a message to the client
    char *msg = "Hello from the server!";
    if (send(newsockfd, msg, strlen(msg), 0) < 0) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(newsockfd);
    close(sockfd);
}

// Main function
int main() {
    // Choose whether to run as a client or server
    char choice;
    printf("Do you want to run as a client (c) or server (s)? ");
    scanf(" %c", &choice);

    // Run the appropriate function
    switch (choice) {
        case 'c':
            client();
            break;
        case 's':
            server();
            break;
        default:
            printf("Invalid choice. Please choose 'c' for client or 's' for server.\n");
    }

    return 0;
}