//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define PING_COUNT 5

// Function to calculate the elapsed time
double elapsed_time(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

// Function to ping the host
int ping(const char *host) {
    struct sockaddr_in addr;
    struct timespec start, end;
    char cmd[128];
    int result;

    // Create socket file descriptor
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Setup the destination address
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = inet_addr(host);

    // Formulate the ping command
    snprintf(cmd, sizeof(cmd), "ping -c 1 -W %d %s > /dev/null", TIMEOUT, host);

    // Send the ICMP echo request
    if (clock_gettime(CLOCK_MONOTONIC, &start) == -1) {
        perror("Clock gettime failed");
        close(sockfd);
        return -1;
    }

    result = system(cmd);

    if (clock_gettime(CLOCK_MONOTONIC, &end) == -1) {
        perror("Clock gettime failed");
        close(sockfd);
        return -1;
    }

    close(sockfd);

    if(result == 0) {
        double time_elapsed = elapsed_time(start, end) * 1000; // Convert seconds to milliseconds
        printf("Ping to %s successful! Time taken: %.2f ms.\n", host, time_elapsed);
        return 1; // Success
    } else {
        printf("Ping to %s failed.\n", host);
        return 0; // Failure
    }
}

// Main function
int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <host_ip_or_name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *target_host = argv[1];
    int successes = 0;
    int failures = 0;

    printf("Starting QoS Monitoring for host: %s\n", target_host);
    printf("----------------------------------------------------\n");

    for (int i = 0; i < PING_COUNT; i++) {
        printf("Ping attempt %d...\n", i + 1);
        if(ping(target_host)) {
            successes++;
        } else {
            failures++;
        }
        sleep(1); // Wait a second before the next ping
    }

    printf("----------------------------------------------------\n");
    printf("Results:\n");
    printf("Successful pings: %d\n", successes);
    printf("Failed pings: %d\n", failures);

    double loss_percentage = (double)failures / PING_COUNT * 100;
    printf("Packet loss: %.2f%%\n", loss_percentage);
    
    if (loss_percentage > 0) {
        printf("Consider checking your network connection!\n");
    } else {
        printf("Network connection is good!\n");
    }

    return EXIT_SUCCESS;
}