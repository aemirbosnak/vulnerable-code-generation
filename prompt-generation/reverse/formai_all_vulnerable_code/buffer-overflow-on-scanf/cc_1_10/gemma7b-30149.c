//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 5000
#define BUFFER_SIZE 1024

// QoS Monitor program

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    time_t start_time, end_time, total_time;
    int packets_sent = 0, packets_received = 0, loss_ratio = 0;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (newsockfd < 0) {
        perror("Error accepting client");
        exit(1);
    }

    // Start the timer
    start_time = time(NULL);

    // Send and receive packets
    while (1) {
        // Send a packet
        printf("Enter packet data: ");
        scanf("%s", buffer);
        send(newsockfd, buffer, BUFFER_SIZE, 0);
        packets_sent++;

        // Receive a packet
        recv(newsockfd, buffer, BUFFER_SIZE, 0);
        packets_received++;
    }

    // End the timer
    end_time = time(NULL);
    total_time = end_time - start_time;

    // Calculate the loss ratio
    loss_ratio = (packets_sent - packets_received) * 100 / packets_sent;

    // Print the results
    printf("Total time: %ld seconds\n", total_time);
    printf("Packets sent: %d\n", packets_sent);
    printf("Packets received: %d\n", packets_received);
    printf("Loss ratio: %d%%\n", loss_ratio);

    // Close the socket
    close(sockfd);

    return 0;
}