//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <netdb.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define MAX_PROBES 4

typedef struct {
    struct sockaddr_in addr;
    char target[256];
} PingConfig;

typedef struct {
    int sent;
    int received;
    double min;
    double max;
    double total;
} PingStatistics;

void initialize_ping_config(PingConfig *config, const char *hostname) {
    struct hostent *host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        perror("Failed to resolve hostname");
        exit(EXIT_FAILURE);
    }

    memset(config, 0, sizeof(PingConfig));
    strcpy(config->target, hostname);
    config->addr.sin_family = AF_INET;
    config->addr.sin_port = 0; // Use default port
    memcpy(&(config->addr.sin_addr), host_info->h_addr_list[0], host_info->h_length);
}

double ping_target(PingConfig *config, int seq_num) {
    int sockfd;
    char packet[PACKET_SIZE];
    struct timespec start, end;
    ssize_t bytes_sent, bytes_received;
    socklen_t addr_len = sizeof(config->addr);
    double rtt;

    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(packet, 0, sizeof(packet));
    snprintf(packet, sizeof(packet), "PING %d", seq_num);

    clock_gettime(CLOCK_MONOTONIC, &start);
    bytes_sent = sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr*)&config->addr, sizeof(config->addr));
    if (bytes_sent < 0) {
        perror("Failed to send packet");
        close(sockfd);
        return -1;
    }

    bytes_received = recvfrom(sockfd, packet, sizeof(packet), 0, (struct sockaddr*)&config->addr, &addr_len);
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    if (bytes_received < 0) {
        perror("Failed to receive packet");
        close(sockfd);
        return -1;
    }

    close(sockfd);
    rtt = (end.tv_sec - start.tv_sec) * 1.0e3 + (end.tv_nsec - start.tv_nsec) / 1.0e6; // in milliseconds
    return rtt;
}

void print_statistics(PingStatistics stats, PingConfig *config) {
    printf("--- %s ping statistics ---\n", config->target);
    printf("%d packets transmitted, %d received, %.1f%% packet loss\n",
           stats.sent, stats.received, 
           ((stats.sent - stats.received) / (double)stats.sent) * 100.0);
    
    if (stats.received > 0) {
        printf("round-trip min/avg/max = %.3f/%.3f/%.3f ms\n",
               stats.min, stats.total / stats.received, stats.max);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    PingConfig config;
    PingStatistics stats = {0, 0, 1e6, 0.0, 0.0};
    
    initialize_ping_config(&config, argv[1]);

    printf("PING %s (%s):\n", config.target, inet_ntoa(config.addr.sin_addr));
    
    for (int i = 1; i <= MAX_PROBES; i++) {
        stats.sent++;
        double rtt = ping_target(&config, i);
        
        if (rtt >= 0) {
            stats.received++;
            printf("%d bytes from %s: seq=%d time=%.3f ms\n", 
                   PACKET_SIZE, config.target, i, rtt);
            if (rtt < stats.min) stats.min = rtt;
            if (rtt > stats.max) stats.max = rtt;
            stats.total += rtt;
        } else {
            printf("Request timed out.\n");
        }

        sleep(TIMEOUT);
    }

    print_statistics(stats, &config);
    return EXIT_SUCCESS;
}