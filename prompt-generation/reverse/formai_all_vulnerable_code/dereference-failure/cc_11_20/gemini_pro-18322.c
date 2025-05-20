//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// SMTP server address and port
#define SMTP_SERVER "smtp.example.com"
#define SMTP_PORT 587

// Email headers
#define FROM "sender@example.com"
#define TO "recipient@example.com"
#define SUBJECT "This is a test email"

// Email body
#define BODY "Hello, world!\n\nThis is a test email sent from a C program."

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SMTP_SERVER);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Read the greeting from the server
    char buf[1024];
    if (read(sockfd, buf, sizeof(buf)) < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Send the HELO command
    sprintf(buf, "HELO %s\r\n", "client.example.com");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Read the response from the server
    if (read(sockfd, buf, sizeof(buf)) < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Send the MAIL FROM command
    sprintf(buf, "MAIL FROM:<%s>\r\n", FROM);
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Read the response from the server
    if (read(sockfd, buf, sizeof(buf)) < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Send the RCPT TO command
    sprintf(buf, "RCPT TO:<%s>\r\n", TO);
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Read the response from the server
    if (read(sockfd, buf, sizeof(buf)) < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Send the DATA command
    sprintf(buf, "DATA\r\n");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Read the response from the server
    if (read(sockfd, buf, sizeof(buf)) < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Send the email headers and body
    sprintf(buf, "From: %s\r\n", FROM);
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    sprintf(buf, "To: %s\r\n", TO);
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    sprintf(buf, "Subject: %s\r\n", SUBJECT);
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    sprintf(buf, "%s\r\n", BODY);
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Send the end of the email
    sprintf(buf, ".\r\n");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Read the response from the server
    if (read(sockfd, buf, sizeof(buf)) < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Send the QUIT command
    sprintf(buf, "QUIT\r\n");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Read the response from the server
    if (read(sockfd, buf, sizeof(buf)) < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("%s", buf);

    // Close the socket
    close(sockfd);

    return 0;
}