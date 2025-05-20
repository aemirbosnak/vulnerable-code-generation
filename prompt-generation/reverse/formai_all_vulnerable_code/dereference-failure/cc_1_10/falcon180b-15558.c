//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>

#define MAX_REQUEST 1024
#define MAX_RESPONSE 4096
#define SERVER "www.example.com"
#define PORT "80"

int main(void) {
    int sockfd, newsockfd, portno, clilen, ret, maxfd;
    char buffer[MAX_RESPONSE];
    struct sockaddr_in serv_addr, cli_addr;
    fd_set readfds;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    portno = atoi(PORT);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER);
    serv_addr.sin_port = htons(portno);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server...\n");

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    maxfd = sockfd;

    while (1) {
        ret = select(maxfd + 1, &readfds, NULL, NULL, NULL);
        if (ret == -1) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(sockfd, &readfds)) {
            memset(buffer, 0, MAX_RESPONSE);
            clilen = sizeof(cli_addr);

            ret = recvfrom(sockfd, buffer, MAX_RESPONSE - 1, 0, (struct sockaddr *)&cli_addr, &clilen);
            if (ret == -1) {
                perror("recvfrom");
                exit(EXIT_FAILURE);
            }

            printf("Received response: %s\n", buffer);

            close(sockfd);
            exit(EXIT_SUCCESS);
        }
    }

    return 0;
}