//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define SMTP_PORT 25

int main(int argc, char *argv[])
{
    int sockfd, ret;
    struct sockaddr_in servaddr;
    char buffer[1024];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server IP address> <email address>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Initialize the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SMTP_PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Read the welcome message from the server
    ret = read(sockfd, buffer, sizeof(buffer));
    if (ret < 0) {
        perror("read");
        exit(1);
    }
    printf("Server: %s\n", buffer);

    // Send the HELO command
    sprintf(buffer, "HELO %s\r\n", argv[2]);
    ret = write(sockfd, buffer, strlen(buffer));
    if (ret < 0) {
        perror("write");
        exit(1);
    }

    // Read the response from the server
    ret = read(sockfd, buffer, sizeof(buffer));
    if (ret < 0) {
        perror("read");
        exit(1);
    }
    printf("Server: %s\n", buffer);

    // Send the MAIL FROM command
    sprintf(buffer, "MAIL FROM: %s\r\n", argv[2]);
    ret = write(sockfd, buffer, strlen(buffer));
    if (ret < 0) {
        perror("write");
        exit(1);
    }

    // Read the response from the server
    ret = read(sockfd, buffer, sizeof(buffer));
    if (ret < 0) {
        perror("read");
        exit(1);
    }
    printf("Server: %s\n", buffer);

    // Send the RCPT TO command
    sprintf(buffer, "RCPT TO: %s\r\n", argv[3]);
    ret = write(sockfd, buffer, strlen(buffer));
    if (ret < 0) {
        perror("write");
        exit(1);
    }

    // Read the response from the server
    ret = read(sockfd, buffer, sizeof(buffer));
    if (ret < 0) {
        perror("read");
        exit(1);
    }
    printf("Server: %s\n", buffer);

    // Send the DATA command
    sprintf(buffer, "DATA\r\n");
    ret = write(sockfd, buffer, strlen(buffer));
    if (ret < 0) {
        perror("write");
        exit(1);
    }

    // Read the response from the server
    ret = read(sockfd, buffer, sizeof(buffer));
    if (ret < 0) {
        perror("read");
        exit(1);
    }
    printf("Server: %s\n", buffer);

    // Send the email message
    sprintf(buffer, "From: %s\r\n", argv[2]);
    ret = write(sockfd, buffer, strlen(buffer));
    if (ret < 0) {
        perror("write");
        exit(1);
    }

    sprintf(buffer, "To: %s\r\n", argv[3]);
    ret = write(sockfd, buffer, strlen(buffer));
    if (ret < 0) {
        perror("write");
        exit(1);
    }

    sprintf(buffer, "Subject: %s\r\n", argv[4]);
    ret = write(sockfd, buffer, strlen(buffer));
    if (ret < 0) {
        perror("write");
        exit(1);
    }

    sprintf(buffer, "\r\n%s\r\n", argv[5]);
    ret = write(sockfd, buffer, strlen(buffer));
    if (ret < 0) {
        perror("write");
        exit(1);
    }

    // Send the QUIT command
    sprintf(buffer, "QUIT\r\n");
    ret = write(sockfd, buffer, strlen(buffer));
    if (ret < 0) {
        perror("write");
        exit(1);
    }

    // Read the response from the server
    ret = read(sockfd, buffer, sizeof(buffer));
    if (ret < 0) {
        perror("read");
        exit(1);
    }
    printf("Server: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}