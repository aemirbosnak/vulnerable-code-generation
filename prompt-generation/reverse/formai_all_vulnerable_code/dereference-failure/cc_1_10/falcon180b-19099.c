//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    int len;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    while (1) {
        bzero(buffer, BUF_SIZE);
        len = recv(sockfd, buffer, BUF_SIZE, 0);
        if (len <= 0) {
            printf("Disconnected from server\n");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
        printf("Received data: %s\n", buffer);
    }

    return 0;
}