//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* host = argv[1];
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = inet_addr(host);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags < 0) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    flags |= O_NONBLOCK;
    if (fcntl(sockfd, F_SETFL, flags) < 0) {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    int ret = connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if (ret < 0 && errno != EINPROGRESS) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(sockfd, &rfds);

    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    ret = select(sockfd + 1, NULL, &rfds, NULL, &tv);
    if (ret < 0) {
        perror("select");
        exit(EXIT_FAILURE);
    } else if (ret == 0) {
        printf("Connection timed out\n");
        exit(EXIT_FAILURE);
    }

    socklen_t len = sizeof(int);
    int error;
    if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, &len) < 0) {
        perror("getsockopt");
        exit(EXIT_FAILURE);
    }

    if (error != 0) {
        printf("Connection failed: %s\n", strerror(error));
        exit(EXIT_FAILURE);
    }

    printf("Connection established\n");
    close(sockfd);

    return EXIT_SUCCESS;
}