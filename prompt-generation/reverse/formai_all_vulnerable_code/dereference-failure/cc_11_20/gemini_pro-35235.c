//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAXLINE 1024

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd;
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connect");
        return EXIT_FAILURE;
    }

    char buffer[MAXLINE];
    int n;

    if ((n = recv(sockfd, buffer, MAXLINE, 0)) < 0)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    if (send(sockfd, "USER username\r\n", 16, 0) < 0)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    if ((n = recv(sockfd, buffer, MAXLINE, 0)) < 0)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    if (send(sockfd, "PASS password\r\n", 16, 0) < 0)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    if ((n = recv(sockfd, buffer, MAXLINE, 0)) < 0)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    if (send(sockfd, "LIST\r\n", 6, 0) < 0)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    if ((n = recv(sockfd, buffer, MAXLINE, 0)) < 0)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s", buffer);

    if (send(sockfd, "QUIT\r\n", 6, 0) < 0)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    if (close(sockfd) < 0)
    {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}