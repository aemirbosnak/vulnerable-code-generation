//Gemma-7B DATASET v1.0 Category: Email Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_MSG_SIZE 1024

int main()
{
    int sockfd, newsockfd, port, clientlen;
    char buffer[MAX_MSG_SIZE];
    struct sockaddr_in server_addr, client_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    clientlen = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen);
    if (newsockfd < 0)
    {
        perror("Error accepting client");
        exit(1);
    }

    // Receive a message from the client
    recv(newsockfd, buffer, MAX_MSG_SIZE, 0);
    printf("Received message: %s", buffer);

    // Send a message to the client
    printf("Enter your message: ");
    scanf("%s", buffer);
    send(newsockfd, buffer, MAX_MSG_SIZE, 0);

    // Close the connection
    close(newsockfd);
    close(sockfd);

    return 0;
}