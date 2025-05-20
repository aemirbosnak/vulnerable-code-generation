//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF 1024

int main(int argc, char *argv[]) {
    int sockfd, new_sockfd, portno, clilen;
    char buffer[MAX_BUF];
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len = sizeof(cli_addr);

    if (argc < 2) {
        fprintf(stderr, "usage: %s <portno>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        new_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &cli_len);
        if (new_sockfd < 0) {
            perror("accept");
            exit(1);
        }

        printf("New connection from %s, port %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        memset(buffer, 0, MAX_BUF);
        read(new_sockfd, buffer, MAX_BUF);
        printf("Received: %s\n", buffer);

        close(new_sockfd);
    }

    close(sockfd);

    return 0;
}