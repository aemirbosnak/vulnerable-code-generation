//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_PORT 65535

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <target> <range>\n", argv[0]);
        return 1;
    }

    struct hostent *host;
    struct in_addr *ip;

    int port = atoi(argv[2]);

    if (inet_aton(argv[1], &ip) == 0) {
        fprintf(stderr, "Invalid address\n");
        return 1;
    }

    host = gethostbyname(argv[1]);

    if (host == NULL) {
        fprintf(stderr, "No such host\n");
        return 1;
    }

    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr = *ip;

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return 1;
    }

    printf("Connection established on port %d\n", ntohs(serv_addr.sin_port));

    if (port == MAX_PORT)
        return 0;

    for (port++; port <= MAX_PORT; port++) {
        struct hostent *hp;
        struct in_addr *ip;

        hp = gethostbyaddr((const char *) &serv_addr.sin_addr, sizeof(serv_addr.sin_addr), AF_INET);

        if (hp!= NULL && (strcmp(hp->h_name, host->h_name) == 0 || strcmp(hp->h_name, argv[1]) == 0)) {
            printf("Port %d is already in use\n", ntohs(serv_addr.sin_port));
            return 0;
        }

        if (inet_pton(AF_INET, hp->h_addr, &ip->s_addr) == 1) {
            serv_addr.sin_addr.s_addr = ip->s_addr;
            bzero((char *) &serv_addr, sizeof(serv_addr));

            if (port == MAX_PORT)
                return 0;

            if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
                perror("connect");
                return 1;
            }

            printf("Connection established on port %d\n", ntohs(serv_addr.sin_port));
        }
    }

    return 0;
}