//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define TIMEOUT 10
#define BUFFER_SIZE 1024

void download(const char *host, int port, char *filename) {
    struct timeval start, end;
    struct timeval timeout;
    struct addrinfo hints, *servinfo, *p;
    int sockfd, rv, retval, n;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo(host, NULL, &hints, &servinfo);

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    retval = setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));
    if (retval < 0) {
        fprintf(stderr, "ERROR setting socket timeout\n");
        exit(1);
    }

    connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen);

    gettimeofday(&start, NULL);

    retval = send(sockfd, "GET / HTTP/1.1\r\nHost: ", 30, 0);
    if (retval < 0) {
        fprintf(stderr, "ERROR sending request\n");
        exit(1);
    }

    retval = send(sockfd, "Connection: close\r\n\r\n", 34, 0);
    if (retval < 0) {
        fprintf(stderr, "ERROR sending headers\n");
        exit(1);
    }

    retval = send(sockfd, filename, strlen(filename), 0);
    if (retval < 0) {
        fprintf(stderr, "ERROR sending filename\n");
        exit(1);
    }

    gettimeofday(&end, NULL);

    retval = recv(sockfd, BUFFER_SIZE, 0, 0);
    if (retval < 0) {
        fprintf(stderr, "ERROR receiving data\n");
        exit(1);
    }

    printf("Downloaded %d bytes in %d milliseconds\n", retval, (end.tv_sec * 1000) + end.tv_usec / 1000 - (start.tv_sec * 1000) - start.tv_usec / 1000);

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <host> <port> <filename>\n", argv[0]);
        exit(1);
    }

    download(argv[1], atoi(argv[2]), argv[3]);

    return 0;
}