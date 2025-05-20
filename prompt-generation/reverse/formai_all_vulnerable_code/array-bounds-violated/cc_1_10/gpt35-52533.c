//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define IMAP_PORT "993"

int main(int argc, char* argv[]) {
    char* server = argv[1];
    char* user = argv[2];
    char* password = argv[3];

    struct addrinfo hints, *result;
    int status, sockfd;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(server, IMAP_PORT, &hints, &result)) != 0) {
        perror("getaddrinfo");
        return 1;
    }

    sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        perror("connect");
        return 1;
    }

    char buf[BUF_SIZE];
    ssize_t num_read;
    bool success = false;

    num_read = recv(sockfd, buf, BUF_SIZE-1, 0);
    buf[num_read] = '\0';
    printf("%s\n", buf);

    sprintf(buf, "a1 LOGIN %s %s", user, password);
    send(sockfd, buf, strlen(buf), 0);
    num_read = recv(sockfd, buf, BUF_SIZE-1, 0);
    buf[num_read] = '\0';
    printf("%s\n", buf);

    sprintf(buf, "a2 SELECT INBOX");
    send(sockfd, buf, strlen(buf), 0);
    num_read = recv(sockfd, buf, BUF_SIZE-1, 0);
    buf[num_read] = '\0';
    printf("%s\n", buf);

    sprintf(buf, "a3 FETCH 1:* (FLAGS BODY[HEADER.FIELDS (FROM SUBJECT DATE)])");
    send(sockfd, buf, strlen(buf), 0);

    while (num_read = recv(sockfd, buf, BUF_SIZE-1, 0)) {
        buf[num_read] = '\0';
        printf("%s", buf);
    }

    sprintf(buf, "a4 LOGOUT");
    send(sockfd, buf, strlen(buf), 0);

    close(sockfd);
    return 0;
}