//Gemma-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 8888

int main()
{
    int sockfd, n, i, r, t, start, end, time_start, time_end;
    char buf[1024];

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
    time_start = time(NULL);

    // Send a message to the server
    printf("Enter a message: ");
    scanf("%s", buf);
    write(sockfd, buf, 1024);

    // Receive a message from the server
    r = read(sockfd, buf, 1024);
    if (r < 0)
    {
        perror("Error reading from socket");
        exit(1);
    }

    // End the timer
    time_end = time(NULL);

    // Calculate the time taken
    t = time_end - time_start;

    // Print the time taken
    printf("Time taken: %d seconds\n", t);

    // Close the socket
    close(sockfd);

    return 0;
}