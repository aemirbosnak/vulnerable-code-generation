//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define MAX_PINGS 10
#define BUFFER_SIZE 1024

int main()
{
    int sockfd, port, i, j, k, n, status, timeout, bytes_sent, bytes_received;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    time_t start_time, end_time, elapsed_time;

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    // Connect to the server
    status = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Send and receive pings
    for (i = 0; i < MAX_PINGS; i++)
    {
        // Send a ping message
        printf("Sending ping...\n");
        bytes_sent = send(sockfd, "PING", 5, 0);

        // Receive the ping response
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        // Calculate the elapsed time
        start_time = time(NULL);
        end_time = time(NULL);
        elapsed_time = end_time - start_time;

        // Print the ping results
        printf("Ping response received: %s bytes in %ld milliseconds\n", bytes_received, elapsed_time);
    }

    // Close the socket
    close(sockfd);

    return 0;
}