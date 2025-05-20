//MISTRAL-7B DATASET v1.0 Category: TCP/IP Programming ; Style: peaceful
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define SERVER_ADDRESS "127.0.0.1"

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    // Initialize socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &serv_addr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server.\n");

    // Send a message to the server
    const char *message = "Hello, peaceful server!";
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("Error sending message");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("Message sent to server.\n");

    // Receive a response from the server
    ssize_t received_bytes;
    while ((received_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[received_bytes] = '\0';
        printf("Received data: %s\n", buffer);
    }
    if (received_bytes < 0) {
        perror("Error receiving data");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Disconnected from server.\n");

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}