//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main()
{
    int sockfd, client_sockfd;
    struct sockaddr_in client_addr;
    char buffer[BUFFER_SIZE];
    time_t start_time, end_time;
    int bytes_received, total_bytes_received = 0;
    float avg_delay = 0.0f;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));

    // Bind the socket to a port
    if (bind(sockfd, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);

    // Start the timer
    start_time = time(NULL);

    // Receive data from the client
    while ((bytes_received = recv(client_sockfd, buffer, BUFFER_SIZE, 0)) > 0)
    {
        total_bytes_received += bytes_received;
    }

    // End the timer
    end_time = time(NULL);

    // Calculate the average delay
    avg_delay = (float)(end_time - start_time) * 1000 / total_bytes_received;

    // Print the results
    printf("Total bytes received: %d\n", total_bytes_received);
    printf("Average delay: %.2f ms\n", avg_delay);

    // Close the socket
    close(client_sockfd);

    return 0;
}