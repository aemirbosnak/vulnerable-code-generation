//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    int len = sizeof(serv_addr);
    struct timeval start, end;
    long int msecs;
    int i;
    char buf[100];
    int n;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server address>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, len) < 0) {
        perror("connect");
        exit(1);
    }

    gettimeofday(&start, NULL);
    for (i = 0; i < 100; i++) {
        if ((n = send(sockfd, buf, sizeof(buf), 0)) < 0) {
            perror("send");
            exit(1);
        }
        if ((n = recv(sockfd, buf, sizeof(buf), 0)) < 0) {
            perror("recv");
            exit(1);
        }
    }
    gettimeofday(&end, NULL);
    msecs = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
    printf("Latency: %ld ms\n", msecs);

    return 0;
}