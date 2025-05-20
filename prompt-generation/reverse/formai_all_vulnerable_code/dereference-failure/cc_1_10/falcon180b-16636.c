//Falcon-180B DATASET v1.0 Category: Networking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX 100

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    int n;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr, "usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, &serv_addr.sin_addr, server->h_length);
    portno = atoi(argv[2]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("connected\n");

    while (1) {
        bzero(buffer, sizeof(buffer));
        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    exit(0);
}