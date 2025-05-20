//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024
#define PACKET_COUNT 100
#define INTERVAL 1

// Function to calculate round trip time
double calculate_rtt(const struct timeval *start, const struct timeval *end) {
    return (end->tv_sec - start->tv_sec) * 1000.0 + (end->tv_usec - start->tv_usec) / 1000.0;
}

// Function to monitor network QoS
void monitor_qos(const char *ip_address) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    struct timeval start_time, end_time;
    double rtt_values[PACKET_COUNT];
    int i, success_count = 0, lost_count = 0;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Prepare server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    if (inet_aton(ip_address, &server_addr.sin_addr) == 0) {
        perror("Invalid IP address");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Starting QoS monitoring to %s...\n", ip_address);
    for (i = 0; i < PACKET_COUNT; i++) {
        // Get the start time
        gettimeofday(&start_time, NULL);

        // Send a ping packet
        snprintf(buffer, sizeof(buffer), "Ping %d", i);
        if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("Error sending packet");
            lost_count++;
            continue;
        }

        // Set a timeout for receiving response
        fd_set readfds;
        struct timeval timeout;
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        timeout.tv_sec = INTERVAL;
        timeout.tv_usec = 0;

        // Wait for response
        int ready = select(sockfd + 1, &readfds, NULL, NULL, &timeout);
        if (ready > 0) {
            // Receive response
            if (recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL) < 0) {
                perror("Error receiving response");
                lost_count++;
                continue;
            }

            // Get the end time
            gettimeofday(&end_time, NULL);

            // Calculate RTT
            rtt_values[i] = calculate_rtt(&start_time, &end_time);
            printf("Received response: %s, RTT: %.2f ms\n", buffer, rtt_values[i]);
            success_count++;
        } else if (ready == 0) {
            printf("Request timed out.\n");
            lost_count++;
        } else {
            perror("Error during select");
            lost_count++;
        }

        // Sleep for a specified interval
        sleep(INTERVAL);
    }

    // Print summary
    printf("\n--- QoS Monitoring Summary ---\n");
    printf("Packets Sent: %d\n", PACKET_COUNT);
    printf("Packets Received: %d\n", success_count);
    printf("Packets Lost: %d (%.2f%% loss)\n", lost_count, ((double)lost_count / PACKET_COUNT) * 100);
    
    // Calculate and print average RTT
    if (success_count > 0) {
        double total_rtt = 0;
        for (i = 0; i < PACKET_COUNT; i++) {
            if (rtt_values[i] > 0) {
                total_rtt += rtt_values[i];
            }
        }
        printf("Average RTT: %.2f ms\n", total_rtt / success_count);
    } else {
        printf("No packets were received successfully.\n");
    }

    // Cleanup
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    monitor_qos(argv[1]);
    return 0;
}