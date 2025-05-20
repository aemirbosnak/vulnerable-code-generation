//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024

int main()
{
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    time_t start_time, end_time, elapsed_time;
    int bytes_received, total_bytes_received = 0;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    serv_addr.sin_port = htons(5000);
    serv_addr.sin_family = AF_INET;
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for connections
    while (1)
    {
        // Accept a connection
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0)
        {
            perror("Error accepting connection");
            continue;
        }

        // Start the timer
        start_time = time(NULL);

        // Receive data
        bytes_received = recv(newsockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0)
        {
            perror("Error receiving data");
            close(newsockfd);
            continue;
        }

        // End the timer
        end_time = time(NULL);

        // Calculate the elapsed time
        elapsed_time = end_time - start_time;

        // Calculate the total number of bytes received
        total_bytes_received += bytes_received;

        // Print the results
        printf("Client IP: %s\n", cli_addr.sin_addr.s_addr);
        printf("Bytes received: %d\n", bytes_received);
        printf("Elapsed time: %.2f seconds\n", (double)elapsed_time);
        printf("Total bytes received: %d\n", total_bytes_received);
        printf("\n");

        // Close the connection
        close(newsockfd);
    }

    return 0;
}