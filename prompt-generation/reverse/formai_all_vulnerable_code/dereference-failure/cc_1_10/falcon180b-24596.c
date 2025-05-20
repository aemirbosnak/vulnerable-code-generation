//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    struct hostent *server;
    int i;

    if (argc < 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("No such host\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    while (1) {
        bzero(buffer, BUF_SIZE);
        fgets(buffer, BUF_SIZE, stdin);
        i = strlen(buffer);
        send(sockfd, buffer, i, 0);
        bzero(buffer, BUF_SIZE);
        recv(sockfd, buffer, BUF_SIZE, 0);
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}