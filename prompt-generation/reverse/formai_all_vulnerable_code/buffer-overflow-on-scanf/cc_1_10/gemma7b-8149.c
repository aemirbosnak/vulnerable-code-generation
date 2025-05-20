//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: introspective
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main()
{
    int sockfd, port, n, server_port;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct sockaddr_in client_addr;

    printf("Enter the port number you want to scan: ");
    scanf("%d", &port);

    printf("Enter the server port number: ");
    scanf("%d", &server_port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(server_port);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(port);
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    n = listen(sockfd, 1);
    if (n < 0)
    {
        perror("Error listening");
        exit(1);
    }

    while (1)
    {
        int client_sockfd;

        client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
        if (client_sockfd < 0)
        {
            perror("Error accepting connection");
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), client_addr.sin_port);

        n = read(client_sockfd, buffer, BUFFER_SIZE);
        if (n < 0)
        {
            perror("Error reading");
            continue;
        }

        printf("Received: %s\n", buffer);

        n = write(client_sockfd, buffer, BUFFER_SIZE);
        if (n < 0)
        {
            perror("Error writing");
            continue;
        }

        close(client_sockfd);
    }

    close(sockfd);

    return 0;
}