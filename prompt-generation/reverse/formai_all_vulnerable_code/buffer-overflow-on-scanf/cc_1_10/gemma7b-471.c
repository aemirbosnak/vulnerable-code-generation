//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_PINGS 10
#define BUFFER_SIZE 128

int main()
{
    int sockfd, i, j, k, status, port = 53001;
    char hostname[256], buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    struct ping_data
    {
        int seq_num;
        double rtt_ms;
    } pings[MAX_PINGS];

    // Get the hostname from the user
    printf("Enter the hostname: ");
    scanf("%s", hostname);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_aton(hostname, &server_addr.sin_addr);

    // Send and receive pings
    for (i = 0; i < MAX_PINGS; i++)
    {
        pings[i].seq_num = i + 1;
        sprintf(buffer, "Ping %d", pings[i].seq_num);
        sendto(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

        k = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, NULL);
        pings[i].rtt_ms = atof(buffer);
    }

    // Print the results
    printf("Ping results:\n");
    for (i = 0; i < MAX_PINGS; i++)
    {
        printf("Sequence number: %d, RTT: %.2f ms\n", pings[i].seq_num, pings[i].rtt_ms);
    }

    // Close the socket
    close(sockfd);

    return 0;
}