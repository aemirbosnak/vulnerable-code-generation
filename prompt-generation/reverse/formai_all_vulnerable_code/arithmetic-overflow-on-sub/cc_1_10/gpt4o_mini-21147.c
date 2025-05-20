//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/udp.h>

#define BUFSIZE 1024
#define QUEUE_SIZE 10

typedef struct {
    char source_ip[INET_ADDRSTRLEN];
    char dest_ip[INET_ADDRSTRLEN];
    unsigned int total_packets;
    double avg_latency;
} QoSStats;

void initialize_QoS_stats(QoSStats *qos_stats) {
    strcpy(qos_stats->source_ip, "0.0.0.0");
    strcpy(qos_stats->dest_ip, "0.0.0.0");
    qos_stats->total_packets = 0;
    qos_stats->avg_latency = 0.0;
}

void update_QoS_stats(QoSStats *qos_stats, struct sockaddr_in *src, struct sockaddr_in *dst, double latency) {
    inet_ntop(AF_INET, &(src->sin_addr), qos_stats->source_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(dst->sin_addr), qos_stats->dest_ip, INET_ADDRSTRLEN);
    qos_stats->total_packets++;
    qos_stats->avg_latency += latency;
    qos_stats->avg_latency /= qos_stats->total_packets; 
}

double get_latency(struct timeval start, struct timeval end) {
    return ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
}

void log_QoS_stats(QoSStats *qos_stats) {
    printf("Source IP: %s\n", qos_stats->source_ip);
    printf("Destination IP: %s\n", qos_stats->dest_ip);
    printf("Total Packets: %u\n", qos_stats->total_packets);
    printf("Average Latency: %.2f ms\n", qos_stats->avg_latency);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFSIZE];
    socklen_t addr_len = sizeof(client_addr);
    struct timeval start, end;
    QoSStats qos_stats;

    initialize_QoS_stats(&qos_stats);
    
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming packets...\n");
    
    while (1) {
        // Clear buffer for new incoming message
        memset(buffer, 0, BUFSIZE);

        // Get the start time
        gettimeofday(&start, NULL);
        
        // Wait for an incoming packet
        int n = recvfrom(sockfd, buffer, BUFSIZE, 0, (struct sockaddr *)&client_addr, &addr_len);
        if (n < 0) {
            perror("Receive failed");
            continue;
        }

        // Get the end time
        gettimeofday(&end, NULL);
        
        // Calculate latency
        double latency = get_latency(start, end);
        
        // Update QoS stats
        update_QoS_stats(&qos_stats, &client_addr, &server_addr, latency);

        printf("Received packet from %s: %s\n", qos_stats.source_ip, buffer);
        
        // For demonstration, log QoS stats
        log_QoS_stats(&qos_stats);
    }

    close(sockfd);
    return 0;
}