//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX 100

int main()
{
    int sockfd, newsockfd, portno, clilen, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");

    if (server == NULL)
    {
        fprintf(stderr, "No such host.\n");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    portno = 8080;

    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

    if (newsockfd < 0)
    {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Connection accepted\n");

    while (1)
    {
        bzero(buffer, MAX);

        sd = recv(newsockfd, buffer, MAX, 0);

        if (sd <= 0)
        {
            fprintf(stdout, "Connection closed by client\n");
            break;
        }

        buffer[sd] = '\0';

        fprintf(stdout, "Received string: %s\n", buffer);

        send(newsockfd, buffer, sd, 0);
    }

    close(newsockfd);

    return 0;
}