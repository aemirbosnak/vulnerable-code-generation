//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: happy
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024
#define LISTEN_PORT 5000

int main()
{
    int sockfd;
    struct sockaddr_in servaddr;
    char packet[MAX_PACKET_SIZE];
    int packet_size;
    struct timeval tv_start, tv_end;
    long elapsed_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(LISTEN_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        return 1;
    }

    // Bind the socket to a port
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(LISTEN_PORT);
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error binding socket");
        return 1;
    }

    // Listen for packets
    while (1)
    {
        // Receive a packet
        packet_size = recvfrom(sockfd, packet, MAX_PACKET_SIZE, 0, NULL, NULL);
        if (packet_size < 0)
        {
            perror("Error receiving packet");
            continue;
        }

        // Start the timer
        gettimeofday(&tv_start, NULL);

        // Process the packet
        // (e.g., check for errors, perform calculations, etc.)

        // Stop the timer
        gettimeofday(&tv_end, NULL);

        // Calculate the elapsed time
        elapsed_time = (tv_end.tv_sec - tv_start.tv_sec) * 1000 + (tv_end.tv_usec - tv_start.tv_usec);

        // Print the elapsed time
        printf("Elapsed time: %ld ms\n", elapsed_time);
    }

    return 0;
}