//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: innovative
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 4096

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE], recvline[MAXLINE];

    if (argc != 3)
    {
        fprintf(stderr, "usage: %s <server address> <port number>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket error");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    {
        perror("inet_pton error");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connect error");
        exit(1);
    }

    while (fgets(sendline, MAXLINE, stdin) != NULL)
    {
        if (write(sockfd, sendline, strlen(sendline)) < 0)
        {
            perror("write error");
            exit(1);
        }
        while ((n = read(sockfd, recvline, MAXLINE)) > 0)
        {
            recvline[n] = 0; /* null terminate */
            if (fputs(recvline, stdout) == EOF)
            {
                perror("fputs error");
                exit(1);
            }
        }
        if (n < 0)
        {
            perror("read error");
            exit(1);
        }
    }

    if (shutdown(sockfd, SHUT_WR) < 0)
    {
        perror("shutdown error");
        exit(1);
    }

    while ((n = read(sockfd, recvline, MAXLINE)) > 0)
    {
        recvline[n] = 0; /* null terminate */
        if (fputs(recvline, stdout) == EOF)
        {
            perror("fputs error");
            exit(1);
        }
    }
    if (n < 0)
    {
        perror("read error");
        exit(1);
    }

    exit(0);
}