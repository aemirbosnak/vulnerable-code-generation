//Falcon-180B DATASET v1.0 Category: Networking ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX 100

int main(int argc, char *argv[])
{
    int listenfd, connfd, addrlen;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAX];
    int n;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    if(listenfd < 0)
    {
        printf("\n Socket creation failed \n");
        exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(8080);

    if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr))<0)
    {
        printf("\nbind failed \n");
        exit(0);
    }

    listen(listenfd, 5);

    addrlen = sizeof(cliaddr);
    connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &addrlen);

    if(connfd < 0)
    {
        printf("\n Connection Failed \n");
        exit(0);
    }

    printf("\n Connection Established \n");

    while(1)
    {
        bzero(buffer, MAX);
        n = read(connfd, buffer, MAX);

        if(n < 0)
        {
            printf("\n Reading Error \n");
            exit(0);
        }

        printf("\n Received Data : %s \n", buffer);

        write(connfd, buffer, strlen(buffer));
    }

    close(connfd);
    close(listenfd);

    return 0;
}