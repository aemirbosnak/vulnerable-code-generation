//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: retro
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

int main() {
    int sockfd, bytes_sent, bytes_received;
    struct sockaddr_in server_addr;
    struct timeval start_time, end_time;
    double total_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(8080);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    bytes_sent = send(sockfd, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: localhost\r\n\r\n"), 0);
    if (bytes_sent < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    bytes_received = recv(sockfd, NULL, 0, 0);
    if (bytes_received < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    printf("Received %d bytes: ", bytes_received);
    printf("%s", (char *)malloc(bytes_received + 1));
    printf("\n");

    gettimeofday(&start_time, NULL);
    bytes_sent = send(sockfd, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: localhost\r\n\r\n"), 0);
    if (bytes_sent < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    bytes_received = recv(sockfd, NULL, 0, 0);
    if (bytes_received < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    gettimeofday(&end_time, NULL);
    total_time = (double)(end_time.tv_sec - start_time.tv_sec) + (double)(end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    printf("Download time: %.2f seconds\n", total_time);

    close(sockfd);
    return 0;
}