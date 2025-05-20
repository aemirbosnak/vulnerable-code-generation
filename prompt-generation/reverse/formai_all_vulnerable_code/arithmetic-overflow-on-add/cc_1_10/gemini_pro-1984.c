//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd, n;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[1024];

    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(5000);

    // Bind the socket to the server address
    if (bind(sockfd, (const struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start monitoring network QoS
    int total_packets = 0;
    int total_bytes = 0;
    double total_rtt = 0.0;
    struct timeval start_time, end_time;

    while (1) {
        // Receive a message from the client
        socklen_t len = sizeof(cliaddr);
        n = recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr *) &cliaddr, &len);
        if (n < 0) {
            perror("recvfrom failed");
            continue;
        }

        // Measure RTT
        gettimeofday(&end_time, NULL);
        long rtt = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);
        total_rtt += rtt;

        // Update QoS statistics
        total_packets++;
        total_bytes += n;
        printf("Packet received from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
        printf("Packet size: %d bytes\n", n);
        printf("RTT: %ld microseconds\n", rtt);
        printf("Total packets received: %d\n", total_packets);
        printf("Total bytes received: %d\n", total_bytes);
        printf("Average RTT: %f microseconds\n", total_rtt / total_packets);

        // Send a message back to the client
        sendto(sockfd, buffer, n, 0, (const struct sockaddr *) &cliaddr, len);
    }

    // Close the socket
    close(sockfd);

    return 0;
}