//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int sockfd, newsockfd, port, i, n, clientlen;
    char buffer[1024];
    struct sockaddr_in server_addr, client_addr;

    // Shock me with a port scanner!
    printf("Shocked Port Scanner!\n");
    printf("Enter the target port: ");
    scanf("%d", &port);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for connections
    clientlen = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen);
    if (newsockfd < 0)
    {
        perror("Error accepting connection");
        exit(1);
    }

    // Send a message
    n = write(newsockfd, "Hello, world!", 13);
    if (n < 0)
    {
        perror("Error sending message");
        exit(1);
    }

    // Receive a message
    n = read(newsockfd, buffer, 1024);
    if (n < 0)
    {
        perror("Error receiving message");
        exit(1);
    }

    // Print the message
    printf("Received message: %s\n", buffer);

    // Close the socket
    close(newsockfd);
    close(sockfd);

    return 0;
}