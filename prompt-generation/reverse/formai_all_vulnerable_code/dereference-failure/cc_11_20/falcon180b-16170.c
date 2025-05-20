//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct addrinfo hints, *servinfo, *p;
    char host[MAX_HOSTNAME];
    char data[MAX_DATA];
    int rv;
    struct timespec timeout = { 0, TIMEOUT * 1000000 };

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <data>\n", argv[0]);
        exit(1);
    }

    strcpy(host, argv[1]);
    strcpy(data, argv[2]);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    ret = getaddrinfo(host, NULL, &hints, &servinfo);
    if (ret!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) == -1) {
            perror("setsockopt");
            close(sockfd);
            continue;
        }

        rv = sendto(sockfd, data, strlen(data), 0, p->ai_addr, p->ai_addrlen);
        if (rv == -1) {
            if (errno == ECONNREFUSED) {
                fprintf(stdout, "Connection refused\n");
            } else if (errno == ETIMEDOUT) {
                fprintf(stdout, "Timeout\n");
            } else {
                perror("sendto");
            }
            close(sockfd);
            continue;
        }

        rv = recvfrom(sockfd, data, MAX_DATA, 0, NULL, NULL);
        if (rv == -1) {
            if (errno == ETIMEDOUT) {
                fprintf(stdout, "Timeout\n");
            } else {
                perror("recvfrom");
            }
        } else {
            data[rv] = '\0';
            fprintf(stdout, "Received: %s\n", data);
        }

        close(sockfd);
    }

    freeaddrinfo(servinfo);
    return 0;
}