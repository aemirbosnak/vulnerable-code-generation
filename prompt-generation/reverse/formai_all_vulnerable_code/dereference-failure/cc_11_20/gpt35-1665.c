//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 25

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("mail.example.com");

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(SMTP_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    char buffer[256];
    int n;

    n = read(sockfd, buffer, 255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';
    printf("%s\n", buffer);

    char *message = "HELO mydomain.com\r\n";
    n = write(sockfd, message, strlen(message));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = read(sockfd, buffer, 255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';

    printf("%s\n", buffer);

    message = "MAIL FROM:<me@mydomain.com>\r\n";
    n = write(sockfd, message, strlen(message));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = read(sockfd, buffer, 255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';

    printf("%s\n", buffer);

    message = "RCPT TO:<you@yourdomain.com>\r\n";
    n = write(sockfd, message, strlen(message));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = read(sockfd, buffer, 255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';

    printf("%s\n", buffer);

    message = "DATA\r\n";
    n = write(sockfd, message, strlen(message));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = read(sockfd, buffer, 255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';

    printf("%s\n", buffer);

    message = "From: me@mydomain.com\r\nTo: you@yourdomain.com\r\nSubject: Test message\r\n\r\nHello,\r\nThis is a test message.\r\n\r\n";
    n = write(sockfd, message, strlen(message));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    message = ".\r\n";
    n = write(sockfd, message, strlen(message));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = read(sockfd, buffer, 255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';

    printf("%s\n", buffer);

    message = "QUIT\r\n";
    n = write(sockfd, message, strlen(message));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = read(sockfd, buffer, 255);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    buffer[n] = '\0';

    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}