//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char* argv[])
{
    int sockfd, newsockfd, portno = 8080;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[1025];
    int addrlen = sizeof(cli_addr);
    int con = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        printf("\n Socket creation failed \n");
        exit(0);
    }

    server = gethostbyname("localhost");

    if(server == NULL)
    {
        printf("\n No such host \n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(portno);

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
    {
        printf("\n Connect Failed \n");
        exit(0);
    }

    while(1)
    {
        bzero(buffer, 1025);
        fgets(buffer, 1024, stdin);
        send(sockfd, buffer, strlen(buffer), 0);
        bzero(buffer, 1025);
        recv(sockfd, buffer, 1024, 0);
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}