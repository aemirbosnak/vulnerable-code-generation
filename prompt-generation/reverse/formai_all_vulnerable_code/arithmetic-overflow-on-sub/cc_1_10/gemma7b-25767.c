//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024

int main() {
    int sockfd, port, n, i, recv_len, send_len;
    struct sockaddr_in server_addr;
    char buffer[MAX_PACKET_SIZE];
    time_t start_time, end_time, total_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(65535));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    // Start the timer
    start_time = time(NULL);

    // Send a packet
    send_len = sendto(sockfd, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (send_len < 0) {
        perror("Error sending packet");
        exit(1);
    }

    // Receive a packet
    recv_len = recvfrom(sockfd, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)&server_addr, NULL);
    if (recv_len < 0) {
        perror("Error receiving packet");
        exit(1);
    }

    // Stop the timer
    end_time = time(NULL);

    // Calculate the total time
    total_time = end_time - start_time;

    // Print the results
    printf("Packet sent: %s\n", buffer);
    printf("Packet received: %s\n", buffer);
    printf("Time taken: %.2f seconds\n", (double)total_time);

    // Close the socket
    close(sockfd);

    return 0;
}