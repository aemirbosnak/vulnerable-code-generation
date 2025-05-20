//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/epoll.h>

#define MAX_EVENTS 10

int main()
{
    int listenfd, connfd, epfd, nfds;
    struct sockaddr_in servaddr;
    struct epoll_event ev, events[MAX_EVENTS];

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        return -1;
    }

    fcntl(listenfd, F_SETFL, O_NONBLOCK);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);

    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind");
        return -1;
    }

    if (listen(listenfd, 10) == -1) {
        perror("listen");
        return -1;
    }

    epfd = epoll_create1(0);
    if (epfd == -1) {
        perror("epoll_create1");
        return -1;
    }

    ev.events = EPOLLIN;
    ev.data.fd = listenfd;

    if (epoll_ctl(epfd, EPOLL_CTL_ADD, listenfd, &ev) == -1) {
        perror("epoll_ctl");
        return -1;
    }

    for (;;) {
        nfds = epoll_wait(epfd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            perror("epoll_wait");
            return -1;
        }

        for (int i = 0; i < nfds; i++) {
            if (events[i].data.fd == listenfd) {
                connfd = accept(listenfd, (struct sockaddr *)NULL, NULL);
                if (connfd == -1) {
                    perror("accept");
                    continue;
                }

                fcntl(connfd, F_SETFL, O_NONBLOCK);

                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = connfd;

                if (epoll_ctl(epfd, EPOLL_CTL_ADD, connfd, &ev) == -1) {
                    perror("epoll_ctl");
                    continue;
                }
            } else {
                char buf[1024];
                int nread = read(events[i].data.fd, buf, sizeof(buf));
                if (nread > 0) {
                    printf("Received: %s", buf);
                    write(events[i].data.fd, buf, nread);
                } else if (nread == 0) {
                    epoll_ctl(epfd, EPOLL_CTL_DEL, events[i].data.fd, NULL);
                    close(events[i].data.fd);
                } else if (nread == -1 && errno != EAGAIN) {
                    perror("read");
                    epoll_ctl(epfd, EPOLL_CTL_DEL, events[i].data.fd, NULL);
                    close(events[i].data.fd);
                }
            }
        }
    }

    close(listenfd);
    close(epfd);
    return 0;
}