//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buff[256];
    int port = 1234;

    // Creating socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    // Setting up server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(port);

    // Binding socket to local address
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("ERROR on binding");
        exit(1);
    }

    // Listening for incoming connections
    if (listen(sockfd, 5) < 0)
    {
        perror("ERROR on listen");
        exit(1);
    }

    while (1)
    {
        printf("Waiting for connection...\n");
        if ((n = accept(sockfd, (struct sockaddr *)NULL, NULL)) < 0)
        {
            perror("ERROR on accept");
            exit(1);
        }
        printf("Connected to %s:%d\n", inet_ntoa(servaddr.sin_addr), ntohs(servaddr.sin_port));

        // Receiving message from client
        bzero(buff, sizeof(buff));
        n = recv(sockfd, buff, sizeof(buff), 0);
        buff[n] = '\0';
        printf("Message from client: %s\n", buff);

        // Sending reply to client
        sprintf(buff, "From Romeo: %s", buff);
        send(sockfd, buff, strlen(buff), 0);

        // Closing socket
        close(sockfd);
    }

    return 0;
}