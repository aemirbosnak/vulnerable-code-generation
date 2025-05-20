//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024
#define TIMEOUT 5

int main()
{
    int sockfd, client_sockfd, nread, packet_size, bytes_sent, send_timeout, recv_timeout;
    struct sockaddr_in server_addr, client_addr;
    char packet[MAX_PACKET_SIZE];
    time_t start_time, end_time, total_time;
    double avg_delay, packet_loss, utilization;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (client_sockfd < 0)
    {
        perror("Error accepting client");
        exit(1);
    }

    // Start the timer
    start_time = time(NULL);

    // Send and receive packets
    packet_size = recv(client_sockfd, packet, MAX_PACKET_SIZE, 0);
    while (packet_size > 0)
    {
        bytes_sent = send(client_sockfd, packet, packet_size, send_timeout);
        packet_size = recv(client_sockfd, packet, MAX_PACKET_SIZE, recv_timeout);
    }

    // Stop the timer
    end_time = time(NULL);
    total_time = end_time - start_time;

    // Calculate statistics
    avg_delay = (total_time * MAX_PACKET_SIZE) / nread;
    packet_loss = (nread - bytes_sent) * 100.0 / nread;
    utilization = (bytes_sent * 100.0) / (total_time * MAX_PACKET_SIZE);

    // Print statistics
    printf("Average delay: %.2f ms\n", avg_delay);
    printf("Packet loss: %.2f%%\n", packet_loss);
    printf("Utilization: %.2f%%\n", utilization);

    // Close the socket
    close(client_sockfd);
    close(sockfd);

    return 0;
}