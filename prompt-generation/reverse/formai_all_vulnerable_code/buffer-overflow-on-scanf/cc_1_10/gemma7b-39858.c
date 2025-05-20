//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

int main()
{
    int sockfd, clientfd, serverfd;
    struct sockaddr_in clientSock, serverSock;
    char buffer[MAX_BUFFER_SIZE];
    char host[256], port[256];
    int nread, nwrite;

    // Get the host and port from the user
    printf("Enter the host: ");
    scanf("%s", host);

    printf("Enter the port: ");
    scanf("%s", port);

    // Create the server socket
    serverfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    if (serverfd == -1)
    {
        perror("Error creating the server socket");
        exit(1);
    }

    // Bind the server socket to the specified host and port
    serverSock.sin_family = AF_INET;
    serverSock.sin_port = htons(atoi(port));
    if (bind(serverfd, (struct sockaddr *)&serverSock, sizeof(serverSock)) == -1)
    {
        perror("Error binding the server socket");
        exit(1);
    }

    // Listen for clients
    listen(serverfd, 1);

    // Accept a client connection
    clientfd = accept(serverfd, (struct sockaddr *)&clientSock, NULL);
    if (clientfd == -1)
    {
        perror("Error accepting the client connection");
        exit(1);
    }

    // Read data from the client
    nread = read(clientfd, buffer, MAX_BUFFER_SIZE);
    if (nread == -1)
    {
        perror("Error reading data from the client");
        exit(1);
    }

    // Write data to the client
    nwrite = write(clientfd, buffer, nread);
    if (nwrite == -1)
    {
        perror("Error writing data to the client");
        exit(1);
    }

    // Close the client connection
    close(clientfd);

    // Close the server socket
    close(serverfd);

    return 0;
}