//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void handle_client(int sockfd) {
    char buf[256];
    while (1) {
        bzero(buf, sizeof(buf));
        ssize_t len = recv(sockfd, buf, sizeof(buf) - 1, 0);
        if (len < 0) {
            perror("recv");
            break;
        }
        buf[len] = '\0';

        if (strcmp(buf, "exit") == 0) {
            close(sockfd);
            break;
        }

        printf("Received message from client: %s\n", buf);

        send(sockfd, "ACK", 3, 0);
    }

    close(sockfd);
}

int main() {
    int sockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buf[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8888);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(sockfd, 3) < 0) {
        perror("listen");
        return 1;
    }

    clilen = sizeof(cli_addr);
    sockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (sockfd < 0) {
        perror("accept");
        return 1;
    }

    printf("New client connected: %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    handle_client(sockfd);

    return 0;
}