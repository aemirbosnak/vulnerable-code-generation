//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int n, len;

    if (argc < 2)
    {
        printf("Usage: %s <port_number>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Error creating socket\n");
        exit(0);
    }

    // Set server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind server address to socket
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error binding socket\n");
        exit(0);
    }

    // Listen for incoming connections
    if (listen(sockfd, 10) < 0)
    {
        printf("Error listening on socket\n");
        exit(0);
    }

    while (1)
    {
        // Accept incoming connection
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
        if (newsockfd < 0)
        {
            printf("Error accepting connection\n");
            exit(0);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        // Send welcome message to client
        sprintf(buffer, "Welcome to the server!");
        send(newsockfd, buffer, strlen(buffer), 0);

        // Receive message from client
        n = recv(newsockfd, buffer, BUFFER_SIZE, 0);
        if (n < 0)
        {
            printf("Error receiving message\n");
            exit(0);
        }

        // Print received message
        buffer[n] = '\0';
        printf("Received message: %s\n", buffer);

        // Close connection
        close(newsockfd);
    }

    return 0;
}