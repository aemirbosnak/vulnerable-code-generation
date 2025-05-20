//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int port;
    int status;
    struct addrinfo hints, *servinfo, *p;
    char port_str[10];
    struct sockaddr_in sin;
    int opt = 1;
    int sockfd;

    if (argc < 2) {
        printf("Usage: %s <target_host> [<target_port>]\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(argv[1], NULL, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(1);
    }

    printf("Scanning %s...\n", argv[1]);
    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if (argc == 3) {
            sprintf(port_str, "%d", atoi(argv[2]));
        } else {
            sprintf(port_str, "%d", (rand() % 65535));
        }

        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }

        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof opt) == -1) {
            perror("setsockopt");
            close(sockfd);
            continue;
        }

        if (send(sockfd, "GET / HTTP/1.1\r\nHost: ", 32, 0) == -1) {
            perror("send");
            close(sockfd);
            continue;
        }

        if (send(sockfd, "\r\n", 2, 0) == -1) {
            perror("send");
            close(sockfd);
            continue;
        }

        if (recv(sockfd, port_str, 10, 0) == -1) {
            perror("recv");
            close(sockfd);
            continue;
        }

        printf("Port %s is open\n", port_str);
        close(sockfd);
    }

    freeaddrinfo(servinfo);
    return 0;
}