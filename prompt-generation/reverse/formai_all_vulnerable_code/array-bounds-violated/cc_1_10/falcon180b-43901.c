//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT "80"
#define HOST "www.google.com"

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    char buffer[BUFFER_SIZE];
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(HOST, PORT, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen)!= -1) {
            break;
        }

        close(sockfd);
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        exit(1);
    }

    printf("Connected to %s\n", HOST);

    while ((numbytes = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[numbytes] = '\0';
        printf("%s", buffer);
    }

    if (numbytes == -1) {
        perror("recv");
    } else {
        printf("\n");
    }

    close(sockfd);
    freeaddrinfo(servinfo);

    return 0;
}