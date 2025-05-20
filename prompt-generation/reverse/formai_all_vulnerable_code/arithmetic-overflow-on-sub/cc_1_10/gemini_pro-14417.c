//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;

    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Receive data from the client
    char buffer[1024];
    socklen_t len = sizeof(cliaddr);
    recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len);

    // Measure the time taken to receive data
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Send data back to the client
    sendto(sockfd, buffer, sizeof(buffer), 0, (const struct sockaddr *)&cliaddr, len);

    // Measure the time taken to send data
    gettimeofday(&end, NULL);

    // Calculate the round-trip time
    double time = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

    // Calculate the bandwidth
    double bandwidth = (sizeof(buffer) * 8) / time;

    // Print the results
    printf("Round-trip time: %.2f ms\n", time);
    printf("Bandwidth: %.2f Mbps\n", bandwidth);

    // Close the socket
    close(sockfd);

    return 0;
}