//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/epoll.h>

#define MAX_EVENTS 20
#define MAX_BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    struct sockaddr_in clientaddr, serveraddr;

    int listenfd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(8080);

    bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

    listen(listenfd, 10);

    int epollfd = epoll_create1(0);
    if (epollfd == -1) {
        perror("epoll_create1 failed!");
        return -1;
    }

    struct epoll_event ev, events[MAX_EVENTS];
    ev.events = EPOLLIN;
    ev.data.fd = listenfd;

    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd, &ev) == -1) {
        perror("epoll_ctl: listenfd");
        return -1;
    }

    while (1) {
        int n = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (n == -1) {
            perror("epoll_wait failed!");
            return -1;
        }

        for (int i = 0; i < n; i++) {
            if (events[i].data.fd == listenfd) {
                socklen_t addrlen = sizeof(clientaddr);
                int connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &addrlen);

                if (connfd == -1) {
                    if ((errno == EAGAIN) || (errno == EWOULDBLOCK)) {
                        continue;
                    } else {
                        perror("accept failed!");
                        return -1;
                    }
                }

                char *client_address = inet_ntoa(clientaddr.sin_addr);
                printf("Received incoming connection from %s\n", client_address);

                fcntl(connfd, F_SETFL, O_NONBLOCK);

                ev.events = EPOLLIN | EPOLLRDHUP | EPOLLOUT | EPOLLET;
                ev.data.fd = connfd;

                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, connfd, &ev) == -1) {
                    perror("epoll_ctl: connfd");
                    return -1;
                }
            } else if (events[i].events & EPOLLIN) {
                int fd = events[i].data.fd;

                while (1) {
                    char buffer[MAX_BUFFER_SIZE];
                    ssize_t nbytes = recv(fd, buffer, MAX_BUFFER_SIZE, 0);

                    if (nbytes == -1) {
                        if (errno == EAGAIN || errno == EWOULDBLOCK) {
                            break;
                        } else {
                            perror("recv failed!");
                            close(fd);
                            break;
                        }
                    } else if (nbytes == 0) {
                        printf("Connection closed by remote host\n");
                        close(fd);
                        break;
                    } else {
                        printf("Received message: %s\n", buffer);
                    }
                }

            } else if (events[i].events & EPOLLOUT) {
                int fd = events[i].data.fd;
                char *message = "HTTP/1.1 200 OK\r\nContent-Length:13\r\n\r\nHello, World!";

                if (send(fd, message, strlen(message), 0) == -1) {
                    perror("send failed!");
                    close(fd);
                }

                close(fd);

            } else if (events[i].events & EPOLLRDHUP) {
                printf("Remote host closed connection\n");
                close(events[i].data.fd);
            }
        }
    }

    return 0;
}