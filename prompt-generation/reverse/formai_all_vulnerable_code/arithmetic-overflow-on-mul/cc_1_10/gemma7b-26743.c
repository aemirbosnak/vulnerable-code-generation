//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: accurate
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024

int main()
{
    int sockfd, port, num_sent, num_recv, bytes_sent, bytes_recv;
    struct sockaddr_in server_addr;
    char send_buf[MAX_PACKET_SIZE], recv_buf[MAX_PACKET_SIZE];
    time_t start_time, end_time;

    // Define the server port
    port = 8080;

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
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    // Start the timer
    start_time = time(NULL);

    // Send a packet
    num_sent = sendto(sockfd, send_buf, MAX_PACKET_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (num_sent < 0)
    {
        perror("Error sending packet");
        exit(1);
    }

    // Receive a packet
    num_recv = recvfrom(sockfd, recv_buf, MAX_PACKET_SIZE, 0, (struct sockaddr *)&server_addr, NULL);
    if (num_recv < 0)
    {
        perror("Error receiving packet");
        exit(1);
    }

    // End the timer
    end_time = time(NULL);

    // Calculate the time taken
    int time_taken = end_time - start_time;

    // Print the results
    printf("Packet sent: %d bytes\n", num_sent);
    printf("Packet received: %d bytes\n", num_recv);
    printf("Time taken: %d milliseconds\n", time_taken * 1000);

    // Close the socket
    close(sockfd);

    return 0;
}