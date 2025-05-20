//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFSIZE 4096

int main(int argc, char *argv[]) {
    int clientfd, serverfd;
    struct sockaddr_in clientaddr, serveraddr;
    char buf[BUFSIZE], method[BUFSIZE], uri[BUFSIZE], version[BUFSIZE], hostname[BUFSIZE];
    int port = 80;
    char *ptr;
    size_t nread, nsend;
    ssize_t nrecv;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket error");
        return EXIT_FAILURE;
    }

    int optval = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("setsockopt error");
        return EXIT_FAILURE;
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("bind error");
        return EXIT_FAILURE;
    }

    if (listen(listenfd, 10) < 0) {
        perror("listen error");
        return EXIT_FAILURE;
    }

    while (1) {
        memset(&clientaddr, 0, sizeof(clientaddr));
        socklen_t clientlen = sizeof(clientaddr);
        clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientlen);
        if (clientfd < 0) {
            perror("accept error");
            continue;
        }

        memset(&buf, 0, sizeof(buf));
        memset(&method, 0, sizeof(method));
        memset(&uri, 0, sizeof(uri));
        memset(&version, 0, sizeof(version));
        memset(&hostname, 0, sizeof(hostname));

        nread = read(clientfd, buf, sizeof(buf));
        if (nread < 0) {
            perror("read error");
            close(clientfd);
            continue;
        }

        sscanf(buf, "%s %s %s", method, uri, version);

        /* get the hostname */
        ptr = strstr(uri, "//");
        if (ptr == NULL) {
            strcpy(hostname, uri);
        } else {
            ptr += 2;
            char *ptr2 = strstr(ptr, "/");
            if (ptr2 == NULL) {
                fprintf(stderr, "ERROR: invalid request\n");
                close(clientfd);
                continue;
            }
            *ptr2 = '\0';
            strcpy(hostname, ptr);
            *ptr2 = '/';
        }

        /* get the port */
        ptr = strchr(hostname, ':');
        if (ptr != NULL) {
            *ptr++ = '\0';
            port = atoi(ptr);
        }

        serverfd = socket(AF_INET, SOCK_STREAM, 0);
        if (serverfd < 0) {
            perror("socket error");
            close(clientfd);
            continue;
        }

        struct hostent *he = gethostbyname(hostname);
        if (he == NULL) {
            perror("gethostbyname error");
            close(serverfd);
            close(clientfd);
            continue;
        }

        memset(&serveraddr, 0, sizeof(serveraddr));
        serveraddr.sin_family = AF_INET;
        serveraddr.sin_addr = *((struct in_addr *)he->h_addr);
        serveraddr.sin_port = htons(port);

        if (connect(serverfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
            perror("connect error");
            close(serverfd);
            close(clientfd);
            continue;
        }

        nsend = write(serverfd, buf, nread);
        if (nsend < 0) {
            perror("write error");
            close(serverfd);
            close(clientfd);
            continue;
        }

        memset(&buf, 0, sizeof(buf));
        while ((nrecv = read(serverfd, buf, sizeof(buf))) > 0) {
            nsend = write(clientfd, buf, nrecv);
            if (nsend < nrecv) {
                perror("write error");
                close(serverfd);
                close(clientfd);
                continue;
            }
            memset(&buf, 0, sizeof(buf));
        }

        if (nrecv < 0) {
            perror("read error");
            close(serverfd);
            close(clientfd);
            continue;
        }

        close(serverfd);
        close(clientfd);
    }

    return EXIT_SUCCESS;
}