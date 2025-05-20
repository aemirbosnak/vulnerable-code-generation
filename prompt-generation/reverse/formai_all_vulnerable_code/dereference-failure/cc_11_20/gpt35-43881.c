//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT "25" //SMTP port number
#define HOSTNAME "smtp.gmail.com" //SMTP server hostname

int main(int argc, char *argv[])
{
    int sockfd, num_bytes;
    char buffer[4096];
    struct addrinfo hints, *servinfo, *p;
    int status;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(HOSTNAME, PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 1;
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                             p->ai_protocol)) == -1) {
            perror("socket error");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect error");
            continue;
        }

        break; // successfully connected
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        return 2;
    }

    freeaddrinfo(servinfo);

    if (recv(sockfd, buffer, sizeof(buffer) - 1, 0) == -1) {
        perror("recv error");
        close(sockfd);
        exit(1);
    }

    printf("%s", buffer); // print server's welcome message

    // send HELO command
    if (send(sockfd, "HELO myhostname\r\n", 17, 0) == -1) {
        perror("send error");
        close(sockfd);
        exit(1);
    }

    if (recv(sockfd, buffer, sizeof(buffer) - 1, 0) == -1) {
        perror("recv error");
        close(sockfd);
        exit(1);
    }

    printf("%s", buffer);

    // send MAIL FROM command
    if (send(sockfd, "MAIL FROM: <sender@gmail.com>\r\n", 31, 0) == -1) {
        perror("send error");
        close(sockfd);
        exit(1);
    }

    if (recv(sockfd, buffer, sizeof(buffer) - 1, 0) == -1) {
        perror("recv error");
        close(sockfd);
        exit(1);
    }

    printf("%s", buffer);

    // send RCPT TO command
    if (send(sockfd, "RCPT TO: <recipient@gmail.com>\r\n", 29, 0) == -1) {
        perror("send error");
        close(sockfd);
        exit(1);
    }

    if (recv(sockfd, buffer, sizeof(buffer) - 1, 0) == -1) {
        perror("recv error");
        close(sockfd);
        exit(1);
    }

    printf("%s", buffer);

    // send DATA command
    if (send(sockfd, "DATA\r\n", 6, 0) == -1) {
        perror("send error");
        close(sockfd);
        exit(1);
    }

    if (recv(sockfd, buffer, sizeof(buffer) - 1, 0) == -1) {
        perror("recv error");
        close(sockfd);
        exit(1);
    }

    printf("%s", buffer);

    // send message body
    if (send(sockfd, "Subject: Test Email\r\n\r\nThis is a test email.\r\n", 47, 0) == -1) {
        perror("send error");
        close(sockfd);
        exit(1);
    }

    // send "." character to indicate end of message body
    if (send(sockfd, ".\r\n", 3, 0) == -1) {
        perror("send error");
        close(sockfd);
        exit(1);
    }

    if (recv(sockfd, buffer, sizeof(buffer) - 1, 0) == -1) {
        perror("recv error");
        close(sockfd);
        exit(1);
    }

    printf("%s", buffer);

    // send QUIT command
    if (send(sockfd, "QUIT\r\n", 6, 0) == -1) {
        perror("send error");
        close(sockfd);
        exit(1);
    }

    if (recv(sockfd, buffer, sizeof(buffer) - 1, 0) == -1) {
        perror("recv error");
        close(sockfd);
        exit(1);
    }

    printf("%s", buffer);

    close(sockfd);

    return 0;
}