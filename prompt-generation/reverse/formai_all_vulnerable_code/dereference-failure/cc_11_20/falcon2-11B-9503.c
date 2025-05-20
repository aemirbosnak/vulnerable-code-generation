//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    struct addrinfo hints, *servinfo, *p;
    int rv, sockfd;
    char buffer[1024];

    // Initialize the address info structure
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Resolve the hostname and port for the SMTP server
    if ((rv = getaddrinfo(NULL, "smtp.example.com", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // Iterate over the server information to get the socket descriptor
    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }
        break;
    }

    // Send the SMTP HELO command
    if (send(sockfd, "HELO client\r\n", sizeof("HELO client\r\n"), 0) == -1) {
        perror("send");
        close(sockfd);
        return 1;
    }

    // Send the SMTP EHLO command
    if (send(sockfd, "EHLO client\r\n", sizeof("EHLO client\r\n"), 0) == -1) {
        perror("send");
        close(sockfd);
        return 1;
    }

    // Send the SMTP MAIL FROM command
    if (send(sockfd, "MAIL FROM:<user@example.com>\r\n", sizeof("MAIL FROM:<user@example.com>\r\n"), 0) == -1) {
        perror("send");
        close(sockfd);
        return 1;
    }

    // Send the SMTP RCPT TO command
    if (send(sockfd, "RCPT TO:<recipient@example.com>\r\n", sizeof("RCPT TO:<recipient@example.com>\r\n"), 0) == -1) {
        perror("send");
        close(sockfd);
        return 1;
    }

    // Send the SMTP DATA command
    if (send(sockfd, "DATA\r\n", sizeof("DATA\r\n"), 0) == -1) {
        perror("send");
        close(sockfd);
        return 1;
    }

    // Send the SMTP message data
    sprintf(buffer, "Subject: Test Message\r\n\r\nHello World!");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        close(sockfd);
        return 1;
    }

    // Send the SMTP QUIT command
    if (send(sockfd, "QUIT\r\n", sizeof("QUIT\r\n"), 0) == -1) {
        perror("send");
        close(sockfd);
        return 1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}