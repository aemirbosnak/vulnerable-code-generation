//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLEN 1024

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    struct addrinfo *result;
    int status = getaddrinfo(argv[1], argv[2], &hints, &result);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
    freeaddrinfo(result);

    char response[MAXLEN];
    if (recv(sockfd, response, MAXLEN, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("Server response: %s\n", response);

    char buffer[MAXLEN];
    printf("Enter a recipient email address: ");
    fgets(buffer, MAXLEN, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;

    const char *from = "SMTP client <sender@example.com>";
    const char *to = buffer;

    printf("Enter the email subject: ");
    fgets(buffer, MAXLEN, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;

    const char *subject = buffer;

    printf("Enter the email message: ");
    fgets(buffer, MAXLEN, stdin);
    buffer[strcspn(buffer, "\r\n")] = 0;

    const char *message = buffer;

    char envelope[MAXLEN];
    snprintf(envelope, MAXLEN, "MAIL FROM: <%s>\r\nRCPT TO: <%s>\r\nDATA\r\n", from, to);
    if (send(sockfd, envelope, strlen(envelope), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, response, MAXLEN, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    char email[MAXLEN];
    snprintf(email, MAXLEN, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", from, to, subject, message);
    if (send(sockfd, email, strlen(email), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, response, MAXLEN, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    if (send(sockfd, "QUIT\r\n", 6, 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, response, MAXLEN, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s", response);

    if (close(sockfd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }
    return 0;
}