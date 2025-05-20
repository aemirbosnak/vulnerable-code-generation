//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("socket");
    }

    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        error("gethostbyname");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("connect");
    }

    char response[MAXLINE];
    send(sockfd, "USER ", 5, 0);
    recv(sockfd, response, MAXLINE, 0);
    printf("Server: %s\n", response);

    send(sockfd, "PASS ", 5, 0);
    recv(sockfd, response, MAXLINE, 0);
    printf("Server: %s\n", response);

    send(sockfd, "STAT ", 5, 0);
    recv(sockfd, response, MAXLINE, 0);
    printf("Server: %s\n", response);

    send(sockfd, "LIST ", 5, 0);
    recv(sockfd, response, MAXLINE, 0);
    printf("Server: %s\n", response);

    close(sockfd);

    return 0;
}