//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[1024], recvline[1024];
    struct timeval start, end;
    double time_taken;

    if (argc != 2) {
        printf("usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    gettimeofday(&start, NULL);
    strcpy(sendline, "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: close\r\n\r\n");
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        perror("send");
        exit(1);
    }

    while ((n = recv(sockfd, recvline, 1024, 0)) > 0) {
        if (n < 0) {
            perror("recv");
            exit(1);
        }
    }

    gettimeofday(&end, NULL);
    time_taken = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

    printf("Time taken: %f ms\n", time_taken);
    printf("Speed: %f kbps\n", 8 * (1024.0 / time_taken));

    close(sockfd);
    return 0;
}