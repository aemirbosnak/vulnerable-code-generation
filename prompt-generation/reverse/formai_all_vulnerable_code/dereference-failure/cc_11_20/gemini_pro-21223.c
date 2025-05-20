//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/time.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <hostname> <email> <to> <body>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct sockaddr_in server;
    struct hostent *host;
    int sockfd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(SMTP_PORT);
    memcpy(&server.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char buffer[1024];
    int n;

    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    buffer[n] = '\0';
    printf("%s\n", buffer);

    sprintf(buffer, "HELO %s\r\n", argv[1]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    buffer[n] = '\0';
    printf("%s\n", buffer);

    sprintf(buffer, "MAIL FROM: <%s>\r\n", argv[2]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    buffer[n] = '\0';
    printf("%s\n", buffer);

    sprintf(buffer, "RCPT TO: <%s>\r\n", argv[3]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    buffer[n] = '\0';
    printf("%s\n", buffer);

    sprintf(buffer, "DATA\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    buffer[n] = '\0';
    printf("%s\n", buffer);

    sprintf(buffer, "%s\r\n.\r\n", argv[4]);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    buffer[n] = '\0';
    printf("%s\n", buffer);

    sprintf(buffer, "QUIT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    close(sockfd);

    return EXIT_SUCCESS;
}