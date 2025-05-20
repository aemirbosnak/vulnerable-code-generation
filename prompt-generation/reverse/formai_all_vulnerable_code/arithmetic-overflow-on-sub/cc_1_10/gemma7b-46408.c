//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd, newsockfd, port, clientlen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    time_t start_time, end_time;

    // Define the port number
    port = 8080;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to the port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    clientlen = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen);
    if (newsockfd < 0) {
        perror("Error accepting client");
        exit(1);
    }

    // Start the timer
    start_time = time(NULL);

    // Receive data
    recv(newsockfd, buffer, BUFFER_SIZE, NULL);

    // End the timer
    end_time = time(NULL);

    // Calculate the time taken
    int time_taken = end_time - start_time;

    // Print the time taken
    printf("Time taken: %d seconds\n", time_taken);

    // Close the socket
    close(newsockfd);

    return 0;
}