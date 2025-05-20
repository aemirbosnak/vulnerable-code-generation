//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 80
#define TIMEOUT 5

void print_error(const char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[1024];
    strcpy(hostname, argv[1]);

    struct addrinfo hints, *result, *rp;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((getaddrinfo(hostname, NULL, &hints, &result))!= 0) {
        print_error("getaddrinfo");
    }

    for (rp = result; rp!= NULL; rp = rp->ai_next) {
        int sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1) {
            continue;
        }

        if ((connect(sockfd, rp->ai_addr, rp->ai_addrlen))!= -1) {
            printf("Host is reachable\n");
            close(sockfd);
            return 0;
        } else if (errno!= ECONNREFUSED) {
            print_error("connect");
        }

        close(sockfd);
    }

    printf("Host is not reachable\n");
    return 1;
}