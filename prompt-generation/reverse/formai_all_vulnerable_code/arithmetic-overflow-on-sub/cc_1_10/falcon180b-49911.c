//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "192.168.1.1"

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    int nbytes;
    struct timeval start, end;
    double elapsed_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serv_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    gettimeofday(&start, NULL);

    nbytes = send(sockfd, "GET /test.bin HTTP/1.1\r\nHost: 192.168.1.1\r\nConnection: close\r\n\r\n", strlen("GET /test.bin HTTP/1.1\r\nHost: 192.168.1.1\r\nConnection: close\r\n\r\n"), 0);

    if (nbytes < 0) {
        printf("Error sending request\n");
        exit(1);
    }

    memset(buffer, 0, BUFFER_SIZE);

    nbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (nbytes < 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    gettimeofday(&end, NULL);

    elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0;
    elapsed_time += (end.tv_usec - start.tv_usec) / 1000.0;

    printf("Elapsed time: %f ms\n", elapsed_time);

    close(sockfd);

    return 0;
}