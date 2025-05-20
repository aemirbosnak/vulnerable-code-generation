//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_CLIENTS 10

int main()
{
    int sockfd, newsockfd, clientfd[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];

    // Bind socket to port 8080
    sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    if (sockfd < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    listen(sockfd, MAX_CLIENTS);

    // Accept client connections
    while (1)
    {
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
        if (newsockfd < 0)
        {
            perror("Error accepting client connection");
            continue;
        }

        // Create a new client socket
        clientfd[newsockfd] = newsockfd;

        // Send a welcome message to the client
        sprintf(buffer, "Welcome to the C Network Topology Mapper, client %d!", newsockfd);
        send(clientfd[newsockfd], buffer, strlen(buffer), 0);

        // Receive client data
        recv(clientfd[newsockfd], buffer, 1024, 0);

        // Print client data
        printf("Client %d: %s\n", newsockfd, buffer);

        // Close client socket
        close(clientfd[newsockfd]);
    }

    return 0;
}