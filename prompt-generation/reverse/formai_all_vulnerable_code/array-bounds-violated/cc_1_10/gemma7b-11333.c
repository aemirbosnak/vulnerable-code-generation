//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10

int main()
{
    int sockfd, newsockfd, client_fd[MAX_CLIENTS], i, j, port = 8888, clients = 0;
    char buffer[1024], msg[1024], username[256];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    struct sockaddr_in my_addr;
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(my_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    while (1)
    {
        newsockfd = accept(sockfd, NULL, NULL);
        if (newsockfd < 0)
        {
            perror("Error accepting client");
            continue;
        }

        // Add the client to the list
        client_fd[clients++] = newsockfd;

        // Send a welcome message to the client
        sprintf(buffer, "Welcome to the C Network Topology Mapper, %s!", username);
        send(newsockfd, buffer, strlen(buffer), 0);

        // Get the client's username
        recv(newsockfd, username, 256, 0);

        // Broadcast the client's username to the other clients
        for (i = 0; i < clients; i++)
        {
            if (client_fd[i] != newsockfd)
            {
                sprintf(msg, "New client connected: %s", username);
                send(client_fd[i], msg, strlen(msg), 0);
            }
        }

        // Close the client's socket
        close(newsockfd);
    }

    return 0;
}