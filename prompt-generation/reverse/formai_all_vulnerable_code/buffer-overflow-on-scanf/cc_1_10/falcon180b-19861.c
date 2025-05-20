//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50];
    char password[50];
    char buffer[1024];
    int n;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Error: Unable to create socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    inet_pton(AF_INET, "localhost", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error: Unable to connect to server\n");
        exit(1);
    }

    sprintf(buffer, "USER %s\r\n", username);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1)
    {
        printf("Error: Unable to send username\n");
        exit(1);
    }

    sprintf(buffer, "PASS %s\r\n", password);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1)
    {
        printf("Error: Unable to send password\n");
        exit(1);
    }

    while (1)
    {
        n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n <= 0)
        {
            printf("Error: Unable to receive data\n");
            exit(1);
        }

        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}