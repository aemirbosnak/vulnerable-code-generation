//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    int addrlen = sizeof(server_addr);
    int timeout = TIMEOUT * 1000;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid IP address\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, addrlen) == -1) {
        if (errno == ECONNREFUSED) {
            printf("Connection refused\n");
        } else if (errno == ETIMEDOUT) {
            printf("Connection timed out\n");
        } else {
            perror("connect");
        }
        exit(1);
    }

    printf("Connected\n");

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        n = recv(sockfd, buffer, BUF_SIZE - 1, 0);

        if (n <= 0) {
            if (n == 0) {
                printf("Connection closed\n");
            } else {
                perror("recv");
            }
            break;
        }

        buffer[n] = '\0';
        printf("Received: %s", buffer);
    }

    close(sockfd);
    return 0;
}