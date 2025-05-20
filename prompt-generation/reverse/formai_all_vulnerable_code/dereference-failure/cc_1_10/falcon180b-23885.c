//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOST 256
#define MAX_DATA 1024

int main(int argc, char *argv[])
{
    int sockfd, ret, hostlen, datalen;
    struct sockaddr_in servaddr;
    char host[MAX_HOST];
    char data[MAX_DATA];

    if (argc < 3)
    {
        printf("Usage: %s <hostname> <data>\n", argv[0]);
        exit(1);
    }

    strncpy(host, argv[1], MAX_HOST);
    strncpy(data, argv[2], MAX_DATA);
    hostlen = strlen(host);
    datalen = strlen(data);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(7);
    inet_pton(AF_INET, host, &servaddr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (ret == -1)
    {
        printf("Error connecting to host\n");
        close(sockfd);
        exit(1);
    }

    send(sockfd, data, datalen, 0);
    ret = recv(sockfd, data, MAX_DATA, 0);
    if (ret == -1)
    {
        printf("Error receiving data\n");
        close(sockfd);
        exit(1);
    }

    printf("Received data: %s\n", data);
    close(sockfd);
    return 0;
}