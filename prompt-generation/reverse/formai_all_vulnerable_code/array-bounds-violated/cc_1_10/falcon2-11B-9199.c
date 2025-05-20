//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        printf("Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    struct sockaddr_in server;
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[1024];
    int numBytes;

    printf("Connecting to %s\n", url);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Failed to create socket\n");
        return 1;
    }

    bzero((char *)&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(5000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("Failed to connect to server\n");
        return 1;
    }

    printf("Connected\n");

    bzero(buffer, 1024);
    numBytes = read(sockfd, buffer, 1024);
    buffer[numBytes] = '\0';
    printf("Received: %s\n", buffer);

    close(sockfd);

    return 0;
}