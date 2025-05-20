//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char sendbuf[BUF_SIZE], recvbuf[BUF_SIZE];

    if (argc < 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error in socket creation\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error in connecting to server\n");
        exit(1);
    }

    while (1) {
        bzero(sendbuf, BUF_SIZE);
        bzero(recvbuf, BUF_SIZE);

        n = send(sockfd, "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n"), 0);
        if (n < 0) {
            printf("Error in sending data\n");
            exit(1);
        }

        n = recv(sockfd, recvbuf, BUF_SIZE, 0);
        if (n < 0) {
            printf("Error in receiving data\n");
            exit(1);
        }

        printf("Received data: %s\n", recvbuf);
    }

    close(sockfd);
    return 0;
}