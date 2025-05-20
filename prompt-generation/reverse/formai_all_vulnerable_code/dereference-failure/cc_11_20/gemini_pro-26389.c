//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <poll.h>
#include <sys/epoll.h>

#define MAX_EVENTS 10

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &addr.sin_addr) == -1) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    int flags = fcntl(sockfd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        return EXIT_FAILURE;
    }
    flags |= O_NONBLOCK;
    if (fcntl(sockfd, F_SETFL, flags) == -1) {
        perror("fcntl");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        if (errno != EINPROGRESS) {
            perror("connect");
            return EXIT_FAILURE;
        }
    }

    struct epoll_event event;
    memset(&event, 0, sizeof(event));
    event.data.fd = sockfd;
    event.events = EPOLLOUT | EPOLLIN;

    int epollfd = epoll_create1(0);
    if (epollfd == -1) {
        perror("epoll_create1");
        return EXIT_FAILURE;
    }

    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &event) == -1) {
        perror("epoll_ctl");
        return EXIT_FAILURE;
    }

    struct epoll_event events[MAX_EVENTS];

    char buffer[1024];
    while (1) {
        int nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            perror("epoll_wait");
            return EXIT_FAILURE;
        }

        for (int i = 0; i < nfds; i++) {
            if (events[i].data.fd == sockfd) {
                if (events[i].events & EPOLLOUT) {
                    // The connection is established
                    if (send(sockfd, "Hello, world!", 13, 0) == -1) {
                        perror("send");
                        return EXIT_FAILURE;
                    }
                    printf("Sent \"Hello, world!\" to %s:%d\n", ip, port);
                }

                if (events[i].events & EPOLLIN) {
                    // Data is available to be read
                    int nbytes = recv(sockfd, buffer, sizeof(buffer), 0);
                    if (nbytes == -1) {
                        perror("recv");
                        return EXIT_FAILURE;
                    } else if (nbytes == 0) {
                        // The connection is closed
                        printf("Connection closed by %s:%d\n", ip, port);
                        close(sockfd);
                        return EXIT_SUCCESS;
                    }

                    printf("Received %d bytes from %s:%d: %s\n", nbytes, ip, port, buffer);
                }
            }
        }
    }

    close(sockfd);
    close(epollfd);

    return EXIT_SUCCESS;
}