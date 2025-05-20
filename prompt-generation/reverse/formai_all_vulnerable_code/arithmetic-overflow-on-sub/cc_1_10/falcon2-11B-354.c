//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }
    struct sockaddr_in server;
    int sockfd;
    struct timeval start, end;
    int count = 0;
    double avg_ping = 0.0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    server.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }

    gettimeofday(&start, NULL);
    while (count++ < 5) {
        int n = send(sockfd, "GET / HTTP/1.1\r\n\r\n", 33, 0);
        if (n < 0) {
            perror("send");
            exit(1);
        }
        gettimeofday(&end, NULL);
        double ping_time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
        avg_ping += ping_time;
    }
    avg_ping /= 5;
    printf("Average ping time: %.2f ms\n", avg_ping);
    close(sockfd);
    return 0;
}