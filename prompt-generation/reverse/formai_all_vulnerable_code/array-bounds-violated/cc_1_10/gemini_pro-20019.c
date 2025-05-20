//GEMINI-pro DATASET v1.0 Category: Networking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/epoll.h>

#define PORT 8080
#define MAX_EVENTS 10

int create_and_bind(void) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

int main(void) {
    int sockfd = create_and_bind();

    if (listen(sockfd, SOMAXCONN) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    int epollfd = epoll_create1(0);
    if (epollfd == -1) {
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }

    struct epoll_event ev;
    ev.events = EPOLLIN | EPOLLOUT;
    ev.data.fd = sockfd;

    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &ev) == -1) {
        perror("epoll_ctl");
        exit(EXIT_FAILURE);
    }

    struct epoll_event events[MAX_EVENTS];

    while (1) {
        int nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < nfds; i++) {
            if (events[i].events & EPOLLIN) {
                int connfd = accept(sockfd, NULL, NULL);
                if (connfd == -1) {
                    perror("accept");
                    continue;
                }

                ev.events = EPOLLIN | EPOLLOUT;
                ev.data.fd = connfd;

                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, connfd, &ev) == -1) {
                    perror("epoll_ctl");
                    continue;
                }
            } else if (events[i].events & EPOLLOUT) {
                int connfd = events[i].data.fd;

                char buffer[] = "Hello from server!\n";
                int n = write(connfd, buffer, strlen(buffer));
                if (n == -1) {
                    perror("write");
                    continue;
                }

                ev.events = EPOLLIN;
                ev.data.fd = connfd;

                if (epoll_ctl(epollfd, EPOLL_CTL_MOD, connfd, &ev) == -1) {
                    perror("epoll_ctl");
                    continue;
                }
            }
        }
    }

    close(sockfd);
    close(epollfd);

    return EXIT_SUCCESS;
}