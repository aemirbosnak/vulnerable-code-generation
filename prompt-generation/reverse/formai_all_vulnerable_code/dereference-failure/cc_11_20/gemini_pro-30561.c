//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char recvline[1024];

    if (argc != 5) {
        fprintf(stderr, "Usage: %s <server> <from> <to> <message>\n", argv[0]);
        return 1;
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Set up the server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SMTP_PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid server address: %s\n", argv[1]);
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return 1;
    }

    // Read the server's greeting
    if (recv(sockfd, recvline, sizeof(recvline), 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("Server greeting: %s\n", recvline);

    // Send the HELO command
    snprintf(recvline, sizeof(recvline), "HELO %s\r\n", argv[1]);
    if (send(sockfd, recvline, strlen(recvline), 0) == -1) {
        perror("send");
        return 1;
    }

    // Read the server's response
    if (recv(sockfd, recvline, sizeof(recvline), 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("Server response: %s\n", recvline);

    // Send the MAIL FROM command
    snprintf(recvline, sizeof(recvline), "MAIL FROM: %s\r\n", argv[2]);
    if (send(sockfd, recvline, strlen(recvline), 0) == -1) {
        perror("send");
        return 1;
    }

    // Read the server's response
    if (recv(sockfd, recvline, sizeof(recvline), 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("Server response: %s\n", recvline);

    // Send the RCPT TO command
    snprintf(recvline, sizeof(recvline), "RCPT TO: %s\r\n", argv[3]);
    if (send(sockfd, recvline, strlen(recvline), 0) == -1) {
        perror("send");
        return 1;
    }

    // Read the server's response
    if (recv(sockfd, recvline, sizeof(recvline), 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("Server response: %s\n", recvline);

    // Send the DATA command
    snprintf(recvline, sizeof(recvline), "DATA\r\n");
    if (send(sockfd, recvline, strlen(recvline), 0) == -1) {
        perror("send");
        return 1;
    }

    // Read the server's response
    if (recv(sockfd, recvline, sizeof(recvline), 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("Server response: %s\n", recvline);

    // Send the message
    if (send(sockfd, argv[4], strlen(argv[4]), 0) == -1) {
        perror("send");
        return 1;
    }

    // Send the dot command
    snprintf(recvline, sizeof(recvline), ".\r\n");
    if (send(sockfd, recvline, strlen(recvline), 0) == -1) {
        perror("send");
        return 1;
    }

    // Read the server's response
    if (recv(sockfd, recvline, sizeof(recvline), 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("Server response: %s\n", recvline);

    // Send the QUIT command
    snprintf(recvline, sizeof(recvline), "QUIT\r\n");
    if (send(sockfd, recvline, strlen(recvline), 0) == -1) {
        perror("send");
        return 1;
    }

    // Read the server's response
    if (recv(sockfd, recvline, sizeof(recvline), 0) == -1) {
        perror("recv");
        return 1;
    }
    printf("Server response: %s\n", recvline);

    // Close the socket
    close(sockfd);

    return 0;
}