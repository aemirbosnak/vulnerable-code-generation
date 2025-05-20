//Gemma-7B DATASET v1.0 Category: Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    int sockfd, newsockfd, portnum, len;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in serv_addr, client_addr;

    // Define the port number
    portnum = 8080;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(portnum));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portnum);
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    while (1)
    {
        // Accept a client connection
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &len);
        if (newsockfd < 0)
        {
            perror("Error accepting client connection");
            continue;
        }

        // Receive data from the client
        recv(newsockfd, buffer, MAX_BUFFER_SIZE, 0);
        printf("Client: %s\n", buffer);

        // Send data to the client
        printf("Server: ");
        scanf("%s", buffer);
        send(newsockfd, buffer, MAX_BUFFER_SIZE, 0);

        // Close the client connection
        close(newsockfd);
    }

    return 0;
}