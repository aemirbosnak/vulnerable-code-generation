//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <sys/timerfd.h>

#define MAX_EVENTS 1024

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 10) == -1) {
        perror("listen");
        exit(1);
    }

    int epollfd = epoll_create1(0);
    if (epollfd == -1) {
        perror("epoll_create1");
        exit(1);
    }

    struct epoll_event event;
    memset(&event, 0, sizeof(event));
    event.events = EPOLLIN;
    event.data.fd = sockfd;

    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &event) == -1) {
        perror("epoll_ctl");
        exit(1);
    }

    while (1) {
        struct epoll_event events[MAX_EVENTS];
        int nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            perror("epoll_wait");
            exit(1);
        }

        for (int i = 0; i < nfds; i++) {
            if (events[i].data.fd == sockfd) {
                // New connection
                struct sockaddr_in client_addr;
                socklen_t client_addr_len = sizeof(client_addr);
                int clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
                if (clientfd == -1) {
                    perror("accept");
                    continue;
                }

                // Add clientfd to epoll
                struct epoll_event event;
                memset(&event, 0, sizeof(event));
                event.events = EPOLLIN;
                event.data.fd = clientfd;

                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, clientfd, &event) == -1) {
                    perror("epoll_ctl");
                    close(clientfd);
                    continue;
                }
            } else {
                // Data from client
                char buffer[1024];
                int nbytes = recv(events[i].data.fd, buffer, sizeof(buffer), 0);
                if (nbytes == -1) {
                    perror("recv");
                    close(events[i].data.fd);
                    continue;
                } else if (nbytes == 0) {
                    // Client closed connection
                    close(events[i].data.fd);
                    continue;
                }

                // Check for spam
                if (strstr(buffer, "viagra") != NULL) {
                    // Send spam message to client
                    const char *spam_message = "This is a spam message. Please do not respond.";
                    if (send(events[i].data.fd, spam_message, strlen(spam_message), 0) == -1) {
                        perror("send");
                        close(events[i].data.fd);
                        continue;
                    }
                }
            }
        }
    }

    close(sockfd);
    close(epollfd);

    return 0;
}