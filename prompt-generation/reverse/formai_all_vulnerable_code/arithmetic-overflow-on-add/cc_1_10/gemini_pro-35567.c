//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Function to send a message to the server
void send_message(int sockfd, char *message) {
    // Send the length of the message first
    int len = strlen(message);
    send(sockfd, &len, sizeof(int), 0);

    // Then send the message itself
    send(sockfd, message, len, 0);
}

// Function to receive a message from the server
char *receive_message(int sockfd) {
    // Receive the length of the message first
    int len;
    recv(sockfd, &len, sizeof(int), 0);

    // Allocate a buffer to store the message
    char *message = malloc(len + 1);

    // Receive the message itself
    recv(sockfd, message, len, 0);

    // Null-terminate the message
    message[len] = '\0';

    // Return the message
    return message;
}

// Main function
int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send a message to the server
    char *message = "Hello from the client!";
    send_message(sockfd, message);

    // Receive a message from the server
    char *response = receive_message(sockfd);

    // Print the response from the server
    printf("Response from the server: %s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}