//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    if (inet_pton(AF_INET, argv[1], &serveraddr.sin_addr) <= 0) {
        printf("Error: Invalid IP address\n");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        if ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) <= 0) {
            if (n == 0) {
                printf("Server disconnected\n");
            } else {
                perror("recv");
            }
            break;
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}