//Code Llama-13B DATASET v1.0 Category: Educational ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define MAX_BUF 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void *get_in_addr(struct sockaddr *sa) {
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(int argc, char *argv[]) {
    int sockfd, new_fd;
    struct sockaddr_storage their_addr;
    socklen_t addr_len;
    struct addrinfo hints, *res, *p;
    int yes = 1;
    char s[INET6_ADDRSTRLEN];

    if (argc != 2) {
        fprintf(stderr, "usage: %s port\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((getaddrinfo(NULL, argv[1], &hints, &res)) != 0) {
        error("getaddrinfo");
    }

    for (p = res; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            continue;
        }

        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
            error("setsockopt");
        }

        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        error("failed to bind socket");
    }

    freeaddrinfo(res);

    if (listen(sockfd, MAX_CLIENTS) == -1) {
        error("listen");
    }

    printf("Server listening on port %s\n", argv[1]);

    while (1) {
        addr_len = sizeof their_addr;
        new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_len);
        if (new_fd == -1) {
            error("accept");
        }

        inet_ntop(their_addr.ss_family, get_in_addr((struct sockaddr *)&their_addr), s, sizeof s);
        printf("Server: got connection from %s\n", s);

        // Read message from client
        char buffer[MAX_BUF];
        int bytes_read = recv(new_fd, buffer, MAX_BUF, 0);
        if (bytes_read == -1) {
            error("recv");
        }

        // Send message back to client
        char *response = "Hello, client!";
        if (send(new_fd, response, strlen(response), 0) == -1) {
            error("send");
        }

        // Close connection
        close(new_fd);
    }

    close(sockfd);
    return 0;
}