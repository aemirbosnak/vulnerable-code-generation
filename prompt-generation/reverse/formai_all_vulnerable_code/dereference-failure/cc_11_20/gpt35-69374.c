//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <errno.h>
#include <netdb.h>
#include <sys/epoll.h>

#define SERVER_PORT 8080
#define MAXEVENTS 64

int setnonblocking(int fd) {
    int flags;

    flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        return -1;
    }

    flags |= O_NONBLOCK;
    if (fcntl(fd, F_SETFL, flags) == -1) {
        perror("fcntl");
        return -1;
    }

    return 0;
}

int make_socket_non_blocking(int sockfd) {
    int flags, s;
    flags = fcntl(sockfd, F_GETFL, 0);
    if (flags == -1) {
        perror("fcntl");
        return -1;
    }

    flags |= O_NONBLOCK;
    s = fcntl(sockfd, F_SETFL, flags);
    if (s == -1) {
        perror("fcntl");
        return -1;
    }

    return 0;
}

int main(int argc, char **argv) {
    int server_sockfd, client_sockfd, epoll_fd, nfds, conn_sockfd;
    struct epoll_event event, *events;
    struct sockaddr_in server_addr, client_addr;
    socklen_t sin_size;
    int yes = 1;
    int i;

    /* Create socket */

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        perror("socket");
        exit(1);
    }

    /* Set socket option - SO_REUSEADDR */

    if (setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    /* Bind socket */

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(server_addr.sin_zero), '\0', 8);
    if (bind(server_sockfd, (struct sockaddr *) &server_addr, sizeof(struct sockaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    /* Listen on socket */

    if (listen(server_sockfd, 10) == -1) {
        perror("listen");
        exit(1);
    }

    /* Create epoll instance */

    epoll_fd = epoll_create(MAXEVENTS);
    if (epoll_fd == -1) {
        perror("epoll_create");
        exit(1);
    }

    event.data.fd = server_sockfd;
    event.events = EPOLLIN | EPOLLET;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_sockfd, &event) == -1) {
        perror("epoll_ctl");
        exit(1);
    }

    /* Allocate events array */

    events = calloc(MAXEVENTS, sizeof event);

    /* Event loop */

    while (1) {
        nfds = epoll_wait(epoll_fd, events, MAXEVENTS, -1);
        if (nfds == -1) {
            perror("epoll_wait");
            exit(1);
        }

        for (i = 0; i < nfds; i++) {
            if (events[i].data.fd == server_sockfd) {
                /* Connection request on listening socket */
                while (1) {
                    sin_size = sizeof(struct sockaddr_in);
                    conn_sockfd = accept(server_sockfd, (struct sockaddr *) &client_addr, &sin_size);

                    if (conn_sockfd == -1) {
                        if ((errno == EAGAIN) || (errno == EWOULDBLOCK)) {
                            /* No more incoming connections */
                            break;
                        } else {
                            perror("accept");
                            break;
                        }
                    }

                    setnonblocking(conn_sockfd);

                    event.data.fd = conn_sockfd;
                    event.events = EPOLLIN | EPOLLET;
                    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, conn_sockfd, &event) == -1) {
                        perror("epoll_ctl");
                        break;
                    }
                }
                continue;
            } else {
                /* Data arriving on already connected socket */
                client_sockfd = events[i].data.fd;

                int client_flags = fcntl(client_sockfd, F_GETFL, 0);
                if (client_flags == -1) {
                    perror("fcntl");
                    continue;
                }

                client_flags |= O_NONBLOCK;
                if (fcntl(client_sockfd, F_SETFL, client_flags) == -1) {
                    perror("fcntl");
                    continue;
                }

                /* Read request from client */

                char buffer[1024];
                int nbytes = recv(client_sockfd, buffer, 1024, 0);
                if (nbytes == 0) {
                    /* Connection closed by client */
                    close(client_sockfd);
                    continue;
                }
                if (nbytes == -1) {
                    if (errno == EAGAIN || errno == EWOULDBLOCK) {
                        /* No more data */
                    } else {
                        perror("recv");
                        close(client_sockfd);
                        continue;
                    }
                }

                /* Connect to server */

                struct hostent *host_info;
                host_info = gethostbyname("localhost");
                if (host_info == NULL) {
                    fprintf(stderr, "Proxy couldn't map host\n");
                    continue;
                }

                int sockfd = socket(AF_INET, SOCK_STREAM, 0);
                if (sockfd == -1) {
                    perror("socket");
                    close(client_sockfd);
                    continue;
                }

                struct sockaddr_in server;
                server.sin_family = AF_INET;
                server.sin_port = htons(80);
                server.sin_addr = *((struct in_addr *) host_info->h_addr);
                memset(&(server.sin_zero), '\0', 8);

                int status = connect(sockfd, (struct sockaddr *) &server, sizeof(struct sockaddr));
                if (status == -1) {
                    perror("connect");
                    close(sockfd);
                    close(client_sockfd);
                    continue;
                }

                char request[1024];
                sprintf(request, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n");

                /* Send request to server */

                nbytes = send(sockfd, request, strlen(request), 0);
                if (nbytes == -1) {
                    perror("send");
                    close(sockfd);
                    close(client_sockfd);
                    continue;
                }

                /* Send response from server to client */

                char response[1024];
                nbytes = recv(sockfd, response, 1024, 0);
                if (nbytes == 0) {
                    close(sockfd);
                    close(client_sockfd);
                    continue;
                }
                if (nbytes == -1) {
                    if (errno == EAGAIN || errno == EWOULDBLOCK) {
                        /* No more data */
                    } else {
                        perror("recv");
                        close(sockfd);
                        close(client_sockfd);
                        continue;
                    }
                }

                /* Send response back to client */
                if (send(client_sockfd, response, strlen(response), 0) == -1) {
                    perror("send");
                    close(sockfd);
                    close(client_sockfd);
                    continue;
                }

                close(sockfd);
                close(client_sockfd);
            }
        }
    }

    free(events);
    close(server_sockfd);

    return 0;
}