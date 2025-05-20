//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct addrinfo hints, *servinfo, *p;
    char s[INET6_ADDRSTRLEN];
    int rv;
    int numbytes;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    if ((rv = getaddrinfo("localhost", "80", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if (p->ai_family == AF_INET) {
            inet_ntop(AF_INET, &((struct sockaddr_in *)p->ai_addr)->sin_addr, s, sizeof(s));
            printf("IPv4 address: %s\n", s);
        } else if (p->ai_family == AF_INET6) {
            inet_ntop(AF_INET6, &((struct sockaddr_in6 *)p->ai_addr)->sin6_addr, s, sizeof(s));
            printf("IPv6 address: %s\n", s);
        }
    }

    freeaddrinfo(servinfo);

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    char buffer[MAX_DATA_SIZE];

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        numbytes = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);

        if (numbytes <= 0) {
            break;
        }

        buffer[numbytes] = '\0';
        printf("Received: %s\n", buffer);
    }

    close(sock);

    return 0;
}