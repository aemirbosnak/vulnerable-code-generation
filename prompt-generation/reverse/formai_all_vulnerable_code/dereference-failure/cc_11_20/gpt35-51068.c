//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd, port;
    struct sockaddr_in server_addr;
    char buffer[MAX_LINE], command[MAX_LINE];

    if (argc != 3) {
        printf("Usage: %s <ipaddress> <port>\n", argv[0]);
        exit(1);
    }

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect error");
        exit(1);
    }

    // Receive greeting from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
        perror("recv error");
        exit(1);
    }
    printf("%s", buffer);

    // Send EHLO command to server
    sprintf(command, "EHLO client.example.com\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("send error");
        exit(1);
    }
    printf("%s", command);

    // Receive response from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
        perror("recv error");
        exit(1);
    }
    printf("%s", buffer);

    // Send MAIL FROM command to server
    sprintf(command, "MAIL FROM: <sender@example.com>\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("send error");
        exit(1);
    }
    printf("%s", command);

    // Receive response from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
        perror("recv error");
        exit(1);
    }
    printf("%s", buffer);

    // Send RCPT TO command to server
    sprintf(command, "RCPT TO: <recipient@example.com>\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("send error");
        exit(1);
    }
    printf("%s", command);

    // Receive response from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
        perror("recv error");
        exit(1);
    }
    printf("%s", buffer);

    // Send DATA command to server
    sprintf(command, "DATA\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("send error");
        exit(1);
    }
    printf("%s", command);

    // Receive response from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
        perror("recv error");
        exit(1);
    }
    printf("%s", buffer);

    // Send message to server
    sprintf(command, "Subject: SMTP Example\r\n\r\nHello, this is an example email.\r\n.\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("send error");
        exit(1);
    }
    printf("%s", command);

    // Receive response from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
        perror("recv error");
        exit(1);
    }
    printf("%s", buffer);

    // Send QUIT command to server
    sprintf(command, "QUIT\r\n");
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("send error");
        exit(1);
    }
    printf("%s", command);

    // Receive response from server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
        perror("recv error");
        exit(1);
    }
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}