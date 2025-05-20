//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <time.h>

#define SERVER_PORT 5000
#define BUFFER_SIZE 1024

int main() {
    int sockfd, client_sockfd, server_sock, port;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    time_t start_time, end_time, total_time;
    int num_bytes_received, num_packets_lost, total_packets_sent = 0;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    server_sock = bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (server_sock < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (client_sockfd < 0) {
        perror("Error accepting client");
        exit(1);
    }

    // Start the timer
    start_time = time(NULL);

    // Receive data from the client
    num_bytes_received = recv(client_sockfd, buffer, BUFFER_SIZE, 0);
    if (num_bytes_received < 0) {
        perror("Error receiving data");
        exit(1);
    }

    // Stop the timer
    end_time = time(NULL);

    // Calculate the total time taken
    total_time = end_time - start_time;

    // Calculate the number of packets lost
    num_packets_lost = total_packets_sent - num_bytes_received;

    // Print the results
    printf("Client IP: %s\n", client_addr.sin_addr.s_addr);
    printf("Total packets sent: %d\n", total_packets_sent);
    printf("Total packets received: %d\n", num_bytes_received);
    printf("Number of packets lost: %d\n", num_packets_lost);
    printf("Total time taken: %d seconds\n", total_time);

    // Close the socket
    close(client_sockfd);
    close(sockfd);

    return 0;
}