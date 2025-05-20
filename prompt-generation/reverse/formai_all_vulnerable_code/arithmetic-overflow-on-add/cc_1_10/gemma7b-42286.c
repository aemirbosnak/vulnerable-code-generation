//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define PORT_SCAN_LIMIT 10

int main()
{
    char host[256];
    int port;
    int sockfd, connfd;
    struct sockaddr_in servaddr;
    struct hostent *hp;

    printf("Enter host name: ");
    scanf("%s", host);

    printf("Enter port number: ");
    scanf("%d", &port);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, htons(port))) == -1)
    {
        perror("Error creating socket");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(host);

    if ((connfd = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) == -1)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connection established.\n");

    for (int i = 0; i < PORT_SCAN_LIMIT; i++)
    {
        port++;
        servaddr.sin_port = htons(port);
        if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == 0)
        {
            printf("Port %d is open.\n", port);
        }
    }

    close(sockfd);
    close(connfd);

    return 0;
}