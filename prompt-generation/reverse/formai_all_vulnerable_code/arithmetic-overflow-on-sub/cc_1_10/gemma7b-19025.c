//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 8080

int main()
{
    int sockfd, newsockfd, portno, clientlen;
    char buffer[1024];
    time_t start, end;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    listen(sockfd, 5);

    // Accept a connection
    newsockfd = accept(sockfd, (struct sockaddr *)NULL, NULL);
    if (newsockfd < 0)
    {
        perror("Error accepting connection");
        exit(1);
    }

    // Start the timer
    start = time(NULL);

    // Receive data
    recv(newsockfd, buffer, 1024, 0);

    // End the timer
    end = time(NULL);

    // Calculate the time taken
    int time_taken = end - start;

    // Print the time taken
    printf("Time taken: %d seconds\n", time_taken);

    // Close the connection
    close(newsockfd);

    // Close the socket
    close(sockfd);

    return 0;
}