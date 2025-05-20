//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SMTP_PORT 25

int main(int argc, char** argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <port> <sender> <recipient>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) != 1) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Read the greeting message from the SMTP server
    char buffer[1024];
    int n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        perror("recv");
        exit(1);
    }

    // Send the HELO command to the SMTP server
    snprintf(buffer, sizeof(buffer), "HELO %s\r\n", argv[0]);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Read the response from the SMTP server
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        perror("recv");
        exit(1);
    }

    // Send the MAIL FROM command to the SMTP server
    snprintf(buffer, sizeof(buffer), "MAIL FROM: %s\r\n", argv[3]);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Read the response from the SMTP server
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        perror("recv");
        exit(1);
    }

    // Send the RCPT TO command to the SMTP server
    snprintf(buffer, sizeof(buffer), "RCPT TO: %s\r\n", argv[4]);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Read the response from the SMTP server
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        perror("recv");
        exit(1);
    }

    // Send the DATA command to the SMTP server
    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Read the response from the SMTP server
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        perror("recv");
        exit(1);
    }

    // Send the email message to the SMTP server
    FILE* fp = fopen("email.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
            perror("send");
            exit(1);
        }
    }

    fclose(fp);

    // Send the . command to the SMTP server to indicate the end of the email message
    snprintf(buffer, sizeof(buffer), ".\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Read the response from the SMTP server
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n <= 0) {
        perror("recv");
        exit(1);
    }

    // Send the QUIT command to the SMTP server
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}