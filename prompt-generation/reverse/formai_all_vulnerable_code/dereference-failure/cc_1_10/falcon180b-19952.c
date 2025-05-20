//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080


int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    while (TRUE) {
        if (send(sockfd, "Hello, World!", strlen("Hello, World!"), 0) < 0) {
            perror("send failed");
            exit(EXIT_FAILURE);
        }
        sleep(1);
    }

    close(sockfd);

    return 0;
}