//Gemma-7B DATASET v1.0 Category: Networking ; Style: single-threaded
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define SERVER_ADDR "localhost"

int main()
{
    int sockfd, newsockfd, clientlen;
    struct sockaddr_in serv_addr, client_addr;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        return 1;
    }

    // Bind the socket to a port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error binding socket");
        return 1;
    }

    // Listen for clients
    clientlen = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen);
    if (newsockfd < 0)
    {
        perror("Error accepting client");
        return 1;
    }

    // Receive data from the client
    recv(newsockfd, buffer, 1024, 0);
    printf("Client: %s\n", buffer);

    // Send data to the client
    printf("Server: ");
    scanf("%s", buffer);
    send(newsockfd, buffer, strlen(buffer) + 1, 0);

    // Close the socket
    close(newsockfd);
    close(sockfd);

    return 0;
}