//Falcon-180B DATASET v1.0 Category: Networking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX 100

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno = 8080;
    unsigned int clilen;
    char buffer[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    printf("Enter the IP address of the remote host: ");
    scanf("%s",buffer);

    server = gethostbyname(buffer);

    if (server == NULL) {
        printf("No such host\n");
        exit(0);
    }

    printf("Enter the port number: ");
    scanf("%d",&portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0) {
        printf("Error connecting\n");
        exit(0);
    }

    while(1)
    {
        bzero(buffer, MAX);
        fgets(buffer, MAX, stdin);
        send(sockfd, buffer, strlen(buffer), 0);

        bzero(buffer, MAX);
        recv(sockfd, buffer, MAX, 0);
        printf("Received message: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}