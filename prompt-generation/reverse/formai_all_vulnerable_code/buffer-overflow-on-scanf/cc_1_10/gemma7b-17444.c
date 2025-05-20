//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/stat.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char hostname[256];
    char filename[256];
    char buffer[MAX_BUFFER_SIZE];
    int port;
    int sockfd;
    struct sockaddr_in server_addr;
    struct stat stat_buf;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port: ");
    scanf("%d", &port);

    printf("Enter filename: ");
    scanf("%s", filename);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (stat(filename, &stat_buf) == 0)
    {
        send(sockfd, "FILE_EXISTS", 12, 0);
    }
    else
    {
        send(sockfd, "FILE_NOT_EXISTS", 16, 0);
    }

    while (1)
    {
        int bytes_read = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

        if (bytes_read == 0)
        {
            break;
        }

        printf("Received data: %s", buffer);
    }

    close(sockfd);

    return 0;
}