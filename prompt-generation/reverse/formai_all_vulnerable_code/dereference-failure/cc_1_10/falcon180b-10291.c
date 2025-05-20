//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[100];
    int n;
    char *hostname = argv[1];
    int max_clients = 5;
    int listener = 0;
    int *client_socket = malloc(max_clients * sizeof(int));

    for(int i=0;i<max_clients;i++)
    {
        client_socket[i] = -1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        printf("socket failed");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    portno = 8080;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if(bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))<0)
    {
        printf("bind failed");
        exit(0);
    }

    listen(sockfd, 5);
    puts("server is listening");

    while(1)
    {
        clilen = sizeof(cli_addr);
        sd = accept(sockfd, (struct sockaddr*)&cli_addr, \
        (socklen_t*)&clilen);
        if(sd < 0)
        {
            printf("accept failed");
            exit(0);
        }

        for(int i=0;i<max_clients;i++)
        {
            if(client_socket[i] == -1)
            {
                client_socket[i] = sd;
                listener = 1;
                break;
            }
        }

        if(listener == 0)
        {
            send(sd, "server is busy\n", strlen("server is busy\n"), 0);
            close(sd);
        }
    }

    return 0;
}