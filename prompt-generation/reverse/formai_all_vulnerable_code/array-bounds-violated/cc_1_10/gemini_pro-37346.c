//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

#define MAX_EVENTS 10
#define PORT 8080

void error(const char *msg)
{
perror(msg);
exit(1);
}

int main()
{
    int sockfd, newsockfd, epollfd, nfds;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    int opt = 1;
    struct epoll_event event;
    struct epoll_event events[MAX_EVENTS];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR: socket");

    // Set socket options
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
        error("ERROR: setsockopt");

    // Bind the socket to the address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR: bind");

    // Listen for connections
    if (listen(sockfd, 5) < 0)
        error("ERROR: listen");

    // Create an epoll instance
    epollfd = epoll_create1(0);
    if (epollfd < 0)
        error("ERROR: epoll_create");

    // Add the listening socket to the epoll instance
    event.events = EPOLLIN;
    event.data.fd = sockfd;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &event) < 0)
        error("ERROR: epoll_ctl");

    // Event loop
    while (1) {
        // Wait for events
        nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds < 0)
            error("ERROR: epoll_wait");

        // Process events
        for (int i = 0; i < nfds; i++) {
            if (events[i].events & EPOLLIN) {
                // Accept a new connection
                clilen = sizeof(cli_addr);
                newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
                if (newsockfd < 0)
                    error("ERROR: accept");

                // Add the new socket to the epoll instance
                event.events = EPOLLIN | EPOLLET;
                event.data.fd = newsockfd;
                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, newsockfd, &event) < 0)
                    error("ERROR: epoll_ctl");
            } else if (events[i].events & EPOLLOUT) {
                // Send data to a client
                char buffer[] = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";
                int n = send(events[i].data.fd, buffer, strlen(buffer), 0);
                if (n < 0)
                    error("ERROR: send");

                // Close the connection
                close(events[i].data.fd);
            }
        }
    }

    // Close the listening socket
    close(sockfd);

    // Close the epoll instance
    close(epollfd);

    return 0;
}