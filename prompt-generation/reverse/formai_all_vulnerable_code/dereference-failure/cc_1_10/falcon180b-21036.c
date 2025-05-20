//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sockfd, n, ret;
    struct sockaddr_in servaddr;
    char senddata[MAX_DATA_SIZE], recvdata[MAX_DATA_SIZE];
    struct timeval timeout;

    if (argc!= 3) {
        printf("Usage:./ping <IP address> <port number>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    servaddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(senddata, 'A', MAX_DATA_SIZE);
        n = send(sockfd, senddata, MAX_DATA_SIZE, 0);
        if (n == -1) {
            printf("Error sending data\n");
            exit(1);
        }

        memset(recvdata, 0, MAX_DATA_SIZE);
        ret = recv(sockfd, recvdata, MAX_DATA_SIZE, 0);
        if (ret == -1) {
            printf("Error receiving data\n");
            exit(1);
        }

        if (strncmp(senddata, recvdata, MAX_DATA_SIZE)!= 0) {
            printf("Data mismatch\n");
            exit(1);
        }

        printf("Data match\n");
    }

    close(sockfd);
    return 0;
}