//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 25
#define BUFFER_SIZE 1024

void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void sendSMTPCommand(int sockfd, const char *command) {
    char buffer[BUFFER_SIZE];

    // Send command to server
    if (send(sockfd, command, strlen(command), 0) < 0) {
        handleError("Failed to send command");
    }

    // Receive server response
    int bytesReceived = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytesReceived < 0) {
        handleError("Failed to receive response");
    }
    buffer[bytesReceived] = '\0'; // Null-terminate the string
    printf("Server Response: %s\n", buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in serverAddr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handleError("Socket creation failed");
    }

    // Specify server address
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change as necessary

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        handleError("Connection to server failed");
    }

    // Get SMTP server greeting
    char buffer[BUFFER_SIZE];
    int bytesReceived = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytesReceived < 0) {
        handleError("Failed to receive greeting");
    }
    buffer[bytesReceived] = '\0';
    printf("Welcome Message: %s\n", buffer);

    // Sending EHLO command
    sendSMTPCommand(sockfd, "EHLO localhost\r\n");

    // SMTP Authentication
    sendSMTPCommand(sockfd, "AUTH LOGIN\r\n");
    sendSMTPCommand(sockfd, "YOUR_BASE64_ENCODED_USERNAME\r\n");
    sendSMTPCommand(sockfd, "YOUR_BASE64_ENCODED_PASSWORD\r\n");

    // Specify mail sender
    sendSMTPCommand(sockfd, "MAIL FROM:<youremail@example.com>\r\n");

    // Specify recipient
    sendSMTPCommand(sockfd, "RCPT TO:<recipient@example.com>\r\n");

    // Send DATA command
    sendSMTPCommand(sockfd, "DATA\r\n");

    // Send email details
    const char *emailBody = "Subject: Test Email\r\n\r\nHello, this is a test email sent using a C SMTP client!\r\n.\r\n";
    if (send(sockfd, emailBody, strlen(emailBody), 0) < 0) {
        handleError("Failed to send email body");
    }

    // End of DATA command
    int finalResponseBytes = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (finalResponseBytes < 0) {
        handleError("Failed to receive response after sending DATA");
    }
    buffer[finalResponseBytes] = '\0';
    printf("Server Response: %s\n", buffer);

    // Send QUIT command
    sendSMTPCommand(sockfd, "QUIT\r\n");

    // Close the socket
    close(sockfd);
    printf("Connection closed. Email sent successfully!\n");

    return 0;
}