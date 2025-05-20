//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define INTERVAL 2

void monitorQoS(int sockfd, struct sockaddr_in *server_addr, int count) {
    char buffer[BUFFER_SIZE];
    struct timespec start, end;
    double totalTime = 0.0;

    // Send a test message to the server
    strcpy(buffer, "QoS Monitor Test");
    if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*) server_addr, sizeof(*server_addr)) < 0) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    // Record the start time
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Receive a response from the server
    socklen_t addr_len = sizeof(*server_addr);
    if (recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*) server_addr, &addr_len) < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }

    // Record the end time
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate and print round-trip time
    double timeElapsed = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    printf("Round Trip Time for request %d: %.2f ms\n", count, timeElapsed / 1e6);

    // Calculate total time for continuous monitoring
    totalTime += timeElapsed;

    // Recursive condition to monitor QoS for defined iterations
    if (count < 10) {  // Limit monitoring to 10 iterations
        sleep(INTERVAL);  // Wait for a given interval before the next request
        monitorQoS(sockfd, server_addr, count + 1);
    } else {
        printf("Average Round Trip Time: %.2f ms\n", totalTime / 10 / 1e6);
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    // Filling server information
    server_addr.sin_family = AF_INET;  // IPv4
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Localhost

    // Start monitoring QoS
    monitorQoS(sockfd, &server_addr, 1);

    // Close the socket
    close(sockfd);
    return 0;
}