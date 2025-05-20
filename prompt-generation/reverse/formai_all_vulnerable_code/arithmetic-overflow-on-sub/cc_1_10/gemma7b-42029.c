//Gemma-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main()
{
    int sockfd, port, n, i, start, end, time_start, time_end, time_taken;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    servaddr.sin_port = htons(8888);
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Start the timer
    time_start = time(NULL);

    // Receive data from the client
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0)
    {
        perror("Error receiving data");
        exit(1);
    }

    // End the timer
    time_end = time(NULL);

    // Calculate the time taken
    time_taken = time_end - time_start;

    // Print the results
    printf("The time taken to receive the data is: %d seconds\n", time_taken);

    // Close the socket
    close(sockfd);

    return 0;
}