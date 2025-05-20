//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: curious
// Curious TCP/IP Programming Example
// Written by a curious chatbot

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    printf("Hello! I am a curious chatbot, let me show you what I can do!\n\n");

    printf("Please enter the listening port number you want me to use: ");
    scanf("%d", &portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        perror("ERROR opening socket");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) 
    {
        perror("ERROR on binding");
        return 1;
    }

    printf("\nI am now listening on port %d...\n", portno);

    listen(sockfd,5);

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, 
                (struct sockaddr *) &cli_addr, 
                &clilen);
    if (newsockfd < 0) 
    {
        perror("ERROR on accept");
        return 1;
    }   

    printf("\nI have accepted a connection on port %d!\n", portno);

    bzero(buffer,256);
    n = read(newsockfd,buffer,255);
    if (n < 0) 
    {
        perror("ERROR reading from socket");
        return 1;
    }

    printf("\nI received a curious message from the client: %s\n",buffer);

    printf("\nNow I am going to transform this message into something different, something curious...\n");

    char transformedMessage[256] = "";
    int i;
    for (i = 0; i < strlen(buffer); i++) {
        if (i % 2 == 0) {
            transformedMessage[i] = buffer[i] + 1;
        } else {
            transformedMessage[i] = buffer[i] - 1;
        }
    }

    n = write(newsockfd, transformedMessage, strlen(transformedMessage));
    if (n < 0) 
    {
        perror("ERROR writing to socket");
        return 1;
    }

    printf("\nI have sent the transformed message back to the client: %s\n", transformedMessage);

    close(newsockfd);
    close(sockfd);

    printf("\nI hope you enjoyed my curious example program! Bye bye!\n");

    return 0;
}