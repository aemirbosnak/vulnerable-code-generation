//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd, newsockfd, portno = 8888, n, i;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[BUFFER_SIZE];
    time_t start, end, elapsed;

    // Socket setup
    sockfd = socket(AF_INET, SOCK_STREAM, htons(portno));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Binding
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listening for clients
    newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, NULL);
    if (newsockfd < 0) {
        perror("Error accepting client connection");
        exit(1);
    }

    // Start timer
    start = time(NULL);

    // Data transfer
    n = read(newsockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("Error reading data");
        exit(1);
    }

    // End timer
    end = time(NULL);

    // Calculate elapsed time
    elapsed = end - start;

    // Print results
    printf("Client IP: %s\n", cliaddr.sin_addr.s_addr);
    printf("Time elapsed: %ld seconds\n", elapsed);
    printf("Data received: %d bytes\n", n);

    // Close connections
    close(newsockfd);
    close(sockfd);

    return 0;
}