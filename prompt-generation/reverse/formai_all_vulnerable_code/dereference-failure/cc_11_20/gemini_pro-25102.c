//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>

#define IMAP_PORT 143

int main(int argc, char **argv)
{
    int sockfd, ret;
    struct sockaddr_in serv_addr;
    char buf[1024];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(IMAP_PORT);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    ret = read(sockfd, buf, sizeof(buf));
    if (ret < 0) {
        perror("read");
        return EXIT_FAILURE;
    }

    printf("%s", buf);

    snprintf(buf, sizeof(buf), "a001 LOGIN %s\r\n", argv[2]);
    ret = write(sockfd, buf, strlen(buf));
    if (ret < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    ret = read(sockfd, buf, sizeof(buf));
    if (ret < 0) {
        perror("read");
        return EXIT_FAILURE;
    }

    printf("%s", buf);

    snprintf(buf, sizeof(buf), "a002 SELECT INBOX\r\n");
    ret = write(sockfd, buf, strlen(buf));
    if (ret < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    ret = read(sockfd, buf, sizeof(buf));
    if (ret < 0) {
        perror("read");
        return EXIT_FAILURE;
    }

    printf("%s", buf);

    snprintf(buf, sizeof(buf), "a003 FETCH 1:* (UID BODY)\r\n");
    ret = write(sockfd, buf, strlen(buf));
    if (ret < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    ret = read(sockfd, buf, sizeof(buf));
    if (ret < 0) {
        perror("read");
        return EXIT_FAILURE;
    }

    printf("%s", buf);

    snprintf(buf, sizeof(buf), "a004 LOGOUT\r\n");
    ret = write(sockfd, buf, strlen(buf));
    if (ret < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    ret = read(sockfd, buf, sizeof(buf));
    if (ret < 0) {
        perror("read");
        return EXIT_FAILURE;
    }

    printf("%s", buf);

    close(sockfd);

    return EXIT_SUCCESS;
}