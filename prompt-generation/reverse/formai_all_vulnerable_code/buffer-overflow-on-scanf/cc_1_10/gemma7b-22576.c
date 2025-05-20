//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PINGS 10
#define TIMEOUT 5

int main()
{
    int i, sockfd, port, status, err;
    char hostname[256];
    struct sockaddr_in servaddr;
    struct ping_data
    {
        int sockfd;
        char hostname[256];
        int seq_num;
        time_t timestamp;
    } ping_data_arr[MAX_PINGS];

    // Get the hostname from the user
    printf("Enter the hostname: ");
    scanf("%s", hostname);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(6));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Set up the server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &servaddr.sin_addr);

    // Send and receive ping packets
    for (i = 0; i < MAX_PINGS; i++)
    {
        ping_data_arr[i].sockfd = sockfd;
        ping_data_arr[i].hostname[0] = '\0';
        ping_data_arr[i].seq_num = i;
        ping_data_arr[i].timestamp = time(NULL);

        // Send the ping packet
        sendto(sockfd, &ping_data_arr[i], sizeof(ping_data_arr[i]), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));

        // Receive the ping response
        recvfrom(sockfd, &ping_data_arr[i], sizeof(ping_data_arr[i]), 0, (struct sockaddr *)&servaddr, NULL);

        // Print the ping results
        printf("Ping to %s (seq num %d):\n", ping_data_arr[i].hostname, ping_data_arr[i].seq_num);
        printf("  Time taken: %ld ms\n", ping_data_arr[i].timestamp - ping_data_arr[i].timestamp);
    }

    // Close the socket
    close(sockfd);

    return 0;
}