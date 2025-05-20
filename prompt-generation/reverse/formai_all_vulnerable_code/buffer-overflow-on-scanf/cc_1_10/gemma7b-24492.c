//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: creative
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int sockfd, newsockfd, port, i, j;
    char buffer[1024];
    struct sockaddr_in serv_addr, client_addr;
    char hostname[256];

    printf("Please enter the hostname:");
    scanf("%s", hostname);

    port = 1;
    for (i = 0; i < 65535; i++)
    {
        serv_addr.sin_port = htons(port);
        sockfd = socket(AF_INET, SOCK_STREAM, htons(0));
        if (sockfd < 0)
        {
            perror("Error creating socket");
            exit(1);
        }

        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0)
        {
            printf("Connection to port %d successful!\n", port);
            break;
        }

        port++;
    }

    if (sockfd < 0)
    {
        perror("Error connecting to port");
        exit(1);
    }

    printf("Enter a message:");
    scanf("%s", buffer);

    write(sockfd, buffer, strlen(buffer));

    read(sockfd, buffer, 1024);

    printf("Received message: %s\n", buffer);

    close(sockfd);

    return 0;
}