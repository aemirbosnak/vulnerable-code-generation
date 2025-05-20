//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>

#define SERVER_PORT 8888
#define BUFFER_SIZE 1024

int main()
{
    int sockfd, newsockfd, port, client_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    char ip[20];

    printf("Enter the IP address of the server: ");
    scanf("%s", ip);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    server_addr.sin_port = htons(SERVER_PORT);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for connections
    listen(sockfd, &client_len);

    // Accept a connection
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if (newsockfd < 0)
    {
        perror("Error accepting connection");
        exit(1);
    }

    // Receive data from the client
    recv(newsockfd, buffer, BUFFER_SIZE, 0);

    // Print the data received from the client
    printf("Data received from client: %s\n", buffer);

    // Send data to the client
    printf("Enter data to send to the client: ");
    scanf("%s", buffer);

    // Send data to the client
    send(newsockfd, buffer, BUFFER_SIZE, 0);

    // Close the connection
    close(newsockfd);

    return 0;
}