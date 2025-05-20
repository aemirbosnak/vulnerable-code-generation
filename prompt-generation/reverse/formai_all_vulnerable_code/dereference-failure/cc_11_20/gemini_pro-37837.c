//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd, n;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char buf[1024];
    char user[1024];
    char pass[1024];

    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    snprintf(user, sizeof(user), "USER %s\r\n", getenv("USER"));
    n = send(sockfd, user, strlen(user), 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    snprintf(pass, sizeof(pass), "PASS %s\r\n", getenv("PASS"));
    n = send(sockfd, pass, strlen(pass), 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    snprintf(buf, sizeof(buf), "STAT\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    snprintf(buf, sizeof(buf), "LIST\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    while ((n = recv(sockfd, buf, sizeof(buf), 0)) > 0) {
        printf("%s", buf);
    }
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    snprintf(buf, sizeof(buf), "RETR 1\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    while ((n = recv(sockfd, buf, sizeof(buf), 0)) > 0) {
        printf("%s", buf);
    }
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    snprintf(buf, sizeof(buf), "QUIT\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    close(sockfd);

    return EXIT_SUCCESS;
}