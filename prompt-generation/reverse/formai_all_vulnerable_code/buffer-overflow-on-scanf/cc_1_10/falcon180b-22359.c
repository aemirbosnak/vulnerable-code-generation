//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_HOST 256
#define MAX_PORT 6
#define MAX_DATA 1024

int main(int argc, char *argv[]) {
    int sockfd = 0, n = 0;
    struct addrinfo hints, *servinfo, *p;
    char host[MAX_HOST];
    char port[MAX_PORT];
    char data[MAX_DATA];

    printf("Enter the hostname: ");
    scanf("%s", host);

    printf("Enter the port number: ");
    scanf("%s", port);

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((n = getaddrinfo(host, port, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(n));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            sockfd = 0;
            continue;
        }

        break;
    }

    if (sockfd == 0) {
        fprintf(stderr, "failed to connect\n");
        exit(1);
    }

    printf("Enter the data to send: ");
    scanf("%s", data);

    if (send(sockfd, data, strlen(data), 0) == -1) {
        perror("send");
        exit(1);
    }

    char buffer[MAX_DATA];
    n = recv(sockfd, buffer, MAX_DATA, 0);
    if (n == -1) {
        perror("recv");
        exit(1);
    }

    printf("Received data: %s\n", buffer);

    close(sockfd);

    return 0;
}