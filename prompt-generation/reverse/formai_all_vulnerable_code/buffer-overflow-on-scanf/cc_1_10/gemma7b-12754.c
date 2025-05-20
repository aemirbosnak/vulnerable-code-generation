//Gemma-7B DATASET v1.0 Category: Email Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVER_PORT 5000
#define BUFFER_SIZE 1024

int main()
{
    int sockfd, newsockfd, port, clientlen, recv_len;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, client_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    serv_addr.sin_port = htons(SERVER_PORT);
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    listen(sockfd, &clientlen);

    // Accept a client connection
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen);
    if (newsockfd < 0)
    {
        perror("Error accepting client connection");
        exit(1);
    }

    // Receive a message from the client
    recv_len = recv(newsockfd, buffer, BUFFER_SIZE, 0);
    if (recv_len < 0)
    {
        perror("Error receiving message");
        exit(1);
    }

    // Print the message from the client
    printf("Received message: %s", buffer);

    // Send a message to the client
    printf("Enter your message: ");
    scanf("%s", buffer);

    // Send the message to the client
    send(newsockfd, buffer, strlen(buffer) + 1, 0);

    // Close the client connection
    close(newsockfd);

    return 0;
}