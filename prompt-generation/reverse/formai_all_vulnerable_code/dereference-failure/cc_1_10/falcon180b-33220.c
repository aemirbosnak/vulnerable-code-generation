//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOST_LEN 1024
#define MAX_DATA_LEN 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char **argv) {
    int sockfd, ret;
    struct addrinfo hints, *res, *res_cur;
    char host[MAX_HOST_LEN];
    char data[MAX_DATA_LEN];
    int datalen;

    if (argc!= 3) {
        printf("Usage: %s <host> <data>\n", argv[0]);
        return 1;
    }

    strncpy(host, argv[1], MAX_HOST_LEN - 1);
    host[MAX_HOST_LEN - 1] = '\0';

    strncpy(data, argv[2], MAX_DATA_LEN - 1);
    data[MAX_DATA_LEN - 1] = '\0';

    datalen = strlen(data);

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    ret = getaddrinfo(host, NULL, &hints, &res);
    if (ret!= 0) {
        printf("getaddrinfo: %s\n", gai_strerror(ret));
        return 1;
    }

    res_cur = res;
    while (res_cur!= NULL) {
        sockfd = socket(res_cur->ai_family, res_cur->ai_socktype, res_cur->ai_protocol);
        if (sockfd == -1) {
            printf("socket: %s\n", strerror(errno));
            continue;
        }

        ret = connect(sockfd, res_cur->ai_addr, res_cur->ai_addrlen);
        if (ret!= 0) {
            printf("connect: %s\n", strerror(errno));
            close(sockfd);
            sockfd = -1;
            continue;
        }

        break;
    }

    if (sockfd == -1) {
        printf("Could not connect to %s\n", host);
        return 1;
    }

    ret = send(sockfd, data, datalen, 0);
    if (ret!= datalen) {
        printf("send: %s\n", strerror(errno));
        close(sockfd);
        return 1;
    }

    close(sockfd);
    printf("Ping sent to %s\n", host);

    return 0;
}