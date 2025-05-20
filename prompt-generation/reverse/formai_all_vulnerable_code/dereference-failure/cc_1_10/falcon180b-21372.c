//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char hostname[1024];
    strcpy(hostname, argv[1]);

    char port[6];
    strcpy(port, argv[2]);

    int sockfd, numbytes;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(hostname, port, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
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
        sockfd = -1;
    }

    if (sockfd == -1) {
        printf("Failed to connect\n");
        return 1;
    }

    char send_data[BUFFER_SIZE];
    strcpy(send_data, "PING");

    if (send(sockfd, send_data, strlen(send_data), 0)!= strlen(send_data)) {
        perror("send");
        return 1;
    }

    char recv_data[BUFFER_SIZE];
    numbytes = recv(sockfd, recv_data, BUFFER_SIZE, 0);

    if (numbytes <= 0) {
        perror("recv");
        return 1;
    }

    recv_data[numbytes] = '\0';
    printf("Received: %s\n", recv_data);

    close(sockfd);
    return 0;
}