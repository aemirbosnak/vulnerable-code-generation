//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024

int main(int argc, char **argv) {
    int sockfd;
    char buffer[MAX_BUFFER];
    struct sockaddr_in servaddr;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server address> <server port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket for outgoing connection
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Prepare server address structure
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid server address\n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Receive server greeting
    memset(buffer, 0, MAX_BUFFER);
    if (recv(sockfd, buffer, MAX_BUFFER - 1, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send HELO command
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive response to HELO command
    memset(buffer, 0, MAX_BUFFER);
    if (recv(sockfd, buffer, MAX_BUFFER - 1, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send MAIL FROM command
    printf("From: ");
    scanf("%s", buffer);
    sprintf(buffer, "MAIL FROM:<%s>\r\n", buffer);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive response to MAIL FROM command
    memset(buffer, 0, MAX_BUFFER);
    if (recv(sockfd, buffer, MAX_BUFFER - 1, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send RCPT TO command
    printf("To: ");
    scanf("%s", buffer);
    sprintf(buffer, "RCPT TO:<%s>\r\n", buffer);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive response to RCPT TO command
    memset(buffer, 0, MAX_BUFFER);
    if (recv(sockfd, buffer, MAX_BUFFER - 1, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send DATA command
    sprintf(buffer, "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive response to DATA command
    memset(buffer, 0, MAX_BUFFER);
    if (recv(sockfd, buffer, MAX_BUFFER - 1, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send message body
    printf("Type message. End with a single line containing only a period: \n");
    while (fgets(buffer, MAX_BUFFER - 1, stdin)) {
        if (strlen(buffer) > 2 && buffer[0] == '.' && buffer[1] == '\n') {
            break;
        }
        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("send");
            exit(EXIT_FAILURE);
        }
    }

    // Send end of message marker
    sprintf(buffer, ".\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive response to message
    memset(buffer, 0, MAX_BUFFER);
    if (recv(sockfd, buffer, MAX_BUFFER - 1, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive response to QUIT command
    memset(buffer, 0, MAX_BUFFER);
    if (recv(sockfd, buffer, MAX_BUFFER - 1, 0) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}