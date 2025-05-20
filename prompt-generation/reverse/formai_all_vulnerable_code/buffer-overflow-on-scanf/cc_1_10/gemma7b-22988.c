//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTS 50

int main()
{
    int i, sockfd, host_num = 0, status;
    char host[MAX_HOSTS][256];
    struct sockaddr_in sock_addr;
    time_t start_time, end_time;
    double rtt_time;

    // Get the hostnames from the user
    printf("Enter the hostnames, separated by commas: ");
    scanf("%s", host);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(8));

    // Set up the socket address
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(53);

    // Start the timer
    start_time = time(NULL);

    // Ping each host
    for (i = 0; i < host_num; i++)
    {
        // Set the host address
        strcpy(sock_addr.sin_addr.s_addr, host[i]);

        // Send a ping message
        sendto(sockfd, "PING", 5, 0, (struct sockaddr *)&sock_addr, sizeof(sock_addr));

        // Receive the reply message
        recvfrom(sockfd, host[i], 256, 0, (struct sockaddr *)&sock_addr, NULL);

        // End the timer
        end_time = time(NULL);

        // Calculate the RTT time
        rtt_time = (double)(end_time - start_time) * 1000;

        // Print the results
        printf("%s: RTT = %.2f ms\n", host[i], rtt_time);
    }

    // Close the socket
    close(sockfd);

    return 0;
}