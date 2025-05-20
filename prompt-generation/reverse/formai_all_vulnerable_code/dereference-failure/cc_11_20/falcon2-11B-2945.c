//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;

    if (argc!= 3) {
        fprintf(stderr, "Usage %s hostname port\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    if (send(sockfd, "EHLO localhost\r\n", 12, 0) < 0) {
        perror("ERROR sending EHLO command");
        exit(1);
    }

    if (send(sockfd, "MAIL FROM: <sender@example.com>\r\n", 32, 0) < 0) {
        perror("ERROR sending MAIL FROM command");
        exit(1);
    }

    if (send(sockfd, "RCPT TO: <recipient@example.com>\r\n", 28, 0) < 0) {
        perror("ERROR sending RCPT TO command");
        exit(1);
    }

    if (send(sockfd, "DATA\r\n", 7, 0) < 0) {
        perror("ERROR sending DATA command");
        exit(1);
    }

    if (send(sockfd, "Subject: Test message\r\n", 29, 0) < 0) {
        perror("ERROR sending Subject command");
        exit(1);
    }

    if (send(sockfd, "This is a test message.\r\n.\r\n", 41, 0) < 0) {
        perror("ERROR sending message body");
        exit(1);
    }

    if (send(sockfd, "QUIT\r\n", 7, 0) < 0) {
        perror("ERROR sending QUIT command");
        exit(1);
    }

    close(sockfd);
    return 0;
}