//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <netdb.h>

#define SERVER_NAME "localhost"
#define SERVER_PORT 8080
#define MONITOR_INTERVAL 5

int main()
{
    char buffer[1024] = "";
    int sockfd, n, i, j, k;
    struct sockaddr_in serv_addr;
    time_t start_time, end_time, uptime;
    int uptime_percentage;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));

    // Connect to the server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_NAME);
    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // Start the timer
    start_time = time(NULL);

    // Monitor the server
    while (1)
    {
        // Send a ping message
        send(sockfd, "PING", 5, 0);

        // Receive the server's response
        n = recv(sockfd, buffer, 1024, 0);

        // Check if the server is alive
        if (n > 0)
        {
            // Update the end time
            end_time = time(NULL);

            // Calculate the uptime
            uptime = end_time - start_time;
            uptime_percentage = ( uptime * 100 ) / MONITOR_INTERVAL;

            // Print the uptime percentage
            printf("Uptime: %d%% (Last update: %s)\n", uptime_percentage, ctime(start_time));
        }

        // Sleep for the specified interval
        sleep(MONITOR_INTERVAL);
    }

    // Close the socket
    close(sockfd);

    return 0;
}