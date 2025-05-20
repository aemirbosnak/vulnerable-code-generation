//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

int main()
{
    char hostname[256];
    int i, port, status, sockfd, timeout = 5;
    struct sockaddr_in servaddr;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &servaddr.sin_addr);

    status = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (status < 0)
    {
        perror("Error connecting to server");
        close(sockfd);
        exit(1);
    }

    printf("Connection established.\n");

    for (i = 0; i < timeout; i++)
    {
        char message[256];
        printf("Enter message: ");
        scanf("%s", message);

        send(sockfd, message, sizeof(message), 0);

        char received_message[256];
        recv(sockfd, received_message, sizeof(received_message), 0);

        printf("Received message: %s\n", received_message);
    }

    close(sockfd);
    return 0;
}