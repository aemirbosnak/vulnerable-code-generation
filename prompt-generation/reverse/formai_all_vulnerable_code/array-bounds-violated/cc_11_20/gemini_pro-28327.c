//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/epoll.h>

#define MAX_EVENTS 10
#define MAX_INPUT_SIZE 1024

struct epoll_event ev, events[MAX_EVENTS];

int main() {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[MAX_INPUT_SIZE];
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    portno = 5000;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    int epollfd = epoll_create1(0);
    if (epollfd == -1) {
        perror("Error creating epoll instance");
        exit(EXIT_FAILURE);
    }

    ev.events = EPOLLIN;
    ev.data.fd = sockfd;

    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, sockfd, &ev) == -1) {
        perror("Error adding socket to epoll instance");
        exit(EXIT_FAILURE);
    }

    while (1) {
        int nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        if (nfds == -1) {
            perror("Error waiting for events");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < nfds; ++i) {
            if (events[i].data.fd == sockfd) {
                clilen = sizeof(cli_addr);
                newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
                if (newsockfd < 0) {
                    perror("ERROR on accept");
                    exit(1);
                }

                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = newsockfd;

                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, newsockfd, &ev) == -1) {
                    perror("Error adding new socket to epoll instance");
                    exit(EXIT_FAILURE);
                }
            } else {
                int clientsockfd = events[i].data.fd;
                memset(buffer, '\0', MAX_INPUT_SIZE);

                int n = read(clientsockfd, buffer, MAX_INPUT_SIZE - 1);
                if (n < 0) {
                    perror("ERROR reading from socket");
                    close(clientsockfd);
                    continue;
                }

                if (n == 0) {
                    close(clientsockfd);
                    continue;
                }

                // User Input Sanitization:
                size_t len = 0;
                char *allowed_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                      "abcdefghijklmnopqrstuvwxyz"
                                      "0123456789";

                while (buffer[len] != '\0') {
                    int found = 0;
                    for (int j = 0; j < strlen(allowed_chars); j++) {
                        if (buffer[len] == allowed_chars[j]) {
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        buffer[len] = '\0';
                        break;
                    }

                    len++;
                }

                n = write(clientsockfd, buffer, strlen(buffer));
                if (n < 0) {
                    perror("ERROR writing to socket");
                    close(clientsockfd);
                }
            }
        }
    }

    close(sockfd);
    close(epollfd);

    return 0;
}