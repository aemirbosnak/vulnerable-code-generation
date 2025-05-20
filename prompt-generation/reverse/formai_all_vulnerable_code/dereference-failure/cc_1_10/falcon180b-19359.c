//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_LINE];
    int max_cli_size = sizeof(cli_addr);
    int opt = TRUE;
    int addrlen = sizeof(cli_addr);
    int client_socket;
    char *message = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: 23\r\nConnection: close\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>";

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        perror("socket failed");
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sockfd, BACKLOG) < 0) {
        perror("listen");
        exit(1);
    }

    while (TRUE) {
        memset(buffer, '\0', sizeof(buffer));
        if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(1);
        }

        printf("New connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        send(newsockfd, message, strlen(message), 0);
        close(newsockfd);
    }

    close(sockfd);
    return 0;
}