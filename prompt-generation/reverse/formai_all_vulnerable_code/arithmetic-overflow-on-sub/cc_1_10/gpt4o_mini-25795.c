//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 4
#define DEST_IP "8.8.8.8" // Google's public DNS for testing
#define TIMEOUT 1 // Timeout in seconds

typedef struct {
    int sent;
    int received;
    double min_time;
    double max_time;
    double total_time;
} QoSStats;

void print_intro();
void ping(const char *ip, QoSStats *stats);
double calculate_rtt(struct timeval *start, struct timeval *end);
void print_results(QoSStats *stats);

int main() {
    print_intro();
    QoSStats stats = {0, 0, 1e9, 0, 0}; // Initialize structure

    ping(DEST_IP, &stats);
    print_results(&stats);

    return 0;
}

void print_intro() {
    printf("========================================\n");
    printf("        Network QoS Monitor\n");
    printf("========================================\n");
    printf("This program will send ICMP ping requests to %s\n", DEST_IP);
    printf("Measuring metrics for quality of service...\n\n");
    sleep(2);
}

void ping(const char *ip, QoSStats *stats) {
    int sockfd;
    struct sockaddr_in dest_addr;
    char packet[PACKET_SIZE];
    struct timeval start, end;
    socklen_t addr_len = sizeof(dest_addr);
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(ip);

    for (int i = 0; i < PING_COUNT; i++) {
        // Prepare ICMP echo request packet
        memset(packet, 0, sizeof(packet));
        packet[0] = 8; // ICMP echo request type
        packet[1] = 0; // Code
        packet[2] = 0; // Checksum placeholder
        packet[3] = 0; // Identifier
        packet[4] = i; // Sequence number
        
        gettimeofday(&start, NULL);
        if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr*)&dest_addr, addr_len) < 0) {
            perror("Send failed");
            continue;
        }
        
        stats->sent++;

        if (recvfrom(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr*)&dest_addr, &addr_len) >= 0) {
            gettimeofday(&end, NULL);
            stats->received++;
            double rtt = calculate_rtt(&start, &end);

            stats->total_time += rtt;
            if (rtt < stats->min_time) {
                stats->min_time = rtt;
            }
            if (rtt > stats->max_time) {
                stats->max_time = rtt;
            }
            printf("Reply from %s: time=%.2f ms\n", ip, rtt);
        } else {
            printf("Request timed out.\n");
        }
        sleep(1); // Delay between pings
    }

    close(sockfd);
}

double calculate_rtt(struct timeval *start, struct timeval *end) {
    return ((end->tv_sec - start->tv_sec) * 1000.0) + ((end->tv_usec - start->tv_usec) / 1000.0);
}

void print_results(QoSStats *stats) {
    printf("\n========================================\n");
    printf("           Ping Results\n");
    printf("========================================\n");
    printf("Packets Sent: %d\n", stats->sent);
    printf("Packets Received: %d\n", stats->received);
    
    if (stats->received > 0) {
        printf("Packet Loss: %.2f%%\n", ((double)(stats->sent - stats->received) / stats->sent) * 100);
        printf("Minimum RTT: %.2f ms\n", stats->min_time);
        printf("Maximum RTT: %.2f ms\n", stats->max_time);
        printf("Average RTT: %.2f ms\n", stats->total_time / stats->received);
    } else {
        printf("All packets were lost!\n");
    }
    printf("========================================\n");
}