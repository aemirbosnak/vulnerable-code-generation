//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define PORT 5000
#define MAX_BUFFER_SIZE 1024

int main()
{
    int sockfd, newsockfd;
    struct sockaddr_in servaddr, cliaddr;
    int clientlen;
    char buffer[MAX_BUFFER_SIZE];
    time_t start_time, end_time;
    double duration, throughput;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));

    // Bind the socket to a port
    servaddr.sin_port = htons(PORT);
    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Listen for clients
    while (1)
    {
        // Accept a client connection
        clientlen = sizeof(cliaddr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clientlen);

        // Start the timer
        start_time = time(NULL);

        // Receive data
        recv(newsockfd, buffer, MAX_BUFFER_SIZE, 0);

        // End the timer
        end_time = time(NULL);

        // Calculate the duration and throughput
        duration = (double)(end_time - start_time);
        throughput = (double)(MAX_BUFFER_SIZE / duration);

        // Print the results
        printf("Client IP: %s\n", cliaddr.sin_addr.s_addr);
        printf("Duration: %.2f seconds\n", duration);
        printf("Throughput: %.2f Mbps\n", throughput);
        printf("\n");

        // Close the client connection
        close(newsockfd);
    }

    return 0;
}