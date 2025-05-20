//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: ultraprecise
/*
SMTP Client Example Program
Author: AI Bot
Description: This program allows the user to send emails through the SMTP protocol using the client socket. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_ADDR "smtp.gmail.com" // SMTP Server address
#define SERVER_PORT 587 // SMTP default port
#define BUF_SIZE 1024 // Maximum buffer size

int main() {
    int sockfd; // Socket file descriptor
    char buffer[BUF_SIZE] = {0}; //Buffer to store server response

    struct sockaddr_in servaddr; //Socket address structure for server
    memset(&servaddr, 0, sizeof(servaddr)); //Clear the structure

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set server address parameters
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, SERVER_ADDR, &servaddr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Wait for server response
    if (read(sockfd, buffer, BUF_SIZE) < 0) {
        perror("Read error");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer); // Print server response

    // Send HELO command to server
    sprintf(buffer, "HELO localhost\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for server response
    if (read(sockfd, buffer, BUF_SIZE) < 0) {
        perror("Read error");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer); // Print server response

    // Send MAIL FROM command to server
    sprintf(buffer, "MAIL FROM:<sender@gmail.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for server response
    if (read(sockfd, buffer, BUF_SIZE) < 0) {
        perror("Read error");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer); // Print server response

    // Send RCPT TO command to server
    sprintf(buffer, "RCPT TO:<receiver@gmail.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for server response
    if (read(sockfd, buffer, BUF_SIZE) < 0) {
        perror("Read error");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer); // Print server response

    // Send DATA command to server
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for server response
    if (read(sockfd, buffer, BUF_SIZE) < 0) {
        perror("Read error");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer); // Print server response

    // Send email content to server
    sprintf(buffer, "Subject: SMTP Client Example\r\nFrom: sender@gmail.com\r\nTo: receiver@gmail.com\r\n\r\nThis is a test email sent from a C program using SMTP protocol.\r\n.\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for server response
    if (read(sockfd, buffer, BUF_SIZE) < 0) {
        perror("Read error");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer); // Print server response

    // Send QUIT command to server
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for server response
    if (read(sockfd, buffer, BUF_SIZE) < 0) {
        perror("Read error");
        exit(EXIT_FAILURE);
    }

    printf("%s\n", buffer); // Print server response

    // Close socket
    close(sockfd);

    return 0; // Program completed successfully
}