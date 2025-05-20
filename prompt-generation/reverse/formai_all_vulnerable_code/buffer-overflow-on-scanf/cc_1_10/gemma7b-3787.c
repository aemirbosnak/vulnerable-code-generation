//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main()
{
    int sockfd, port, n, server_port;
    char buffer[1024];

    printf("Enter the port number: ");
    scanf("%d", &port);

    printf("Enter the server port number: ");
    scanf("%d", &server_port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Enter your message: ");
    scanf("%s", buffer);

    n = send(sockfd, buffer, strlen(buffer) + 1, 0);
    if (n < 0)
    {
        perror("Error sending message");
        exit(1);
    }

    n = recv(sockfd, buffer, 1024, 0);
    if (n < 0)
    {
        perror("Error receiving message");
        exit(1);
    }

    printf("Server's response: %s", buffer);

    close(sockfd);
    return 0;
}