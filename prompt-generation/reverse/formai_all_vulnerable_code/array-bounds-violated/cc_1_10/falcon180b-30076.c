//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 21
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char sendbuf[BUF_SIZE], recvbuf[BUF_SIZE];
    char *filename = argv[2];

    if (argc!= 3) {
        printf("Usage: %s <server_ip> <filename>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    sprintf(sendbuf, "STOR %s\r\n", filename);
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    bzero(recvbuf, BUF_SIZE);
    n = recv(sockfd, recvbuf, BUF_SIZE, 0);
    recvbuf[n] = '\0';
    printf("Server response: %s\n", recvbuf);

    sprintf(sendbuf, "RETR %s\r\n", filename);
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    bzero(recvbuf, BUF_SIZE);
    while ((n = recv(sockfd, recvbuf, BUF_SIZE, 0)) > 0) {
        recvbuf[n] = '\0';
        printf("%s", recvbuf);
    }

    close(sockfd);
    return 0;
}