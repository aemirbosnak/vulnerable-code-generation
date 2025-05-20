//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define PORT 8080
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_LINE];
    int n;
    int addrlen;
    struct hostent *server;

    if (argc!= 3) {
        printf("usage: %s <IP> <port>\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        perror("socket failed");
        exit(0);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("No such host\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(0);
    }

    while (1) {
        bzero(buffer, MAX_LINE);
        n = read(sockfd, buffer, MAX_LINE);
        if (n <= 0) {
            printf("Connection closed by server\n");
            close(sockfd);
            exit(0);
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    return 0;
}