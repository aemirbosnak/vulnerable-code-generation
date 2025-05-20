//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: accurate
/*
 * SMTP Client example program
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>

#define SMTP_PORT 25
#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, n;
    char buffer[BUF_SIZE];
    struct sockaddr_in server_addr;
    struct hostent *server;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <message>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host: %s\n", argv[1]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);
    bzero(&(server_addr.sin_zero), 8);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // send HELO command
    n = write(sockfd, "HELO mydomain.com\r\n", strlen("HELO mydomain.com\r\n"));
    if (n < 0) {
        perror("ERROR writing HELO");
        exit(1);
    }

    // read the response
    n = read(sockfd, buffer, BUF_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading response");
        exit(1);
    }
    buffer[n] = '\0';

    // send MAIL command
    n = write(sockfd, "MAIL FROM:<sender@mydomain.com>\r\n", strlen("MAIL FROM:<sender@mydomain.com>\r\n"));
    if (n < 0) {
        perror("ERROR writing MAIL");
        exit(1);
    }

    // send RCPT command
    n = write(sockfd, "RCPT TO:<receiver@mydomain.com>\r\n", strlen("RCPT TO:<receiver@mydomain.com>\r\n"));
    if (n < 0) {
        perror("ERROR writing RCPT");
        exit(1);
    }

    // send DATA command
    n = write(sockfd, "DATA\r\n", strlen("DATA\r\n"));
    if (n < 0) {
        perror("ERROR writing DATA");
        exit(1);
    }

    // send message
    n = write(sockfd, argv[2], strlen(argv[2]));
    if (n < 0) {
        perror("ERROR writing message");
        exit(1);
    }

    // send .
    n = write(sockfd, "\r\n.\r\n", strlen("\r\n.\r\n"));
    if (n < 0) {
        perror("ERROR writing .");
        exit(1);
    }

    // read the response
    n = read(sockfd, buffer, BUF_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading response");
        exit(1);
    }
    buffer[n] = '\0';

    // send QUIT command
    n = write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    if (n < 0) {
        perror("ERROR writing QUIT");
        exit(1);
    }

    close(sockfd);
    return 0;
}