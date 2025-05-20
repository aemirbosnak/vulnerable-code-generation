//Falcon-180B DATASET v1.0 Category: Networking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_EVENTS 1000
#define BUF_LEN 1024

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd, epoll_fd, i, num_events, client_socket;
    struct epoll_event event;
    struct epoll_event *events = malloc(MAX_EVENTS * sizeof(struct epoll_event));
    char buffer[BUF_LEN];

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    if(listen_fd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&event, 0, sizeof(event));
    event.data.fd = listen_fd;
    event.events = EPOLLIN;

    if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_fd, &event) == -1) {
        perror("epoll_ctl");
        exit(1);
    }

    while(1) {
        num_events = epoll_wait(epoll_fd, events, MAX_EVENTS - 1, -1);
        if(num_events == -1) {
            perror("epoll_wait");
            exit(1);
        }

        for(i = 0 ; i < num_events ; i++) {
            if(events[i].data.fd == listen_fd) {
                conn_fd = accept(listen_fd, NULL, NULL);

                if(conn_fd == -1) {
                    perror("accept");
                    exit(1);
                }

                memset(&event, 0, sizeof(event));
                event.data.fd = conn_fd;
                event.events = EPOLLIN | EPOLLET;

                if(epoll_ctl(epoll_fd, EPOLL_CTL_ADD, conn_fd, &event) == -1) {
                    perror("epoll_ctl");
                    exit(1);
                }
            }
            else {
                if(events[i].events & EPOLLIN) {
                    memset(buffer, 0, BUF_LEN);
                    recv(events[i].data.fd, buffer, BUF_LEN, 0);
                    printf("Received data from client : %s\n", buffer);
                }

                if(events[i].events & EPOLLOUT) {
                    send(events[i].data.fd, "Server response\n", strlen("Server response\n"), 0);
                }
            }
        }
    }

    return 0;
}