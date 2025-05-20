//Falcon-180B DATASET v1.0 Category: Networking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        puts("Socket failed");
        exit(1);
    }

    server = gethostbyname("localhost");

    if (server == NULL)
    {
        puts("No such host");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    portno = 8080;

    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        puts("Connection failed");
        exit(1);
    }

    while(1)
    {
        bzero(buffer, BUFFER_SIZE);

        n = read(sockfd, buffer, BUFFER_SIZE);

        if (n < 0)
        {
            puts("Reading error");
            exit(1);
        }

        printf("Server message : %s\n", buffer);

        bzero(buffer, BUFFER_SIZE);

        printf("Enter your message : ");

        fgets(buffer, BUFFER_SIZE, stdin);

        n = write(sockfd, buffer, strlen(buffer));

        if (n < 0)
        {
            puts("Writing error");
            exit(1);
        }
    }

    close(sockfd);

    return 0;
}