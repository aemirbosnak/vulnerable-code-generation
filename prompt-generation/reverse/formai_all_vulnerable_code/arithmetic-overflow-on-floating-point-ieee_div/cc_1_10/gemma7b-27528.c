//Gemma-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

#define SERVER_PORT 8888
#define BUFFER_SIZE 1024

int main()
{
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    double start_time, end_time, total_time;
    int bytes_received;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    server_addr.sin_port = htons(SERVER_PORT);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Wait for a client connection
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (newsockfd < 0)
    {
        perror("Error accepting client connection");
        exit(1);
    }

    // Start the timer
    start_time = time(NULL);

    // Receive data from the client
    bytes_received = recv(newsockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0)
    {
        perror("Error receiving data");
        exit(1);
    }

    // End the timer
    end_time = time(NULL);

    // Calculate the total time
    total_time = end_time - start_time;

    // Print the results
    printf("Test results:\n");
    printf("Number of bytes received: %d\n", bytes_received);
    printf("Total time: %.2f seconds\n", total_time);
    printf("Speed: %.2f Mbps\n", (bytes_received / total_time) * 8);

    // Close the socket
    close(newsockfd);
    close(sockfd);

    return 0;
}