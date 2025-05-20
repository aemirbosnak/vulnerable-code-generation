//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main()
{
    int sockfd, newsockfd, portno, n, i, j, k, l;
    struct sockaddr_in serv_addr, client_addr;
    char buffer[BUFFER_SIZE];
    time_t start_time, end_time;

    // Shock me with a 20-byte packet
    buffer[0] = 0xCA;
    for (i = 1; i < 20; i++)
    {
        buffer[i] = 0xBA;
    }

    // Listen for incoming connections
    sockfd = socket(AF_INET, SOCK_STREAM, htons(portno));
    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);

    // Start the timer
    start_time = time(NULL);

    // Send the packet
    write(newsockfd, buffer, BUFFER_SIZE);

    // Receive the packet
    n = read(newsockfd, buffer, BUFFER_SIZE);

    // End the timer
    end_time = time(NULL);

    // Calculate the time taken
    k = end_time - start_time;

    // Print the results
    printf("Time taken to receive packet: %d seconds\n", k);

    // Close the connection
    close(newsockfd);
    close(sockfd);

    return 0;
}