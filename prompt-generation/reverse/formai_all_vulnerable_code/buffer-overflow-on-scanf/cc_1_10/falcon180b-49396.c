//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
#define PORT 21

int main()
{
    int sockfd;
    struct sockaddr_in server_addr;
    char username[20], password[20];
    char command[MAX_LINE_LENGTH];
    char response[MAX_LINE_LENGTH];

    printf("Enter FTP server address: ");
    scanf("%s", &server_addr.sin_addr.s_addr);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_addr.sin_addr.s_addr, &server_addr.sin_addr);

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Connected to FTP server\n");

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    while (1)
    {
        memset(command, 0, MAX_LINE_LENGTH);
        memset(response, 0, MAX_LINE_LENGTH);

        printf("Enter command: ");
        scanf("%s", command);

        send(sockfd, command, strlen(command), 0);

        recv(sockfd, response, MAX_LINE_LENGTH, 0);

        printf("%s\n", response);
    }

    close(sockfd);

    return 0;
}