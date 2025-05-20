//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define MAX_PINGS 10

int main()
{
    int sockfd, port, i, j, k, num_pings, sent_bytes, recv_bytes;
    struct sockaddr_in server_addr;
    char buffer[1024];
    time_t start_time, end_time, elapsed_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(65535));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    // Send and receive pings
    num_pings = 0;
    while (num_pings < MAX_PINGS)
    {
        // Send a ping
        start_time = time(NULL);
        sent_bytes = sendto(sockfd, "PING", 5, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (sent_bytes < 0)
        {
            perror("Error sending ping");
            exit(1);
        }

        // Receive a pong
        recv_bytes = recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr *)&server_addr, NULL);
        if (recv_bytes < 0)
        {
            perror("Error receiving pong");
            exit(1);
        }

        // Calculate the elapsed time
        end_time = time(NULL);
        elapsed_time = end_time - start_time;

        // Print the results
        printf("Ping %d: Round-trip time = %d ms\n", num_pings, elapsed_time);

        num_pings++;
    }

    // Close the socket
    close(sockfd);

    return 0;
}