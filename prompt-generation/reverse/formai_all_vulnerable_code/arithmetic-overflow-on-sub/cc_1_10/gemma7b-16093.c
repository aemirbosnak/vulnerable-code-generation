//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    int sockfd, client_sockfd;
    struct sockaddr_in client_addr;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];
    int bytes_received;
    time_t start_time, end_time;
    double latency;

    // Socket setup
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind server socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8888);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Accept client connection
    client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (client_sockfd < 0)
    {
        perror("Error accepting client connection");
        exit(1);
    }

    // Start timer
    start_time = time(NULL);

    // Receive data
    bytes_received = recv(client_sockfd, buffer, MAX_BUFFER_SIZE, 0);

    // End timer
    end_time = time(NULL);

    // Calculate latency
    latency = (double)(end_time - start_time) * 1000 / bytes_received;

    // Print latency
    printf("Latency: %.2f ms\n", latency);

    // Close sockets
    close(client_sockfd);
    close(sockfd);

    return 0;
}