//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: grateful
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>

int main()
{
    int sockfd, port, n, i, flag = 0;
    char buffer[1024];
    struct sockaddr_in server_addr;

    printf("Enter the port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connected to the server.\n");

    while (1)
    {
        n = read(sockfd, buffer, 1024);
        if (n > 0)
        {
            for (i = 0; i < n; i++)
            {
                printf("%c", buffer[i]);
            }
            printf("\n");
        }
        else if (n == 0)
        {
            printf("Server has closed the connection.\n");
            break;
        }
        else
        {
            perror("Error reading from socket");
            break;
        }
    }

    close(sockfd);

    return 0;
}