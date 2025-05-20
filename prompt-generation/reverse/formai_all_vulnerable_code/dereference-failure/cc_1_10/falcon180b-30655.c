//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOST_LEN 1024
#define MAX_SERVICE_LEN 1024
#define MAX_DATAGRAM_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char host[MAX_HOST_LEN];
    char service[MAX_SERVICE_LEN];
    int rv, numbytes;
    char datagram[MAX_DATAGRAM_SIZE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s host service\n", argv[0]);
        exit(1);
    }

    strcpy(host, argv[1]);
    strcpy(service, argv[2]);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    if ((rv = getaddrinfo(host, service, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect\n");
        exit(1);
    }

    while (1) {
        if ((numbytes = recv(sockfd, datagram, MAX_DATAGRAM_SIZE, 0)) <= 0) {
            if (numbytes == 0) {
                fprintf(stdout, "Connection closed by remote host\n");
            } else {
                perror("recv");
            }
            close(sockfd);
            exit(1);
        }

        datagram[numbytes] = '\0';
        fprintf(stdout, "Received %d bytes: %s\n", numbytes, datagram);
    }

    return 0;
}