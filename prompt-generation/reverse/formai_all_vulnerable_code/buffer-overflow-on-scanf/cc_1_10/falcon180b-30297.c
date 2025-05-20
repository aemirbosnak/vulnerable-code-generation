//Falcon-180B DATASET v1.0 Category: Firewall ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main()
{
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    int opt = 1;
    int addrlen = sizeof(cli_addr);
    char hostname[64];
    int port;

    // Get hostname and port from user input
    printf("Enter hostname: ");
    scanf("%s", hostname);
    printf("Enter port: ");
    scanf("%d", &port);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options on the socket
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Connect to remote server
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0)
    {
        if (inet_aton(hostname, &serv_addr.sin_addr) == 0)
        {
            fprintf(stderr, "Invalid address/name");
            exit(EXIT_FAILURE);
        }
    }

    // Connect to remote server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&addrlen)) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Send data to remote server
    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, BUF_SIZE, stdin);
        send(newsockfd, buffer, strlen(buffer), 0);
    }

    // Close sockets
    close(sockfd);
    close(newsockfd);

    return 0;
}