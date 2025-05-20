//Gemma-7B DATASET v1.0 Category: Networking ; Style: Alan Turing
#include <stdio.h>
#include <sys/socket.h>

int main()
{
    int sockfd, newsockfd, portno = 5000;
    char buffer[1024];

    // Socket setup
    sockfd = socket(AF_INET, SOCK_STREAM, htons(portno));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        return 1;
    }

    // Listening for connections
    listen(sockfd, 10);

    // Accept a connection
    newsockfd = accept(sockfd, NULL, NULL);
    if (newsockfd < 0)
    {
        perror("Error accepting connection");
        return 1;
    }

    // Send and receive messages
    while (1)
    {
        // Receive a message
        int recv_len = recv(newsockfd, buffer, 1024, 0);
        if (recv_len < 0)
        {
            perror("Error receiving message");
            break;
        }

        // Print the message
        printf("Received: %s\n", buffer);

        // Send a message
        printf("Enter your message: ");
        scanf("%s", buffer);

        // Send the message
        int send_len = send(newsockfd, buffer, strlen(buffer) + 1, 0);
        if (send_len < 0)
        {
            perror("Error sending message");
            break;
        }

        // Check if the client has disconnected
        if (recv_len == 0)
        {
            break;
        }
    }

    // Close the socket
    close(newsockfd);
    close(sockfd);

    return 0;
}