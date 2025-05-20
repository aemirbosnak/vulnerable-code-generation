//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <time.h>

#define SERVER_PORT 8080
#define MONITOR_INTERVAL 60

int main()
{
    time_t start_time, end_time, uptime_seconds = 0;
    int sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];

    // Socket setup
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Socket error");
        exit(1);
    }

    // Bind the socket to the server port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Bind error");
        exit(1);
    }

    // Monitor loop
    while (1)
    {
        // Get the client connection
        client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);

        // Calculate the uptime
        start_time = time(NULL);
        send(client_sockfd, "Hello, world!", 13, 0);
        end_time = time(NULL);
        uptime_seconds = end_time - start_time;

        // Print the uptime
        printf("Client connected for %d seconds.\n", uptime_seconds);

        // Close the client connection
        close(client_sockfd);
    }

    return 0;
}