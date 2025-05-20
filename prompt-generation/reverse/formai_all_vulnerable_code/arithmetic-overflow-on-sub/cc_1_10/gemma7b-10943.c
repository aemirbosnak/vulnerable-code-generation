//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <time.h>

#define MAX_PINGS 10
#define SLEEP_TIME 1

int main()
{
    int sockfd;
    struct sockaddr_in server_addr;
    char ping_message[1024];
    int num_pings = 0;
    time_t start_time, end_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.1");
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Send and receive ping messages
    start_time = time(NULL);
    for (num_pings = 0; num_pings < MAX_PINGS; num_pings++)
    {
        // Send a ping message
        sprintf(ping_message, "Ping %d", num_pings);
        send(sockfd, ping_message, strlen(ping_message), 0);

        // Receive a ping message
        recv(sockfd, ping_message, 1024, 0);

        // Print the ping message
        printf("Received: %s\n", ping_message);
    }

    // Close the socket
    close(sockfd);

    // End time
    end_time = time(NULL);

    // Print the total time taken
    printf("Total time taken: %.2f seconds\n", (double)(end_time - start_time) / MAX_PINGS);

    return 0;
}