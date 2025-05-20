//Gemma-7B DATASET v1.0 Category: Socket programming ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_CLIENTS 10

int main()
{
    int serverSocketfd, clientSocketfd[MAX_CLIENTS], numClients = 0;
    char message[1024], clientName[256];

    // Create a socket for the server
    serverSocketfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    if (serverSocketfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Listen for clients
    while (1)
    {
        // Accept a client connection
        clientSocketfd[numClients] = accept(serverSocketfd, NULL, NULL);
        if (clientSocketfd[numClients] < 0)
        {
            perror("Error accepting client connection");
            exit(1);
        }

        // Get the client name
        recv(clientSocketfd[numClients], clientName, 256, 0);

        // Send a welcome message to the client
        sprintf(message, "Welcome to the server, %s!", clientName);
        send(clientSocketfd[numClients], message, strlen(message), 0);

        // Have the client send a message
        recv(clientSocketfd[numClients], message, 1024, 0);

        // Print the client's message
        printf("Client: %s, Message: %s\n", clientName, message);

        // Close the client connection
        close(clientSocketfd[numClients]);

        // Increment the number of clients
        numClients++;
    }

    return 0;
}