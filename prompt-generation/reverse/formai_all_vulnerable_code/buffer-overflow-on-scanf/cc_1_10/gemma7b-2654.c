//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define MAX_PINGS 5
#define BUFFER_SIZE 1024

int main()
{
    char host[256];
    char message[BUFFER_SIZE];
    int sockfd, port, n, i, status, attempts = 0;
    struct sockaddr_in srv_addr;

    printf("Enter the host name: ");
    scanf("%s", host);

    printf("Enter the port number: ");
    scanf("%d", &port);

    for (i = 0; i < MAX_PINGS; i++)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

        srv_addr.sin_family = AF_INET;
        srv_addr.sin_port = htons(port);
        srv_addr.sin_addr.s_addr = inet_addr(host);

        connect(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr));

        sprintf(message, "Ping!");
        write(sockfd, message, BUFFER_SIZE);

        n = read(sockfd, message, BUFFER_SIZE);

        if (n > 0)
        {
            printf("Received: %s\n", message);
            attempts = 0;
        }
        else
        {
            attempts++;
            printf("Error: Unable to reach host. Attempts: %d\n", attempts);
        }

        close(sockfd);
    }

    return 0;
}