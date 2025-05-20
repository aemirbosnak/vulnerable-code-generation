//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define MAX_LINE 1024

int main(int argc, char *argv[])
{
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_LINE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        printf("Error opening socket\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));

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
        memset(buffer, 0, MAX_LINE);

        printf("Enter command: ");
        scanf("%s", buffer);

        if (strcmp(buffer, "LIST") == 0)
        {
            send(sockfd, buffer, strlen(buffer), 0);
            recv(sockfd, buffer, MAX_LINE, 0);
            printf("Server reply: %s\n", buffer);
        }
        else if (strcmp(buffer, "GET") == 0)
        {
            strcat(buffer, " ");
            scanf("%s", buffer + strlen(buffer));
            send(sockfd, buffer, strlen(buffer), 0);
            recv(sockfd, buffer, MAX_LINE, 0);
            printf("Server reply: %s\n", buffer);
        }
        else if (strcmp(buffer, "PUT") == 0)
        {
            strcat(buffer, " ");
            scanf("%s", buffer + strlen(buffer));
            send(sockfd, buffer, strlen(buffer), 0);
            recv(sockfd, buffer, MAX_LINE, 0);
            printf("Server reply: %s\n", buffer);
        }
        else if (strcmp(buffer, "QUIT") == 0)
        {
            send(sockfd, buffer, strlen(buffer), 0);
            close(sockfd);
            exit(0);
        }
        else
        {
            printf("Invalid command\n");
        }
    }

    return 0;
}