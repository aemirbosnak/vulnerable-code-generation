//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE 1024
#define MAX_HOST_LEN 100

struct hostent *gethostbyname(const char *name);
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[MAX_LINE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(argv[1], NULL, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect\n");
        exit(1);
    }

    sprintf(s, "Connected to %s\n", argv[1]);
    write(sockfd, s, strlen(s));

    while (1) {
        memset(s, 0, MAX_LINE);
        if (read(sockfd, s, MAX_LINE) == 0) {
            fprintf(stderr, "Connection closed by server\n");
            break;
        }
        printf("%s", s);
    }

    close(sockfd);
    return 0;
}

struct hostent *gethostbyname(const char *name) {
    struct hostent *he;
    int h_errno;

    if ((he = gethostbyname(name)) == NULL) {
        h_errno = h_errno;
        fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
        exit(1);
    }

    return he;
}