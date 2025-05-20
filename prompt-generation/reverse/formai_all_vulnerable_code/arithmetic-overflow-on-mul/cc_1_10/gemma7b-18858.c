//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_PACKET_SIZE 1024
#define TIMEOUT 5

int main()
{
    int sockfd, newsockfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAX_PACKET_SIZE];
    int n, bytes_received;
    struct timeval tv;
    long long start_time, end_time, total_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for connections
    newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, NULL);
    if (newsockfd < 0)
    {
        perror("Error accepting connection");
        exit(1);
    }

    // Start the timer
    gettimeofday(&tv, NULL);
    start_time = tv.tv_sec * 1000000 + tv.tv_usec;

    // Receive data
    bytes_received = recv(newsockfd, buffer, MAX_PACKET_SIZE, 0);
    if (bytes_received < 0)
    {
        perror("Error receiving data");
        exit(1);
    }

    // Stop the timer
    gettimeofday(&tv, NULL);
    end_time = tv.tv_sec * 1000000 + tv.tv_usec;

    // Calculate the total time
    total_time = end_time - start_time;

    // Print the results
    printf("Client IP: %s\n", cliaddr.sin_addr.s_addr);
    printf("Bytes received: %d\n", bytes_received);
    printf("Total time: %lld ms\n", total_time);

    // Close the socket
    close(newsockfd);
    close(sockfd);

    return 0;
}