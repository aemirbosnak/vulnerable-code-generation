//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFF_SIZE 1024

int main() {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[BUFF_SIZE];
    clock_t start, end;
    double time_taken;

    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(3000);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Send a test message to the server
    start = clock();
    sendto(sockfd, buffer, BUFF_SIZE, 0, (const struct sockaddr *) &servaddr, sizeof(servaddr));

    // Receive the response from the server
    n = recvfrom(sockfd, buffer, BUFF_SIZE, 0, NULL, NULL);
    end = clock();

    // Calculate the time taken for the round trip
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Calculate the bandwidth
    double bandwidth = (BUFF_SIZE / time_taken) * 8 / 1024;

    // Print the bandwidth
    printf("Bandwidth: %.2f kbps\n", bandwidth);

    // Close the socket
    close(sockfd);

    return 0;
}