//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_PINGS 10
#define BUFFER_SIZE 128

int main()
{
    int sockfd, port, i, j, k;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    time_t start, end, elapsed;
    int num_pings = 0;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(5));
    if (sockfd == -1)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    // Start the timer
    start = time(NULL);

    // Send and receive pings
    for (i = 0; i < MAX_PINGS; i++)
    {
        // Send a ping
        memset(buffer, 'a', BUFFER_SIZE);
        sendto(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

        // Receive a pong
        recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, NULL);

        // Measure the elapsed time
        end = time(NULL);
        elapsed = end - start;

        // Print the results
        printf("Ping %d: Response time = %.2f seconds\n", num_pings, elapsed);

        // Increment the number of pings
        num_pings++;

        // Reset the start time
        start = time(NULL);
    }

    // Close the socket
    close(sockfd);

    return 0;
}