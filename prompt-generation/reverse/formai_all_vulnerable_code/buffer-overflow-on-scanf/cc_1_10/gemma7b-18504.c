//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: invasive
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define PORT_MAX 65535

void scan(char *host, int port)
{
    int sockfd, connfd, n, i;
    struct sockaddr_in servaddr;
    char buffer[1024];

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(host);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(0));
    if (sockfd == -1)
    {
        perror("Error creating socket");
        return;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        perror("Error connecting to server");
        return;
    }

    n = read(sockfd, buffer, 1024);
    if (n > 0)
    {
        printf("Port %d: ", port);
        printf("%s\n", buffer);
    }

    close(sockfd);
    close(connfd);
}

int main()
{
    char host[256];
    int port, i;

    printf("Enter host: ");
    scanf("%s", host);

    printf("Enter port range (separated by commas): ");
    scanf("%d,%d", &port, &i);

    scan(host, port);

    return 0;
}