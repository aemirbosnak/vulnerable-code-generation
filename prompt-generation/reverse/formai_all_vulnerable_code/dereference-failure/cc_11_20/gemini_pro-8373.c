//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <port> <message>\n", argv[0]);
        exit(1);
    }

    char *server = argv[1];
    int port = atoi(argv[2]);
    char *message = argv[3];

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(server);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send HELO
    char buf[BUF_SIZE];
    sprintf(buf, "HELO %s\r\n", server);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive greeting
    if (recv(sockfd, buf, BUF_SIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Send MAIL FROM
    sprintf(buf, "MAIL FROM: <sender@example.com>\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive OK
    if (recv(sockfd, buf, BUF_SIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Send RCPT TO
    sprintf(buf, "RCPT TO: <recipient@example.com>\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive OK
    if (recv(sockfd, buf, BUF_SIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Send DATA
    sprintf(buf, "DATA\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive 354
    if (recv(sockfd, buf, BUF_SIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Send message
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Send dot
    sprintf(buf, ".\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive OK
    if (recv(sockfd, buf, BUF_SIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Send QUIT
    sprintf(buf, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive OK
    if (recv(sockfd, buf, BUF_SIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }

    close(sockfd);

    return 0;
}