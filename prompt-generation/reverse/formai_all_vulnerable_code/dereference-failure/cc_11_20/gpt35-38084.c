//FormAI DATASET v1.0 Category: Chat server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT "3500"
#define BACKLOG 10

int main(void) {
    struct sockaddr_storage their_addr;
    socklen_t addr_size;
    struct addrinfo hints, *res;
    int sockfd, new_fd, numbytes;
    char buf[1024];
    char s[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if(getaddrinfo(NULL, PORT, &hints, &res)) {
        perror("getaddrinfo");
        return 1;
    }

    if((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
        perror("socket");
        return 2;
    }

    if(bind(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        close(sockfd);
        perror("bind");
        return 3;
    }

    freeaddrinfo(res);

    if(listen(sockfd, BACKLOG) == -1) {
        perror("listen");
        return 4;
    }

    printf("server: waiting for connections...\n");

    while(1) {
        addr_size = sizeof their_addr;
        new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);
        if(new_fd == -1) {
            perror("accept");
            continue;
        }

        inet_ntop(their_addr.ss_family, &(((struct sockaddr_in*)&their_addr)->sin_addr), s, sizeof s);
        printf("server: got connection from %s\n", s);

        if(!fork()) {
            close(sockfd);
            if(send(new_fd, "Connected", 9, 0) == -1) {
                perror("send");
            }
            if((numbytes = recv(new_fd, buf, 1024 - 1, 0)) == -1) {
                perror("recv");
                exit(1);
            }
            buf[numbytes] = '\0';
            printf("server: received '%s'\n", buf);

            if(send(new_fd, "Data Received", 14, 0) == -1) {
                perror("send");
            }

            close(new_fd);
            exit(0);
        }
        close(new_fd);
    }

    return 0;
}