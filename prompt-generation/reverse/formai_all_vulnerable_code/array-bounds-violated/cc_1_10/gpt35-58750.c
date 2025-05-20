//FormAI DATASET v1.0 Category: Simple Web Server ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/epoll.h>

#define MAX_EVENTS 100
#define PORT 8000
#define MSG_SIZE 1024

void handle_connection(int fd)
{
    char buff[MSG_SIZE];
    ssize_t read_size = recv(fd, buff, MSG_SIZE, 0);
    if (read_size < 0) {
        perror("recv failed");
        return;
    }
    if (read_size == 0) {
        printf("client disconnected");
        return;
    }
    buff[read_size] = '\0';
    printf("Received: %s", buff);
    char response[MSG_SIZE];
    snprintf(response, MSG_SIZE, "Response to [%s]", buff);
    if (send(fd, response, strlen(response), 0) < 0) {
        perror("send failed");
        return;
    }
}

int main()
{
    int epoll_fd, listen_fd;
    struct sockaddr_in listen_addr;
    struct epoll_event event, events[MAX_EVENTS];
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    listen_addr.sin_port = htons(PORT);

    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_fd, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    epoll_fd = epoll_create1(0);
    if (epoll_fd < 0) {
        perror("epoll creation failed");
        exit(EXIT_FAILURE);
    }

    event.data.fd = listen_fd;
    event.events = EPOLLIN;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_fd, &event) < 0) {
        perror("epoll_ctl add failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int num_events = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (num_events < 0) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("epoll_wait failed");
                exit(EXIT_FAILURE);
            }
        }
        for (int i = 0; i < num_events; ++i) {
            if (events[i].data.fd == listen_fd) {
                struct sockaddr_in client_addr;
                socklen_t client_addrlen = sizeof(client_addr);
                int conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_addrlen);
                if (conn_fd < 0) {
                    perror("accept failed");
                    continue;
                }
                event.data.fd = conn_fd;
                event.events = EPOLLIN | EPOLLET;
                if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, conn_fd, &event) < 0) {
                    perror("epoll_ctl add failed");
                    exit(EXIT_FAILURE);
                }
            } else {
                handle_connection(events[i].data.fd);
            }
        }
    }
    return 0;
}