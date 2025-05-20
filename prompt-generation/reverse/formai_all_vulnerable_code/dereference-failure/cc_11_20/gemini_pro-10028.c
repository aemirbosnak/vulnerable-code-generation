//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAXLINE];
    int n;

    if (argc != 4) {
        printf("Usage: %s <server> <port> <message>\n", argv[0]);
        return 1;
    }

    // Prepare the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    // Prepare the server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return 1;
    }

    // Do the EHLO/HELO greeting
    sprintf(buffer, "EHLO %s\r\n", argv[1]);
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, MAXLINE);
    if (n < 0) {
        perror("read");
        return 1;
    }
    if (strncmp(buffer, "250 ", 4) != 0) {
        printf("EHLO/HELO failed: %s\n", buffer);
        return 1;
    }

    // Do the MAIL FROM command
    sprintf(buffer, "MAIL FROM: <%s>\r\n", argv[3]);
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, MAXLINE);
    if (n < 0) {
        perror("read");
        return 1;
    }
    if (strncmp(buffer, "250 ", 4) != 0) {
        printf("MAIL FROM failed: %s\n", buffer);
        return 1;
    }

    // Do the RCPT TO command
    sprintf(buffer, "RCPT TO: <%s>\r\n", argv[1]);
    write(sockfd, buffer, strlen(buffer));
    n = read(sockfd, buffer, MAXLINE);
    if (n < 0) {
        perror("read");
        return 1;
    }
    if (strncmp(buffer, "250 ", 4) != 0) {
        printf("RCPT TO failed: %s\n", buffer);
        return 1;
    }

    // Do the DATA command
    write(sockfd, "DATA\r\n", strlen("DATA\r\n"));
    n = read(sockfd, buffer, MAXLINE);
    if (n < 0) {
        perror("read");
        return 1;
    }
    if (strncmp(buffer, "354 ", 4) != 0) {
        printf("DATA failed: %s\n", buffer);
        return 1;
    }

    // Write the message
    write(sockfd, argv[3], strlen(argv[3]));
    write(sockfd, "\r\n.\r\n", strlen("\r\n.\r\n"));

    // Do the QUIT command
    write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    n = read(sockfd, buffer, MAXLINE);
    if (n < 0) {
        perror("read");
        return 1;
    }
    if (strncmp(buffer, "221 ", 4) != 0) {
        printf("QUIT failed: %s\n", buffer);
        return 1;
    }

    return 0;
}