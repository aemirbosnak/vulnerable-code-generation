//Falcon-180B DATASET v1.0 Category: Networking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFLEN 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, ret;
    struct sockaddr_in serv_addr, cli_addr;
    char buf[BUFLEN];

    if (argc < 3) {
        printf("usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("socket failed\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    portno = atoi(argv[2]);
    serv_addr.sin_port = htons(portno);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        printf("connect failed\n");
        exit(1);
    }

    printf("connected to %s:%d\n", argv[1], portno);

    do {
        memset(buf, 0, BUFLEN);
        ret = read(sockfd, buf, BUFLEN);
        if (ret == 0) {
            printf("disconnected\n");
            break;
        }
        printf("received message: %s\n", buf);
    } while (1);

    close(sockfd);
    return 0;
}