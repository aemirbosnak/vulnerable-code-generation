//Gemma-7B DATASET v1.0 Category: Chat server ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 8888

int main()
{
    int sockfd, newsockfd, port, clilen;
    char buffer[1024];
    struct sockaddr_in server_addr, client_addr;

    // Socket setup
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind to port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    listen(sockfd, &clilen);

    // Accept client connection
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clilen);
    if (newsockfd < 0)
    {
        perror("Error accepting client connection");
        exit(1);
    }

    // Send and receive messages
    while (1)
    {
        // Receive message from client
        recv(newsockfd, buffer, 1024, 0);

        // Print message to server console
        printf("Client: %s\n", buffer);

        // Send message to client
        printf("Server: ");
        scanf("%s", buffer);
        send(newsockfd, buffer, strlen(buffer) + 1, 0);
    }

    // Close client connection
    close(newsockfd);

    // Close server socket
    close(sockfd);

    return 0;
}