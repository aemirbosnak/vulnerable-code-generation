//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    char *hostname;
    int sockfd, numbytes;
    struct hostent *he;
    struct sockaddr_in serveraddr;
    char buffer[BUF_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    he = gethostbyname(hostname);
    if (he == NULL) {
        printf("Host not found\n");
        exit(1);
    }

    memcpy(&serveraddr.sin_addr, he->h_addr, he->h_length);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(7);

    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s\n", hostname);

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        numbytes = recv(sockfd, buffer, BUF_SIZE, 0);
        if (numbytes <= 0) {
            printf("Disconnected from %s\n", hostname);
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}