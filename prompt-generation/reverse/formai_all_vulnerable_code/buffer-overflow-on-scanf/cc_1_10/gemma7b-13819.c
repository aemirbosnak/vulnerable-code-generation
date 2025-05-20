//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    int sockfd, n, port = 50001, attempts = 3;
    char host[256];

    printf("Enter the host name: ");
    scanf("%s", host);

    for (int i = 0; i < attempts; i++)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
        if (sockfd == -1)
        {
            perror("Error creating socket");
            exit(1);
        }

        struct sockaddr_in serv_addr;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        serv_addr.sin_addr.s_addr = inet_addr(host);

        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        {
            perror("Error connecting to server");
            close(sockfd);
            continue;
        }

        n = write(sockfd, "PING", 4);
        if (n < 0)
        {
            perror("Error sending ping message");
            close(sockfd);
            continue;
        }

        n = read(sockfd, host, 256);
        if (n < 0)
        {
            perror("Error receiving response");
            close(sockfd);
            continue;
        }

        printf("Received response: %s\n", host);
        close(sockfd);
    }

    return 0;
}