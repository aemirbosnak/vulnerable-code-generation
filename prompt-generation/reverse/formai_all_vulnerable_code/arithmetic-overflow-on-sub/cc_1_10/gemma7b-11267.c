//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_PINGS 10

int main()
{
    int sockfd, port = 53000, i, attempts = 0, status = 0;
    struct sockaddr_in server_addr;
    char ping_message[] = "Ping!";
    time_t start_time, end_time, elapsed_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        return 1;
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    // Send and receive pings
    for (i = 0; i < MAX_PINGS && attempts < MAX_PINGS; i++)
    {
        start_time = time(NULL);

        // Send the ping message
        sendto(sockfd, ping_message, sizeof(ping_message), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

        // Receive the ping reply
        char reply[1024];
        int recv_len = recvfrom(sockfd, reply, sizeof(reply), 0, (struct sockaddr *)&server_addr, NULL);

        end_time = time(NULL);
        elapsed_time = end_time - start_time;

        // Print the results
        printf("Ping: %d bytes, time: %.2f seconds\n", recv_len, elapsed_time);

        attempts++;
    }

    // Close the socket
    close(sockfd);

    return 0;
}