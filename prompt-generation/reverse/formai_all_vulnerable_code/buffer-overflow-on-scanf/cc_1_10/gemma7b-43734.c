//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define PORT 21

int main()
{
    char hostname[256];
    char username[256];
    char password[256];
    char filename[256];
    int sockfd;
    struct sockaddr_in sock_addr;

    printf("Enter hostname:");
    scanf("%s", hostname);

    printf("Enter username:");
    scanf("%s", username);

    printf("Enter password:");
    scanf("%s", password);

    printf("Enter filename:");
    scanf("%s", filename);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));

    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(PORT);
    sock_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == -1)
    {
        perror("Error connecting to server");
        exit(1);
    }

    char buffer[1024];

    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "RETR %s\r\n", filename);
    send(sockfd, buffer, strlen(buffer), 0);

    recv(sockfd, buffer, 1024, 0);

    printf("File received: %s\n", buffer);

    close(sockfd);

    return 0;
}