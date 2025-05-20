//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main()
{
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int len;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1)
    {
        printf("Enter command: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\r\n")] = '\0';

        if (send(sockfd, buffer, strlen(buffer), 0) < 0)
        {
            printf("Error sending command\n");
            exit(1);
        }

        len = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (len < 0)
        {
            printf("Error receiving response\n");
            exit(1);
        }

        buffer[len] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}