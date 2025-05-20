//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 25
#define MAX_LINE_LENGTH 1024

// A simple SMTP client that sends an email message.
int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <sender_email> <recipient_email> <subject> <message_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create a socket and connect to the SMTP server.
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Read the welcome message from the SMTP server.
    char buf[MAX_LINE_LENGTH];
    memset(buf, 0, MAX_LINE_LENGTH);
    if (recv(sockfd, buf, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the HELO command to the SMTP server.
    snprintf(buf, MAX_LINE_LENGTH, "HELO %s\r\n", argv[0]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    memset(buf, 0, MAX_LINE_LENGTH);
    if (recv(sockfd, buf, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command to the SMTP server.
    snprintf(buf, MAX_LINE_LENGTH, "MAIL FROM: %s\r\n", argv[1]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    memset(buf, 0, MAX_LINE_LENGTH);
    if (recv(sockfd, buf, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command to the SMTP server.
    snprintf(buf, MAX_LINE_LENGTH, "RCPT TO: %s\r\n", argv[2]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    memset(buf, 0, MAX_LINE_LENGTH);
    if (recv(sockfd, buf, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the DATA command to the SMTP server.
    snprintf(buf, MAX_LINE_LENGTH, "DATA\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    memset(buf, 0, MAX_LINE_LENGTH);
    if (recv(sockfd, buf, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the email message to the SMTP server.
    FILE *fp;
    fp = fopen(argv[4], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    while (fgets(buf, MAX_LINE_LENGTH, fp) != NULL) {
        if (send(sockfd, buf, strlen(buf), 0) == -1) {
            perror("send");
            return EXIT_FAILURE;
        }
    }

    fclose(fp);

    // Send the dot (.) command to the SMTP server to indicate the end of the email message.
    snprintf(buf, MAX_LINE_LENGTH, ".\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    memset(buf, 0, MAX_LINE_LENGTH);
    if (recv(sockfd, buf, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the QUIT command to the SMTP server.
    snprintf(buf, MAX_LINE_LENGTH, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}