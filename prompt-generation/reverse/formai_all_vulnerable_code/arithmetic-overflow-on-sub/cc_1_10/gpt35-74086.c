//FormAI DATASET v1.0 Category: Network Ping Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_TIMEOUT 2
#define BUFFER_SIZE 1024

void ping(char *ip) {
    struct timeval start, end, timeout;
    struct sockaddr_in target;
    int sockfd;
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Unable to create socket");
        return;
    }

    // Set timeout
    timeout.tv_sec = MAX_TIMEOUT;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("Unable to set socket timeout");
        close(sockfd);
        return;
    }

    // Get target IP address info
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(0);
    target.sin_addr.s_addr = inet_addr(ip);

    // Send ping request
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "ping");
    gettimeofday(&start, NULL);
    if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&target, sizeof(target)) < 0) {
        perror("Unable to send ping request");
        close(sockfd);
        return;
    }

    // Receive ping response
    memset(buffer, 0, sizeof(buffer));
    if (recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL) < 0) {
        perror("Unable to receive ping response");
        close(sockfd);
        return;
    }

    // Calculate ping time
    gettimeofday(&end, NULL);
    double time = (double)(end.tv_usec - start.tv_usec) / 1000 + (double)(end.tv_sec - start.tv_sec) * 1000;

    // Print ping result
    printf("%s responded in %.2f ms!\n", ip, time);

    close(sockfd);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s [ip]\n", argv[0]);
        return 0;
    }

    printf("Starting Ping Test...\n");
    ping(argv[1]);
    printf("Ping Test Complete!\n");

    return 0;
}