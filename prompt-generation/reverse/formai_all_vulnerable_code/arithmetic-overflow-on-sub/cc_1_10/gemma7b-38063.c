//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 5000
#define BUFFER_SIZE 1024

int main() {
    int sockfd, newsockfd, port, clientlen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    time_t start, end, elapsed;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    server_addr.sin_port = htons(SERVER_PORT);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    clientlen = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen);

    // Start the timer
    start = time(NULL);

    // Receive data from the client
    recv(newsockfd, buffer, BUFFER_SIZE, 0);

    // End the timer
    end = time(NULL);

    // Calculate the elapsed time
    elapsed = end - start;

    // Print the elapsed time
    printf("Elapsed time: %d seconds\n", elapsed);

    // Close the socket
    close(newsockfd);
    close(sockfd);

    return 0;
}