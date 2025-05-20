//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 110
#define BUFFER_SIZE 1024

void handleResponse(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytesRead;

    // Reading response from the server
    while ((bytesRead = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytesRead] = '\0'; // Null terminate
        printf("%s", buffer);
    }
}

void sendCommand(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    // Wait for response
    handleResponse(sockfd);
}

int main() {
    int sockfd;
    struct sockaddr_in serverAddr;
    const char *hostname = "your.pop3.server"; // Replace with your POP3 server
    const char *username = "yourusername";      // Replace with your username
    const char *password = "yourpassword";      // Replace with your password

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with the server's IP

    // Connect to the POP3 server
    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Welcome message from server
    handleResponse(sockfd);

    // Send USER command
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "USER %s\r\n", username);
    sendCommand(sockfd, command);

    // Send PASS command
    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    sendCommand(sockfd, command);

    // Checking mailbox size with STAT command
    sendCommand(sockfd, "STAT\r\n");

    // Listing the messages
    sendCommand(sockfd, "LIST\r\n");

    // Retrieving the first message
    snprintf(command, sizeof(command), "RETR 1\r\n");
    sendCommand(sockfd, command);

    // Quit command
    sendCommand(sockfd, "QUIT\r\n");

    // Close the socket
    close(sockfd);
    
    printf("Disconnected from server. Goodbye!\n");
    return 0;
}