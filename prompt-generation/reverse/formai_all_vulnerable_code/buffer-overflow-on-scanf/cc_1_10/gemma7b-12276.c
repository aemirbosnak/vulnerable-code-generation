//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

int main()
{
    int sockfd, n, port, server_port;
    char server_ip[100];
    char filename[100];
    struct sockaddr_in server_addr;

    printf("Enter server IP address:");
    scanf("%s", server_ip);

    printf("Enter port number:");
    scanf("%d", &port);

    printf("Enter file name:");
    scanf("%s", filename);

    server_port = port;
    sockfd = socket(AF_INET, SOCK_STREAM, htons(server_port));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_aton(server_ip, &server_addr.sin_addr);

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    n = send(sockfd, filename, strlen(filename), 0);

    if (n < 0)
    {
        perror("Error sending file name");
    }

    n = recv(sockfd, filename, 100, 0);

    if (n < 0)
    {
        perror("Error receiving file name");
    }

    printf("File name received: %s\n", filename);

    close(sockfd);

    return 0;
}