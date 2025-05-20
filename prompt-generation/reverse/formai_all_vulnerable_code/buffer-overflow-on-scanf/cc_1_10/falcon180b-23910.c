//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    char *host;
    struct addrinfo hints, *servinfo, *p;
    char buffer[BUF_SIZE];
    int speed = 0;
    double start_time, end_time;

    printf("Enter hostname or IP address: ");
    scanf("%s", host);

    printf("Enter port number: ");
    scanf("%d", &portno);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((n = getaddrinfo(host, NULL, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(n));
        exit(1);
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);

    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    start_time = clock();

    while (speed < 1024) {
        memset(buffer, 0, BUF_SIZE);
        n = read(sockfd, buffer, BUF_SIZE);
        if (n <= 0) {
            break;
        }
        speed += n;
    }

    end_time = clock();

    printf("Internet speed: %d bytes/second\n", speed);

    close(sockfd);

    return 0;
}