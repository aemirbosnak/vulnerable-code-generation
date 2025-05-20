//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server IP address> <port number>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Say hello to the server
    if (write(sockfd, "HELO\n", 5) <= 0) {
        perror("write");
        exit(1);
    }

    // Receive the server's response
    if (read(sockfd, buffer, MAXLINE) <= 0) {
        perror("read");
        exit(1);
    }
    printf("%s", buffer);

    // Send the MAIL FROM command
    if (write(sockfd, "MAIL FROM: <test@example.com>\n", 31) <= 0) {
        perror("write");
        exit(1);
    }

    // Receive the server's response
    if (read(sockfd, buffer, MAXLINE) <= 0) {
        perror("read");
        exit(1);
    }
    printf("%s", buffer);

    // Send the RCPT TO command
    if (write(sockfd, "RCPT TO: <test2@example.com>\n", 30) <= 0) {
        perror("write");
        exit(1);
    }

    // Receive the server's response
    if (read(sockfd, buffer, MAXLINE) <= 0) {
        perror("read");
        exit(1);
    }
    printf("%s", buffer);

    // Send the DATA command
    if (write(sockfd, "DATA\n", 5) <= 0) {
        perror("write");
        exit(1);
    }

    // Receive the server's response
    if (read(sockfd, buffer, MAXLINE) <= 0) {
        perror("read");
        exit(1);
    }
    printf("%s", buffer);

    // Send the email body
    if (write(sockfd, "Subject: Test email\n\nThis is a test email.\n", 41) <= 0) {
        perror("write");
        exit(1);
    }

    // Send the . command to terminate the email body
    if (write(sockfd, ".\n", 2) <= 0) {
        perror("write");
        exit(1);
    }

    // Receive the server's response
    if (read(sockfd, buffer, MAXLINE) <= 0) {
        perror("read");
        exit(1);
    }
    printf("%s", buffer);

    // Send the QUIT command
    if (write(sockfd, "QUIT\n", 5) <= 0) {
        perror("write");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}