//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main()
{
    int sockfd, newsockfd, port, n, i, j, k, t = 0, flag = 0, total_bytes = 0;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    time_t start_time, end_time, total_time = 0;

    // Define the port number
    port = 5000;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to the port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (newsockfd < 0)
    {
        perror("Error accepting client connection");
        exit(1);
    }

    // Start the timer
    start_time = time(NULL);

    // Receive data from the client
    n = recv(newsockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0)
    {
        perror("Error receiving data");
        exit(1);
    }

    // Calculate the total number of bytes received
    total_bytes += n;

    // End the timer
    end_time = time(NULL);

    // Calculate the total time taken
    total_time = end_time - start_time;

    // Print the results
    printf("Client IP: %s\n", client_addr.sin_addr.s_addr);
    printf("Total bytes received: %d\n", total_bytes);
    printf("Total time taken: %d seconds\n", total_time);
    printf("Average speed: %d bytes/second\n", (total_bytes * 8) / total_time);

    // Close the socket
    close(sockfd);
    close(newsockfd);

    return 0;
}