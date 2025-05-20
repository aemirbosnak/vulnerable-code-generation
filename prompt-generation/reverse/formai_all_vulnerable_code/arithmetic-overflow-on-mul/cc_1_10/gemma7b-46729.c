//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_BUFFER_SIZE 1024

int main() {

    int sockfd, port, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_BUFFER_SIZE];
    int recv_size, send_size, bytes_sent, total_bytes_sent = 0;
    struct timeval tv_start, tv_end;
    double latency, throughput;

    // Define the port number
    port = 8080;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    server_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (client_sockfd < 0) {
        perror("Error accepting client connection");
        exit(1);
    }

    // Start the timer
    gettimeofday(&tv_start, NULL);

    // Receive data from the client
    recv_size = recv(client_sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (recv_size < 0) {
        perror("Error receiving data");
        exit(1);
    }

    // Send data to the client
    send_size = send(client_sockfd, buffer, recv_size, 0);
    if (send_size < 0) {
        perror("Error sending data");
        exit(1);
    }

    // Stop the timer
    gettimeofday(&tv_end, NULL);

    // Calculate latency and throughput
    latency = (tv_end.tv_sec - tv_start.tv_sec) * 1000 + (tv_end.tv_usec - tv_start.tv_usec) / 1000.0;
    throughput = (double)recv_size / latency;

    // Print the results
    printf("Latency: %.2f ms\n", latency);
    printf("Throughput: %.2f Mbps\n", throughput);

    // Close the socket
    close(client_sockfd);
    close(sockfd);

    return 0;
}