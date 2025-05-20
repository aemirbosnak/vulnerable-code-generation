//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024
#define MAX_HOST_NAME_SIZE 256

int main(int argc, char *argv[]) {
    char hostname[MAX_HOST_NAME_SIZE];
    char data[MAX_DATA_SIZE];
    int sockfd, n;
    struct addrinfo hints, *servinfo, *p;
    int rv;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(hostname, NULL, &hints, &servinfo))!= 0) {
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

    freeaddrinfo(servinfo);

    while (1) {
        printf("Enter a message to send: ");
        fgets(data, MAX_DATA_SIZE, stdin);

        if (strlen(data) == 0) {
            continue;
        }

        n = send(sockfd, data, strlen(data), 0);
        if (n == -1) {
            perror("send");
            close(sockfd);
            exit(1);
        }

        memset(data, 0, MAX_DATA_SIZE);
        n = recv(sockfd, data, MAX_DATA_SIZE, 0);
        if (n == -1) {
            perror("recv");
            close(sockfd);
            exit(1);
        }

        printf("Received message: %s\n", data);
    }

    close(sockfd);

    return 0;
}