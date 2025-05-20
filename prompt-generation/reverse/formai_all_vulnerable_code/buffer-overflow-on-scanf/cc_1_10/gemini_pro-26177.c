//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
    int sockfd, port;
    struct sockaddr_in server_addr;

    // Get the port number from the user
    printf("Enter the port number: ");
    scanf("%d", &port);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    const char *message = "Hello, world!";
    if (send(sockfd, message, strlen(message), 0) == -1)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive a message from the server
    char buffer[1024];
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Print the message received from the server
    printf("Received: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}