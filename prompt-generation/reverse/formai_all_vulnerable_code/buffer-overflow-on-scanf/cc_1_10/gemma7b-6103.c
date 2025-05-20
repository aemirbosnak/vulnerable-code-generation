//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define RED_TEAM "Montague"
#define BLUE_TEAM "Capulet"

int main()
{
    char team;
    char host[256];
    int port;
    int sockfd;
    struct sockaddr_in server_addr;
    char message[256];

    printf("Enter your team: (%c) or (%c) ", RED_TEAM[0], BLUE_TEAM[0]);
    scanf("%c", &team);

    printf("Enter the host name: ");
    scanf("%s", host);

    printf("Enter the port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_aton(host, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Enter your message: ");
    scanf("%s", message);

    send(sockfd, message, strlen(message), 0);

    recv(sockfd, message, strlen(message), 0);

    printf("Server's response: %s\n", message);

    close(sockfd);

    return 0;
}