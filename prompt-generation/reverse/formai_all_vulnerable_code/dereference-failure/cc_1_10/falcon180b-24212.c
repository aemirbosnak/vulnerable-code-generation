//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if(argc!= 4) {
        fprintf(stderr, "Usage: %s <host> <username> <password>\n", argv[0]);
        return 1;
    }

    char host[256];
    char username[256];
    char password[256];

    strcpy(host, argv[1]);
    strcpy(username, argv[2]);
    strcpy(password, argv[3]);

    struct addrinfo hints, *servinfo;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int rv;
    if((rv = getaddrinfo(host, "21", &hints, &servinfo))!= 0) {
        error("getaddrinfo");
    }

    int sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if(sockfd == -1) {
        error("socket");
    }

    if(connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        error("connect");
    }

    char buffer[BUF_SIZE];
    snprintf(buffer, BUF_SIZE, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    snprintf(buffer, BUF_SIZE, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    char response[BUF_SIZE];
    while(recv(sockfd, response, BUF_SIZE, 0) > 0) {
        printf("%s", response);
    }

    close(sockfd);

    return 0;
}