//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFSIZE 4096

int nonblock(int fd) {
    int flags;

    if ((flags = fcntl(fd, F_GETFL, 0)) < 0) {
        perror("fcntl(F_GETFL)");
        exit(1);
    }

    flags |= O_NONBLOCK;

    if (fcntl(fd, F_SETFL, flags) < 0) {
        perror("fcntl(F_SETFL)");
        exit(1);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    int listenfd, clientfd, backendfd;
    struct sockaddr_in listenaddr, clientaddr, backendaddr;
    socklen_t clientaddrlen, backendaddrlen;
    char buf[BUFSIZE];
    int n;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <listen port> <backend address:port>\n", argv[0]);
        exit(1);
    }

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&listenaddr, 0, sizeof(listenaddr));
    listenaddr.sin_family = AF_INET;
    listenaddr.sin_port = htons(atoi(argv[1]));
    listenaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listenfd, (struct sockaddr *)&listenaddr, sizeof(listenaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(listenfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    if ((backendfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&backendaddr, 0, sizeof(backendaddr));
    backendaddr.sin_family = AF_INET;

    if (inet_pton(AF_INET, argv[2], &backendaddr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid backend address: %s\n", argv[2]);
        exit(1);
    }

    backendaddr.sin_port = htons(atoi(strchr(argv[2], ':') + 1));

    if (nonblock(backendfd) < 0) {
        perror("nonblock");
        exit(1);
    }

    while (1) {
        clientaddrlen = sizeof(clientaddr);
        if ((clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientaddrlen)) < 0) {
            if (errno == EINTR) continue;
            perror("accept");
            exit(1);
        }

        if (connect(backendfd, (struct sockaddr *)&backendaddr, sizeof(backendaddr)) < 0) {
            if (errno == EINPROGRESS) {
                fd_set wfds;

                FD_ZERO(&wfds);
                FD_SET(backendfd, &wfds);

                if (select(backendfd + 1, NULL, &wfds, NULL, NULL) < 0) {
                    perror("select");
                    exit(1);
                }

                int error;
                socklen_t len = sizeof(error);

                if (getsockopt(backendfd, SOL_SOCKET, SO_ERROR, &error, &len) < 0) {
                    perror("getsockopt");
                    exit(1);
                }

                if (error) {
                    fprintf(stderr, "connect() failed: %s\n", strerror(error));
                    exit(1);
                }
            } else {
                perror("connect");
                exit(1);
            }
        }

        nonblock(clientfd);

        while ((n = read(clientfd, buf, BUFSIZE)) > 0) {
            if (write(backendfd, buf, n) < n) {
                perror("write");
                exit(1);
            }
        }

        if (n < 0) {
            if (errno == EAGAIN) continue;
            perror("read");
            exit(1);
        }

        close(clientfd);

        while ((n = read(backendfd, buf, BUFSIZE)) > 0) {
            if (write(clientfd, buf, n) < n) {
                perror("write");
                exit(1);
            }
        }

        if (n < 0) {
            if (errno == EAGAIN) continue;
            perror("read");
            exit(1);
        }

        close(backendfd);
    }

    return 0;
}