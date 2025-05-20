//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_PINGS 10

int main()
{
    int sockfd, port, i, j, k, sr, time_sent, time_received;
    char hostname[256];
    struct sockaddr_in serv_addr;
    struct ping_packet
    {
        int seq_num;
        char data[1024];
    } ping_packet;

    // Get the hostname from the user
    printf("Enter the hostname: ");
    scanf("%s", hostname);

    // Set the port number
    port = 8080;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));

    // Connect to the server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(hostname);
    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // Send and receive ping packets
    for (i = 0; i < MAX_PINGS; i++)
    {
        // Create a ping packet
        ping_packet.seq_num = i;
        for (j = 0; j < 1024; j++)
        {
            ping_packet.data[j] = 'a' + i;
        }

        // Send the packet
        send(sockfd, &ping_packet, sizeof(ping_packet), 0);

        // Receive the packet
        recv(sockfd, &ping_packet, sizeof(ping_packet), 0);

        // Print the results
        printf("Ping %d: ", ping_packet.seq_num);
        time_sent = time(NULL);
        time_received = time(NULL);
        printf("Time sent: %.2f seconds\n", time_sent - time_received);
        printf("Time received: %.2f seconds\n", time_received - time_sent);
        printf("Round-trip time: %.2f milliseconds\n", (time_sent - time_received) * 1000);
        printf("\n");
    }

    // Close the socket
    close(sockfd);

    return 0;
}