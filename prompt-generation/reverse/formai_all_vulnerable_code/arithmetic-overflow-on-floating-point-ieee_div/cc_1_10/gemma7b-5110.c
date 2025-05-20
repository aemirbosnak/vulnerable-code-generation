//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define SERVER_PORT 8888
#define BUFFER_SIZE 1024

int main()
{
    int sockfd, newsockfd, clientlen;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[BUFFER_SIZE];
    time_t start_time, end_time, elapsed_time;
    int bytes_received, total_bytes = 0;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));

    // Bind the socket to a port
    servaddr.sin_port = htons(SERVER_PORT);
    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Listen for clients
    clientlen = sizeof(cliaddr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clientlen);

    // Start the timer
    start_time = time(NULL);

    // Receive data
    bytes_received = recv(newsockfd, buffer, BUFFER_SIZE, 0);

    // End the timer
    end_time = time(NULL);

    // Calculate the elapsed time
    elapsed_time = end_time - start_time;

    // Calculate the total number of bytes received
    total_bytes = bytes_received;

    // Print the results
    printf("Client IP: %s\n", cliaddr.sin_addr.s_addr);
    printf("Total bytes received: %d\n", total_bytes);
    printf("Elapsed time: %ld seconds\n", elapsed_time);
    printf("Average speed: %.2f Mbps\n", (double)total_bytes / elapsed_time * 8);

    // Close the socket
    close(newsockfd);
    close(sockfd);

    return 0;
}