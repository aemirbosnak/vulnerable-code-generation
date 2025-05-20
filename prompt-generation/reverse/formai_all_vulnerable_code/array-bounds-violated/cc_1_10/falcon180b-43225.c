//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 1024
#define PORT "21"
#define HOST "localhost"

int main()
{
    int sockfd, newsockfd, portno, clilen, i, valread;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    char *username = "anonymous";
    char *password = "anonymous@example.com";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("socket failed");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, HOST, &serv_addr.sin_addr);
    portno = htons(atoi(PORT));
    serv_addr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("connect failed");
        exit(0);
    }

    printf("connected\n");

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0)
    {
        printf("accept failed");
        exit(0);
    }

    printf("accepted\n");

    send(newsockfd, "220 Welcome to FTP service.\r\n", strlen("220 Welcome to FTP service.\r\n"), 0);
    send(newsockfd, "USER ", strlen("USER "), 0);
    send(newsockfd, username, strlen(username), 0);
    send(newsockfd, "\r\n", strlen("\r\n"), 0);

    while (1)
    {
        bzero(buffer, MAX);
        valread = recv(newsockfd, buffer, MAX, 0);
        if (valread <= 0)
        {
            printf("disconnected\n");
            break;
        }
        buffer[valread] = '\0';
        printf("%s", buffer);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}