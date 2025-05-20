//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

int main()
{
    int sockfd, port, n, err, host_num;
    char hostname[256];

    printf("Enter host name: ");
    scanf("%s", hostname);

    printf("Enter port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd == -1)
    {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connection established.\n");

    char buffer[1024];

    while (1)
    {
        printf("Enter message: ");
        scanf("%s", buffer);

        n = send(sockfd, buffer, strlen(buffer) + 1, 0);
        if (n == -1)
        {
            perror("Error sending message");
            exit(1);
        }

        n = recv(sockfd, buffer, 1024, 0);
        if (n == -1)
        {
            perror("Error receiving message");
            exit(1);
        }

        printf("Received message: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}