//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    int sockfd, port, i, n, recv_len;
    char buffer[1024];
    struct sockaddr_in serv_addr;

    printf("Enter the port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connection established.\n");

    while (1)
    {
        printf("Enter a message: ");
        scanf("%s", buffer);

        n = send(sockfd, buffer, strlen(buffer), 0);
        if (n < 0)
        {
            perror("Error sending message");
            exit(1);
        }

        recv_len = recv(sockfd, buffer, 1024, 0);
        if (recv_len > 0)
        {
            printf("Received message: %s\n", buffer);
        }
    }

    close(sockfd);
    return 0;
}