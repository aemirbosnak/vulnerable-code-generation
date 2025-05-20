//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 80

int main() {
    struct timeval tv;
    fd_set readfds;
    struct sockaddr_in server;
    int sockfd, n;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "socket error\n");
        exit(1);
    }

    bzero((char *) &server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "www.example.com", &server.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton error\n");
        exit(1);
    }

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        gettimeofday(&tv, NULL);
        tv.tv_sec += 1;

        if (select(sockfd + 1, &readfds, NULL, NULL, &tv) == -1) {
            perror("select");
            exit(1);
        }

        if (FD_ISSET(sockfd, &readfds)) {
            n = recv(sockfd, NULL, 0, 0);
            if (n < 0) {
                perror("recv");
                exit(1);
            }

            if (n > 0) {
                printf("Response code: %d\n", n);
            } else {
                printf("Connection closed\n");
                exit(1);
            }
        }
    }

    close(sockfd);
    return 0;
}