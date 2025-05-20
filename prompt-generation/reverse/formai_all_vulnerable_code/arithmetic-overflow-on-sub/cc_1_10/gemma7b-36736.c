//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: calm
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_PINGS 5
#define BUFFER_SIZE 128

int main()
{
    int sockfd, ping_cnt = 0, status;
    struct sockaddr_in srv_addr;
    char buffer[BUFFER_SIZE];

    time_t start_time, end_time;
    double elapsed_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(5));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Set up the server address
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(6666);
    srv_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    // Ping the server
    while (ping_cnt < MAX_PINGS)
    {
        // Send a ping message
        sprintf(buffer, "Ping!");
        sendto(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&srv_addr, sizeof(srv_addr));

        // Receive the ping reply
        recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&srv_addr, NULL);

        // Calculate the elapsed time
        start_time = time(NULL);
        end_time = time(NULL);
        elapsed_time = end_time - start_time;

        // Print the results
        printf("Ping %d: %s, elapsed time: %.2f seconds\n", ping_cnt, buffer, elapsed_time);

        // Increment the ping count
        ping_cnt++;
    }

    // Close the socket
    close(sockfd);

    return 0;
}