//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: configurable
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024
#define TIMEOUT 2

int main() {
    int sockfd, newsockfd, clientlen, n, i, j;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_PACKET_SIZE];
    time_t start_time, end_time;
    double latency, throughput;

    // Socket setup
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Wait for clients
    clientlen = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen);
    if (newsockfd < 0) {
        perror("Error accepting client");
        exit(1);
    }

    // Start timer
    start_time = time(NULL);

    // Receive and send data
    n = recv(newsockfd, buffer, MAX_PACKET_SIZE, 0);
    if (n < 0) {
        perror("Error receiving data");
        exit(1);
    }
    send(newsockfd, buffer, n, 0);

    // End timer
    end_time = time(NULL);

    // Calculate latency and throughput
    latency = (double)(end_time - start_time) * 1000 / n;
    throughput = (double)n * 8 / (end_time - start_time);

    // Print results
    printf("Client IP: %s\n", client_addr.sin_addr.s_addr);
    printf("Latency: %.2f ms\n", latency);
    printf("Throughput: %.2f Mbps\n", throughput);

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}