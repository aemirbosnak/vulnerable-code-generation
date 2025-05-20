//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXLINE 1024
#define SERV_PORT 25

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(EXIT_FAILURE);
    }

    char buffer[MAXLINE];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    int n = recv(sockfd, buffer, MAXLINE, 0);
    if (n < 0) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buffer[n] = 0;
    printf("%s", buffer);

    char *helo = "HELO client\r\n";
    if (send(sockfd, helo, strlen(helo), 0) != strlen(helo)) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    n = recv(sockfd, buffer, MAXLINE, 0);
    if (n < 0) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buffer[n] = 0;
    printf("%s", buffer);

    char *mail_from = "MAIL FROM:<sender@example.com>\r\n";
    if (send(sockfd, mail_from, strlen(mail_from), 0) != strlen(mail_from)) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    n = recv(sockfd, buffer, MAXLINE, 0);
    if (n < 0) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buffer[n] = 0;
    printf("%s", buffer);

    char *rcpt_to = "RCPT TO:<recipient@example.com>\r\n";
    if (send(sockfd, rcpt_to, strlen(rcpt_to), 0) != strlen(rcpt_to)) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    n = recv(sockfd, buffer, MAXLINE, 0);
    if (n < 0) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buffer[n] = 0;
    printf("%s", buffer);

    char *data = "DATA\r\n";
    if (send(sockfd, data, strlen(data), 0) != strlen(data)) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    n = recv(sockfd, buffer, MAXLINE, 0);
    if (n < 0) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buffer[n] = 0;
    printf("%s", buffer);

    char *message = "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test\r\n\r\nThis is a test message sent from the client\r\n.\r\n";
    if (send(sockfd, message, strlen(message), 0) != strlen(message)) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    n = recv(sockfd, buffer, MAXLINE, 0);
    if (n < 0) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buffer[n] = 0;
    printf("%s", buffer);

    char *quit = "QUIT\r\n";
    if (send(sockfd, quit, strlen(quit), 0) != strlen(quit)) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    n = recv(sockfd, buffer, MAXLINE, 0);
    if (n < 0) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    buffer[n] = 0;
    printf("%s", buffer);

    close(sockfd);

    return(EXIT_SUCCESS);
}