//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

#define PORT 8080
#define MAX_EVENTS 10

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = { 0 };
    int epoll_fd, nfds;
    struct epoll_event event, events[MAX_EVENTS];

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("socket failed");
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        error("setsockopt");
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        error("bind failed");
    }

    // Listening on the socket
    if (listen(server_fd, 3) < 0) {
        error("listen");
    }

    // Creating epoll file descriptor
    epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        error("epoll_create1");
    }

    // Adding server socket to epoll
    event.events = EPOLLIN;
    event.data.fd = server_fd;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &event) == -1) {
        error("epoll_ctl");
    }

    while(1) {
        // Waiting for events to happen
        nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            error("epoll_wait");
        }

        // Looping over events
        for (int i = 0; i < nfds; i++) {
            // Handling new connection
            if (events[i].data.fd == server_fd) {
                if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
                    error("accept");
                }

                printf("New connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

                // Adding new socket to epoll
                event.events = EPOLLIN | EPOLLET;
                event.data.fd = new_socket;
                if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, new_socket, &event) == -1) {
                    error("epoll_ctl");
                }
            } else {
                // Reading data from socket
                valread = read(events[i].data.fd, buffer, 1024);
                if (valread == 0) {
                    // Closing connection
                    printf("Client disconnected\n");
                    close(events[i].data.fd);
                    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, events[i].data.fd, NULL);
                } else {
                    // Writing data back to socket
                    write(events[i].data.fd, buffer, valread);
                }
            }
        }
    }

    // Closing server socket
    close(server_fd);

    // Closing epoll file descriptor
    close(epoll_fd);

    return 0;
}