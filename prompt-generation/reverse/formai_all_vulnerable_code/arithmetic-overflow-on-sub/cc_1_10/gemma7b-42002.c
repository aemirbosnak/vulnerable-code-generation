//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <time.h>

#define MAX_PINGS 10
#define TIMEOUT 2

int main()
{
    int sockfd, port, i, j, k;
    struct sockaddr_in server_addr;
    char ping_message[1024] = "Ping!";
    clock_t start_time, end_time;
    double elapsed_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    // Send and receive pings
    for (i = 0; i < MAX_PINGS; i++)
    {
        start_time = clock();

        // Send the ping message
        sendto(sockfd, ping_message, sizeof(ping_message), NULL, (struct sockaddr *)&server_addr, sizeof(server_addr));

        // Receive the ping response
        recvfrom(sockfd, ping_message, sizeof(ping_message), NULL, (struct sockaddr *)&server_addr, NULL);

        end_time = clock();

        // Calculate the elapsed time
        elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        // Print the results
        printf("Ping: %d, Time: %.2f seconds\n", i + 1, elapsed_time);
    }

    // Close the socket
    close(sockfd);

    return 0;
}