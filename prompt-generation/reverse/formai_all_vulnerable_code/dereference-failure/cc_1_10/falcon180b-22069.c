//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct addrinfo hints, *servinfo, *p;
    char s[NI_MAXHOST];
    char c[NI_MAXSERV];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    ret = getaddrinfo(argv[1], NULL, &hints, &servinfo);
    if (ret!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        ret = getnameinfo(p->ai_addr, p->ai_addrlen, s, sizeof(s), c, sizeof(c), 0);
        if (ret!= 0) {
            fprintf(stderr, "getnameinfo: %s\n", gai_strerror(ret));
            continue;
        }

        printf("pinging %s:%s\n", s, c);

        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        char ping_data[1024];
        strcpy(ping_data, "PING");
        send(sockfd, ping_data, strlen(ping_data), 0);

        char recv_data[1024];
        memset(recv_data, 0, sizeof(recv_data));
        ret = recv(sockfd, recv_data, sizeof(recv_data), 0);
        if (ret <= 0) {
            fprintf(stderr, "recv: %s\n", strerror(errno));
        } else {
            printf("Received response: %s\n", recv_data);
        }

        close(sockfd);
    }

    freeaddrinfo(servinfo);

    return 0;
}