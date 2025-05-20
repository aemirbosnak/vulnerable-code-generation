//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main()
{
    char host[256];
    int port = 53;
    int i, j;
    struct sockaddr_in sin;

    printf("Enter host name: ");
    scanf("%s", host);

    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    sin.sin_addr.s_addr = inet_addr(host);

    for (i = 0; i < 5; i++)
    {
        int sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
        if (sockfd < 0)
        {
            perror("Error creating socket");
            exit(1);
        }

        if (connect(sockfd, (struct sockaddr *)&sin, sizeof(sin)) < 0)
        {
            perror("Error connecting to server");
            close(sockfd);
            continue;
        }

        for (j = 0; j < 10; j++)
        {
            char buf[1024];
            printf("Enter message: ");
            scanf("%s", buf);

            send(sockfd, buf, sizeof(buf), 0);

            recv(sockfd, buf, sizeof(buf), 0);

            printf("Received: %s\n", buf);
        }

        close(sockfd);
    }

    return 0;
}