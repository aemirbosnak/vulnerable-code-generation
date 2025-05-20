//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>

#define BUFSIZE 4096

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <port> <target-host> <target-port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[1]);
    const char *target_host = argv[2];
    int target_port = atoi(argv[3]);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    int optval = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    struct sockaddr_in listenaddr;
    memset(&listenaddr, 0, sizeof(listenaddr));
    listenaddr.sin_family = AF_INET;
    listenaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    listenaddr.sin_port = htons(port);

    if (bind(listenfd, (struct sockaddr *)&listenaddr, sizeof(listenaddr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    if (listen(listenfd, 5) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    while (1) {
        struct sockaddr_in clientaddr;
        socklen_t clientaddrlen = sizeof(clientaddr);

        int clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientaddrlen);
        if (clientfd == -1) {
            perror("accept");
            continue;
        }

        char buf[BUFSIZE];
        int n;

        while ((n = read(clientfd, buf, sizeof(buf))) > 0) {
            char *p = buf;
            while (n > 0) {
                int m = send(clientfd, p, n, 0);
                if (m == -1) {
                    perror("send");
                    goto clientfd_close;
                }
                p += m;
                n -= m;
            }
        }

        if (n == -1) {
            perror("read");
        }

clientfd_close:
        close(clientfd);
    }

    close(listenfd);

    return EXIT_SUCCESS;
}