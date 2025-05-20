//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX 1024

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, len;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    struct hostent *server;
    int i;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket failed");
        exit(1);
    }
    
    server = gethostbyname("www.example.com");
    if (server == NULL)
    {
        printf("No such host\n");
        exit(1);
    }
    
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    portno = htons(80);
    serv_addr.sin_port = portno;
    
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect failed");
        exit(1);
    }
    
    printf("Connected to server\n");
    
    while(1)
    {
        bzero(buffer, MAX);
        fgets(buffer, MAX, stdin);
        send(sockfd, buffer, strlen(buffer), 0);
        
        len = recv(sockfd, buffer, MAX, 0);
        if (len <= 0)
        {
            printf("Disconnected from server\n");
            exit(1);
        }
        
        printf("Received from server: %s", buffer);
    }
    
    close(sockfd);
    return 0;
}