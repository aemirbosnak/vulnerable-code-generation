//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char **argv)
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[1024];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <recipient>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SMTP_PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1) {
        perror("read");
        exit(1);
    }

    printf("Server: %s", buffer);

    snprintf(buffer, sizeof(buffer), "HELO localhost\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n == -1) {
        perror("write");
        exit(1);
    }

    n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1) {
        perror("read");
        exit(1);
    }

    printf("Server: %s", buffer);

    snprintf(buffer, sizeof(buffer), "MAIL FROM: <sender@localhost>\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n == -1) {
        perror("write");
        exit(1);
    }

    n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1) {
        perror("read");
        exit(1);
    }

    printf("Server: %s", buffer);

    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", argv[2]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n == -1) {
        perror("write");
        exit(1);
    }

    n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1) {
        perror("read");
        exit(1);
    }

    printf("Server: %s", buffer);

    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n == -1) {
        perror("write");
        exit(1);
    }

    n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1) {
        perror("read");
        exit(1);
    }

    printf("Server: %s", buffer);

    snprintf(buffer, sizeof(buffer), "Subject: Test email\r\n\r\nThis is a test email.\r\n.\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n == -1) {
        perror("write");
        exit(1);
    }

    n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1) {
        perror("read");
        exit(1);
    }

    printf("Server: %s", buffer);

    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n == -1) {
        perror("write");
        exit(1);
    }

    n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1) {
        perror("read");
        exit(1);
    }

    printf("Server: %s", buffer);

    close(sockfd);

    return 0;
}