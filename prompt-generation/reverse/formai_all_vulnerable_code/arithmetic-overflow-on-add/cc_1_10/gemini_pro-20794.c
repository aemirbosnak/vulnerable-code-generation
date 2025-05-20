//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <signal.h>

// Function to measure the round-trip time (RTT) of a network connection
int measure_rtt(int sockfd, struct sockaddr_in *server_addr, socklen_t server_len)
{
    // Create a buffer to send and receive data
    char buffer[1024];

    // Send a message to the server
    int bytes_sent = sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)server_addr, server_len);
    if (bytes_sent < 0) {
        perror("sendto");
        return -1;
    }

    // Wait for a response from the server
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    int bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)server_addr, &server_len);
    gettimeofday(&end_time, NULL);
    if (bytes_received < 0) {
        perror("recvfrom");
        return -1;
    }

    // Calculate the RTT
    int rtt = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;
    return rtt;
}

// Function to measure the throughput of a network connection
int measure_throughput(int sockfd, struct sockaddr_in *server_addr, socklen_t server_len)
{
    // Create a buffer to send and receive data
    char buffer[1024];

    // Send data to the server for 10 seconds
    time_t start_time = time(NULL);
    int total_bytes_sent = 0;
    while (time(NULL) - start_time < 10) {
        int bytes_sent = sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)server_addr, server_len);
        if (bytes_sent < 0) {
            perror("sendto");
            return -1;
        }
        total_bytes_sent += bytes_sent;
    }

    // Calculate the throughput
    int throughput = total_bytes_sent / 10;
    return throughput;
}

// Function to monitor the QoS of a network connection
int monitor_qos(int sockfd, struct sockaddr_in *server_addr, socklen_t server_len)
{
    // Initialize variables to store the QoS metrics
    int rtt, throughput;

    // Loop forever to continuously monitor the QoS
    while (1) {
        // Measure the RTT and throughput
        rtt = measure_rtt(sockfd, server_addr, server_len);
        throughput = measure_throughput(sockfd, server_addr, server_len);

        // Print the QoS metrics
        printf("RTT: %d ms\n", rtt);
        printf("Throughput: %d KB/s\n", throughput);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}

int main(int argc, char *argv[])
{
    // Check if the user has provided the IP address and port number of the server
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        return -1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Set the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));
    socklen_t server_len = sizeof(server_addr);

    // Monitor the QoS of the network connection
    monitor_qos(sockfd, &server_addr, server_len);

    // Close the socket
    close(sockfd);

    return 0;
}