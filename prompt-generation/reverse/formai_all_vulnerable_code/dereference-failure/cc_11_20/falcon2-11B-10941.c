//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr, "Usage %s hostname\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    portno = htons(25); // SMTP port

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Connected to SMTP server\n");

    char buffer[256];
    bzero(buffer, 256);
    if (recv(sockfd, buffer, 256, 0) <= 0) {
        perror("recv");
        exit(1);
    }

    printf("%s\n", buffer);

    if (send(sockfd, "MAIL FROM:<sender@example.com>\r\n", strlen("MAIL FROM:<sender@example.com>\r\n"), 0) < 0) {
        perror("send");
        exit(1);
    }

    if (send(sockfd, "RCPT TO:<receiver@example.com>\r\n", strlen("RCPT TO:<receiver@example.com>\r\n"), 0) < 0) {
        perror("send");
        exit(1);
    }

    if (send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0) < 0) {
        perror("send");
        exit(1);
    }

    if (send(sockfd, "Subject: Test message\r\n", strlen("Subject: Test message\r\n"), 0) < 0) {
        perror("send");
        exit(1);
    }

    if (send(sockfd, "This is a test message.\r\n", strlen("This is a test message.\r\n"), 0) < 0) {
        perror("send");
        exit(1);
    }

    if (send(sockfd, ".\r\n", strlen(".\r\n"), 0) < 0) {
        perror("send");
        exit(1);
    }

    if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        perror("send");
        exit(1);
    }

    close(sockfd);

    return 0;
}