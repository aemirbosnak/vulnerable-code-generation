//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <sys/time.h>

#define BUFSIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serveraddr;
    char sendbuffer[BUFSIZE], recvbuffer[BUFSIZE];
    struct timeval timeout;

    if (argc!= 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    strcpy(sendbuffer, "USER ");
    strcat(sendbuffer, argv[2]);
    strcat(sendbuffer, "\r\n");

    strcpy(sendbuffer, "PASS ");
    strcat(sendbuffer, argv[3]);
    strcat(sendbuffer, "\r\n");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("socket failed\n");
        exit(EXIT_FAILURE);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(110);
    inet_pton(AF_INET, argv[1], &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("connect failed\n");
        exit(EXIT_FAILURE);
    }

    if (send(sockfd, sendbuffer, strlen(sendbuffer), 0) == -1) {
        printf("send failed\n");
        exit(EXIT_FAILURE);
    }

    memset(recvbuffer, 0, BUFSIZE);
    n = recv(sockfd, recvbuffer, BUFSIZE, 0);

    if (n <= 0) {
        printf("recv failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Received: %s\n", recvbuffer);

    close(sockfd);
    return 0;
}