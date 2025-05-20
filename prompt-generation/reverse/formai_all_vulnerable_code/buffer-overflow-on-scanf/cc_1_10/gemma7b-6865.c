//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: enthusiastic
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>

int main()
{
    int sockfd, port;
    char hostname[256];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port: ");
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

    // Send and receive messages
    while (1)
    {
        printf("Enter message: ");
        scanf("%s", buffer);

        send(sockfd, buffer, sizeof(buffer), 0);

        recv(sockfd, buffer, sizeof(buffer), 0);

        printf("Received message: %s\n", buffer);

        if (strcmp(buffer, "quit") == 0)
            break;
    }

    close(sockfd);

    return 0;
}