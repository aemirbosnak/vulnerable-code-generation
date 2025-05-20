//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define MAX_PORT 65535

int main()
{
    char host[256];
    int port;
    int sockfd;
    struct sockaddr_in srvaddr;
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

    srvaddr.sin_family = AF_INET;
    srvaddr.sin_port = htons(port);
    srvaddr.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr *)&srvaddr, sizeof(srvaddr)) == -1)
    {
        perror("Error connecting to server");
        close(sockfd);
        exit(1);
    }

    printf("Connection established.\n");

    char buffer[1024];
    int bytes_read;

    while ((bytes_read = read(sockfd, buffer, 1024)) > 0)
    {
        printf("Received: %s", buffer);
    }

    close(sockfd);
    exit(0);
}