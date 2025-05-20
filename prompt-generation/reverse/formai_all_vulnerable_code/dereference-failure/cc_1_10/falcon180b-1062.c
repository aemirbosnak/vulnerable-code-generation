//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024
#define SERVER_PORT "80"
#define SERVER_NAME "www.example.com"

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct addrinfo hints, *servinfo, *p;
    char s[MAX_DATA_SIZE];
    struct hostent *hp;
    int rv;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(SERVER_NAME, SERVER_PORT, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(EXIT_FAILURE);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen)!= -1) {
            break;
        }

        close(sockfd);
        perror("connect");
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(servinfo);

    while (1) {
        memset(s, 0, MAX_DATA_SIZE);
        n = read(sockfd, s, MAX_DATA_SIZE);
        if (n <= 0) {
            if (n == 0) {
                fprintf(stderr, "connection closed by server\n");
            } else {
                perror("read");
            }
            break;
        }

        s[n] = '\0';
        printf("Received: %s\n", s);
    }

    close(sockfd);
    exit(EXIT_SUCCESS);
}