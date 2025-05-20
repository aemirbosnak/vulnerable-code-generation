//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: single-threaded
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main()
{
    int sockfd, clientfd, nread, i, j, k, bytes_sent, total_bytes_sent = 0, total_bytes_received = 0, start_time, end_time;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    server_addr.sin_port = htons(8080);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    clientfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (clientfd < 0)
    {
        perror("Error accepting client");
        exit(1);
    }

    // Start the timer
    start_time = time(NULL);

    // Receive data from the client
    nread = read(clientfd, buffer, BUFFER_SIZE);
    if (nread < 0)
    {
        perror("Error receiving data");
        exit(1);
    }

    // Send data to the client
    bytes_sent = send(clientfd, buffer, nread, 0);
    if (bytes_sent < 0)
    {
        perror("Error sending data");
        exit(1);
    }

    // End the timer
    end_time = time(NULL);

    // Calculate the total bytes sent and received
    total_bytes_sent += bytes_sent;
    total_bytes_received += nread;

    // Print the results
    printf("Total bytes sent: %d\n", total_bytes_sent);
    printf("Total bytes received: %d\n", total_bytes_received);
    printf("Time taken: %d seconds\n", end_time - start_time);

    // Close the socket
    close(sockfd);
    close(clientfd);

    return 0;
}