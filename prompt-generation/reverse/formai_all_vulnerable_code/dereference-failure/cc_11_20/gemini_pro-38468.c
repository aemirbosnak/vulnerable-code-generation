//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <server> <from> <to> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *server = argv[1];
    char *from = argv[2];
    char *to = argv[3];
    char *message = argv[4];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char buffer[1024];

    // Read the greeting
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the HELO command
    snprintf(buffer, sizeof(buffer), "HELO %s\r\n", server);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", from);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", to);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the DATA command
    if (send(sockfd, "DATA\r\n", 6, 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the message
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Send the dot to indicate the end of the message
    if (send(sockfd, ".\r\n", 3, 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the QUIT command
    if (send(sockfd, "QUIT\r\n", 6, 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    close(sockfd);

    return EXIT_SUCCESS;
}