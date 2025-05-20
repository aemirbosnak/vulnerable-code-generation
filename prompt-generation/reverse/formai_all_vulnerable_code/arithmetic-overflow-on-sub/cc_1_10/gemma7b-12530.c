//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    int sockfd, newsockfd, port, n, i, j, k, flag = 0;
    struct sockaddr_in servaddr, cliaddr;
    struct timeval tv_start, tv_end, tv_diff;
    char buffer[MAX_BUFFER_SIZE];

    // Define the port number
    port = 8080;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    // Bind the socket to the port
    servaddr.sin_port = htons(port);
    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Listen for connections
    newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, NULL);

    // Start the timer
    gettimeofday(&tv_start, NULL);

    // Receive data
    n = recv(newsockfd, buffer, MAX_BUFFER_SIZE, 0);

    // End the timer
    gettimeofday(&tv_end, NULL);

    // Calculate the time difference
    tv_diff.tv_sec = tv_end.tv_sec - tv_start.tv_sec;
    tv_diff.tv_usec = tv_end.tv_usec - tv_start.tv_usec;

    // Print the results
    printf("Client IP: %s\n", cliaddr.sin_addr.s_addr);
    printf("Time taken: %ld seconds, %ld milliseconds\n", tv_diff.tv_sec, tv_diff.tv_usec);
    printf("Number of bytes received: %d\n", n);

    // Close the connection
    close(newsockfd);

    return 0;
}