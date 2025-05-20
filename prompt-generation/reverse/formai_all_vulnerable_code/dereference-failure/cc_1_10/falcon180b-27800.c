//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define MAX_HOST_NAME 256
#define MAX_PORT_NUMBER 6

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[MAX_HOST_NAME];
    char sport[MAX_PORT_NUMBER];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strncpy(s, argv[1], MAX_HOST_NAME - 1);
    s[MAX_HOST_NAME - 1] = '\0';
    snprintf(sport, MAX_PORT_NUMBER, "%s", argv[2]);

    rv = getaddrinfo(s, sport, &hints, &servinfo);
    if (rv!= 0) {
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
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(servinfo);

    char buffer[4096];
    while (fgets(buffer, sizeof(buffer), stdin)!= NULL) {
        send(sockfd, buffer, strlen(buffer), 0);
    }

    close(sockfd);

    return 0;
}