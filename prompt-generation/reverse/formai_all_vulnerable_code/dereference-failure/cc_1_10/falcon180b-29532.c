//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024


int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo;
    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    int port;
    char buffer[BUFFER_SIZE];
    int n;

    if (argc!= 5) {
        printf("Usage: %s hostname username password port\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[4]);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((n = getaddrinfo(hostname, NULL, &hints, &servinfo))!= 0) {
        printf("getaddrinfo error: %s\n", gai_strerror(n));
        exit(1);
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);

    if (sockfd == -1) {
        printf("socket error\n");
        exit(1);
    }

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen)!= 0) {
        printf("connect error\n");
        exit(1);
    }

    printf("Connected to %s, port %d\n", hostname, port);

    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    while (1) {
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}