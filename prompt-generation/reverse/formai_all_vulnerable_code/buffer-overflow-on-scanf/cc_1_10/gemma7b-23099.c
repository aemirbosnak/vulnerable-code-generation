//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char host[256];
    char port[6];
    int sockfd, newsockfd, portnum;
    struct sockaddr_in serv_addr, cli_addr;

    printf("Enter host name: ");
    scanf("%s", host);

    printf("Enter port number: ");
    scanf("%s", port);

    portnum = atoi(port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(portnum));

    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portnum);
    serv_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, NULL);

    if (newsockfd < 0)
    {
        perror("Error accepting connection");
        exit(1);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}