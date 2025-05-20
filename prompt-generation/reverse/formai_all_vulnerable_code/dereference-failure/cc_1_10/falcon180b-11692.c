//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    struct addrinfo hints, *servinfo, *p;
    char s[NI_MAXHOST];
    int rv;
    int success = 0;
    char *node = argv[1];
    char *service = argv[2];
    int family = AF_INET;

    // Set up hints for getaddrinfo()
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = family;
    hints.ai_socktype = SOCK_STREAM;

    // Get address info for the node and service
    rv = getaddrinfo(node, service, &hints, &servinfo);

    // Check if getaddrinfo() succeeded
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo(): %s\n", gai_strerror(rv));
        exit(1);
    }

    // Loop through all the results and try to connect to each one
    for (p = servinfo; p!= NULL; p = p->ai_next) {
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

        success = 1;
        printf("Successfully connected to %s\n", node);
        break;
    }

    // Close the socket
    close(sockfd);

    return 0;
}