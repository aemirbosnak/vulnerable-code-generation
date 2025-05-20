//Gemma-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: realistic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 8080

int main()
{
    int sockfd, n, i, bytes_read, start_time, end_time;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    n = connect(sockfd, NULL, 0);
    if (n < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Start the timer
    start_time = time(NULL);

    // Send a file to the server
    FILE *file = fopen("test.txt", "r");
    if (file)
    {
        while ((bytes_read = fread(buffer, 1, 1024, file)) > 0)
        {
            n = send(sockfd, buffer, bytes_read, 0);
            if (n < 0)
            {
                perror("Error sending file");
                exit(1);
            }
        }
    }

    // End the timer
    end_time = time(NULL);

    // Calculate the time taken
    i = end_time - start_time;

    // Print the time taken
    printf("Time taken to send file: %d seconds", i);

    // Close the socket
    close(sockfd);

    return 0;
}