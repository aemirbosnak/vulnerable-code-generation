//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define SERVER_PORT 21
#define BUFFER_SIZE 1024

int main()
{
    char hostname[256];
    char username[256];
    char password[256];
    char filename[256];
    char buffer[BUFFER_SIZE];
    int sockfd, port, len, bytes_read, i;
    struct sockaddr_in server_addr;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    printf("Enter filename: ");
    scanf("%s", filename);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    sprintf(buffer, "USER %s", username);
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "PASS %s", password);
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "RETR %s", filename);
    send(sockfd, buffer, strlen(buffer), 0);

    len = recv(sockfd, buffer, BUFFER_SIZE, 0);

    if (len > 0)
    {
        for (i = 0; i < len; i++)
        {
            printf("%c", buffer[i]);
        }
    }

    close(sockfd);

    return 0;
}