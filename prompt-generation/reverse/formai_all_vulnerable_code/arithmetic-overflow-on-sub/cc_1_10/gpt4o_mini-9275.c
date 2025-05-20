//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_TIMEOUT 1000000 // Maximum timeout in microseconds
#define PACKET_SIZE 64      // Size of the packet
#define QOS_CHECK_INTERVAL 2 // Check interval in seconds

typedef struct {
    struct sockaddr_in addr;
    int sent_packets;
    int received_packets;
    double min_rtt;
    double max_rtt;
    double total_rtt;
} QoSMonitor;

// Function to calculate the RTT
double calculate_rtt(struct timeval *start, struct timeval *end) {
    return (end->tv_sec - start->tv_sec) * 1000.0 + 
           (end->tv_usec - start->tv_usec) / 1000.0; // Convert to milliseconds
}

// Function to initialize QoS Monitor
void init_monitor(QoSMonitor *monitor, const char *ip) {
    memset(monitor, 0, sizeof(QoSMonitor));
    monitor->sent_packets = 0;
    monitor->received_packets = 0;
    monitor->min_rtt = -1.0; // Negative value indicates no RTT measured
    monitor->max_rtt = -1.0;
    monitor->total_rtt = 0.0;
    
    monitor->addr.sin_family = AF_INET;
    monitor->addr.sin_port = htons(0); // Randomly chose, we don't bind to any port
    inet_pton(AF_INET, ip, &monitor->addr.sin_addr);
}

// Function to send a ping
int send_ping(QoSMonitor *monitor) {
    int sockfd;
    char buffer[PACKET_SIZE];
    struct timeval start, end;
    socklen_t addr_len = sizeof(monitor->addr);
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }
    
    gettimeofday(&start, NULL);
    if (sendto(sockfd, buffer, PACKET_SIZE, 0, (struct sockaddr *)&monitor->addr, sizeof(monitor->addr)) < 0) {
        perror("Send failed");
        close(sockfd);
        return -1;
    }
    monitor->sent_packets++;
    
    // Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = MAX_TIMEOUT / 1000000;
    timeout.tv_usec = MAX_TIMEOUT % 1000000;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));
    
    // Receive response
    if (recvfrom(sockfd, buffer, PACKET_SIZE, 0, (struct sockaddr *)&monitor->addr, &addr_len) < 0) {
        perror("No response");
        close(sockfd);
        return 0; // Returns 0 for timeout
    }
    
    gettimeofday(&end, NULL);
    double rtt = calculate_rtt(&start, &end);
    monitor->received_packets++;
    
    // Update RTT statistics
    if (monitor->min_rtt < 0 || rtt < monitor->min_rtt) {
        monitor->min_rtt = rtt;
    }
    if (rtt > monitor->max_rtt) {
        monitor->max_rtt = rtt;
    }
    monitor->total_rtt += rtt;
    
    close(sockfd);
    return 1; // Indicates success
}

// Function to display the QoS statistics
void display_stats(QoSMonitor *monitor) {
    printf("Sent Packets: %d, Received Packets: %d\n", monitor->sent_packets, monitor->received_packets);
    if (monitor->received_packets > 0) {
        printf("Minimum RTT: %.2f ms\n", monitor->min_rtt);
        printf("Maximum RTT: %.2f ms\n", monitor->max_rtt);
        printf("Average RTT: %.2f ms\n",
            monitor->total_rtt / monitor->received_packets);
    } else {
        printf("No packets received. Check connectivity.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP_ADDRESS>\n", argv[0]);
        return 1;
    }
    
    QoSMonitor monitor;
    init_monitor(&monitor, argv[1]);
    
    while (1) {
        printf("Pinging %s...\n", argv[1]);
        if (send_ping(&monitor) > 0) {
            printf("Ping successful!\n");
        } else {
            printf("Ping failed or timed out.\n");
        }
        display_stats(&monitor);
        sleep(QOS_CHECK_INTERVAL);
    }
    
    return 0;
}