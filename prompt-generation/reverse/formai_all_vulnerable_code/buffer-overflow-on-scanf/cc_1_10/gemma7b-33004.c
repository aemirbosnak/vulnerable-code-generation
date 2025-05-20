//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int sockfd, newsockfd, portno, i, n;
    char buffer[1024], hostname[256];
    struct sockaddr_in servaddr, cliaddr;

    printf("Please enter the hostname: ");
    scanf("%s", hostname);

    printf("Please enter the port number: ");
    scanf("%d", &portno);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(portno));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(portno);
    servaddr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connected to the server.\n");

    // Send and receive messages
    while (1)
    {
        printf("Enter a message: ");
        scanf("%s", buffer);

        n = write(sockfd, buffer, strlen(buffer) + 1);
        if (n < 0)
        {
            perror("Error sending message");
            exit(1);
        }

        n = read(sockfd, buffer, 1024);
        if (n < 0)
        {
            perror("Error receiving message");
            exit(1);
        }

        printf("Received: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}