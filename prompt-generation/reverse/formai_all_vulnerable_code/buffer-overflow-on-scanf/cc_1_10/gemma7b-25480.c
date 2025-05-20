//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>

int main()
{
    char host[256];
    int port;
    int sockfd;
    struct sockaddr_in sock_addr;
    struct hostent *hp;
    char buf[1024];

    printf("Enter the host name: ");
    scanf("%s", host);

    printf("Enter the port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connected to %s on port %d\n", host, port);

    while (1)
    {
        printf("Enter your message: ");
        scanf("%s", buf);

        if (send(sockfd, buf, strlen(buf) + 1, 0) < 0)
        {
            perror("Error sending message");
            exit(1);
        }

        recv(sockfd, buf, 1024, 0);

        printf("Received: %s\n", buf);
    }

    close(sockfd);

    return 0;
}