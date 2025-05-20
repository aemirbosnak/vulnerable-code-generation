//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 21
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    char buffer[MAX_LINE];
    int n;
    int maxfd;
    fd_set readfds;

    if (argc!= 3) {
        printf("Usage: %s <IP> <PORT>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%d\n", argv[1], atoi(argv[2]));

    while (1) {
        FD_ZERO(&readfds);

        FD_SET(sockfd, &readfds);

        maxfd = sockfd;

        select(maxfd + 1, &readfds, NULL, NULL, NULL);

        if (FD_ISSET(sockfd, &readfds)) {
            memset(buffer, 0, MAX_LINE);

            n = recv(sockfd, buffer, MAX_LINE, 0);

            if (n <= 0) {
                printf("Disconnected\n");
                close(sockfd);
                exit(EXIT_SUCCESS);
            }

            printf("Received: %s", buffer);
        }
    }

    return 0;
}