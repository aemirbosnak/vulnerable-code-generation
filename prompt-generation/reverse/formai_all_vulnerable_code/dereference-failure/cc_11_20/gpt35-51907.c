//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(int argc, char **argv) {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    if (argc != 3) {
        printf("usage: %s <IP address> <Port>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(1);
    }

    printf("220 Welcome to SMTP Server\n");
    char hello[] = "HELO example.com\r\n";
    if (write(sockfd, hello, strlen(hello)) < 0) {
        perror("write error");
        exit(1);
    }

    n = read(sockfd, recvline, MAXLINE);
    if (n < 0) {
        perror("read error");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    char mail_from[] = "MAIL FROM: <user@example.com>\r\n";
    if (write(sockfd, mail_from, strlen(mail_from)) < 0) {
        perror("write error");
        exit(1);
    }

    n = read(sockfd, recvline, MAXLINE);
    if (n < 0) {
        perror("read error");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    char rcpt_to[] = "RCPT TO: <target@example.com>\r\n";
    if (write(sockfd, rcpt_to, strlen(rcpt_to)) < 0) {
        perror("write error");
        exit(1);
    }

    n = read(sockfd, recvline, MAXLINE);
    if (n < 0) {
        perror("read error");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    char data[] = "DATA\r\n";
    if (write(sockfd, data, strlen(data)) < 0) {
        perror("write error");
        exit(1);
    }

    n = read(sockfd, recvline, MAXLINE);
    if (n < 0) {
        perror("read error");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    char message[] = "Subject: Test Email\n\nThis is a test email from SMTP client.\n.\r\n";
    if (write(sockfd, message, strlen(message)) < 0) {
        perror("write error");
        exit(1);
    }

    n = read(sockfd, recvline, MAXLINE);
    if (n < 0) {
        perror("read error");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    char quit[] = "QUIT\r\n";
    if (write(sockfd, quit, strlen(quit)) < 0) {
        perror("write error");
        exit(1);
    }

    n = read(sockfd, recvline, MAXLINE);
    if (n < 0) {
        perror("read error");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    close(sockfd);
    return 0;
}