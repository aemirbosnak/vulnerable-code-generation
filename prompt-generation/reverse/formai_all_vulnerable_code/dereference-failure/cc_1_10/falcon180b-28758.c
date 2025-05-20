//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>

#define MAX_HOST_LEN 1024
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct addrinfo hints, *servinfo, *p;
    char host[MAX_HOST_LEN];
    char data[MAX_DATA_LEN];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s host message\n", argv[0]);
        exit(1);
    }

    strcpy(host, argv[1]);
    strcpy(data, argv[2]);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;

    ret = getaddrinfo(host, NULL, &hints, &servinfo);
    if (ret!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            fprintf(stderr, "socket: %s\n", strerror(errno));
            continue;
        }

        ret = sendto(sockfd, data, strlen(data), 0, p->ai_addr, p->ai_addrlen);
        if (ret == -1) {
            fprintf(stderr, "sendto: %s\n", strerror(errno));
        } else {
            char buf[MAX_DATA_LEN];
            memset(buf, 0, sizeof(buf));
            ret = recvfrom(sockfd, buf, sizeof(buf), 0, NULL, NULL);
            if (ret == -1) {
                fprintf(stderr, "recvfrom: %s\n", strerror(errno));
            } else {
                printf("Received response: %s\n", buf);
            }
        }

        close(sockfd);
    }

    freeaddrinfo(servinfo);

    return 0;
}