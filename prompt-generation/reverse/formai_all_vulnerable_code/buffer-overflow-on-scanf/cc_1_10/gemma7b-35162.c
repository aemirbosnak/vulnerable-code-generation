//Gemma-7B DATASET v1.0 Category: Chat server ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10

int main()
{
    int serverSockfd, clientSockfd[MAX_CLIENTS], i, nClients = 0, port = 8888;
    char buffer[1024], clientName[256];

    // Create a socket
    serverSockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (serverSockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    if (bind(serverSockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    for (;;)
    {
        // Accept a client connection
        clientSockfd[nClients] = accept(serverSockfd, NULL, NULL);
        if (clientSockfd[nClients] < 0)
        {
            perror("Error accepting client connection");
            continue;
        }

        // Get the client name
        recv(clientSockfd[nClients], clientName, 256, 0);

        // Welcome the client
        printf("Client %s has connected.\n", clientName);

        // Have the client send a message
        printf("Client: ");
        scanf("%s", buffer);

        // Send the message to the client
        send(clientSockfd[nClients], buffer, strlen(buffer) + 1, 0);

        // Close the client connection
        close(clientSockfd[nClients]);

        // Increment the number of clients
        nClients++;
    }

    return 0;
}