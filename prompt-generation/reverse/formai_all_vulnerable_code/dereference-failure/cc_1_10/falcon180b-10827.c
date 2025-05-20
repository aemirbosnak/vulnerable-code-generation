//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

int ping(char* ip);

int main(int argc, char* argv[]) {
    if(argc!= 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }

    char* ip = argv[1];
    int status = ping(ip);

    if(status == 0) {
        printf("Host is reachable.\n");
    } else {
        printf("Host is not reachable.\n");
    }

    return 0;
}

int ping(char* ip) {
    int sockfd;
    struct sockaddr_in server;
    int status;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(7);

    status = connect(sockfd, (struct sockaddr*)&server, sizeof(server));

    if(status == -1) {
        if(errno == ECONNREFUSED) {
            return 1;
        } else {
            perror("connect failed");
            exit(1);
        }
    }

    close(sockfd);
    return 0;
}