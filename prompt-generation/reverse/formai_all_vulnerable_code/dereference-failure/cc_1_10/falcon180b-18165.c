//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    char hostname[MAX_SIZE];
    char service[MAX_SIZE];
    struct addrinfo hints, *serverinfo;
    int sockfd, retval;

    if (argc!= 3) {
        printf("Usage: %s hostname service\n", argv[0]);
        return 1;
    }

    strcpy(hostname, argv[1]);
    strcpy(service, argv[2]);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    retval = getaddrinfo(hostname, service, &hints, &serverinfo);

    if (retval!= 0) {
        printf("getaddrinfo error: %s\n", gai_strerror(retval));
        return 2;
    }

    sockfd = socket(serverinfo->ai_family, serverinfo->ai_socktype, serverinfo->ai_protocol);

    if (sockfd == -1) {
        printf("socket error\n");
        return 3;
    }

    if (connect(sockfd, serverinfo->ai_addr, serverinfo->ai_addrlen) == -1) {
        printf("connect error\n");
        return 4;
    }

    char request[MAX_SIZE];
    sprintf(request, "GET / HTTP/1.0\r\nHost: %s\r\nConnection: close\r\n\r\n", hostname);

    send(sockfd, request, strlen(request), 0);

    char buffer[MAX_SIZE];
    bzero(buffer, MAX_SIZE);

    retval = recv(sockfd, buffer, MAX_SIZE, 0);

    if (retval <= 0) {
        printf("recv error\n");
        return 5;
    }

    printf("HTTP response:\n%s", buffer);

    close(sockfd);
    freeaddrinfo(serverinfo);

    return 0;
}