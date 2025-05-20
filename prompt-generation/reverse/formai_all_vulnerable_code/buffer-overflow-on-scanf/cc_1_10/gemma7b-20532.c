//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: beginner-friendly
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

#define PORT_RANGE 1024

int main()
{
    int sockfd, port, err, client_sockfd;
    char buffer[1024];

    printf("Enter the target host: ");
    char host[256];
    scanf("%s", host);

    for (port = 1; port <= PORT_RANGE; port++)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
        if (sockfd == -1)
        {
            perror("Error creating socket");
            continue;
        }

        struct sockaddr_in serv_addr;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(port);
        serv_addr.sin_addr.s_addr = inet_addr(host);

        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        {
            perror("Error connecting to socket");
            close(sockfd);
            continue;
        }

        printf("Connection established on port %d\n", port);

        // Send and receive messages
        write(sockfd, "Hello, world!", 13);
        read(sockfd, buffer, 1024);
        printf("Received: %s\n", buffer);

        close(sockfd);
    }

    return 0;
}