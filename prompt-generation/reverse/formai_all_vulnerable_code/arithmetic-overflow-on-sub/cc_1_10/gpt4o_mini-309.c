//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define PACKET_SIZE 64
#define ICMP_HEADER_SIZE 8
#define TIMEOUT 1
#define MAX_PINGS 10

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - ICMP_HEADER_SIZE];
};

struct ping_stats {
    int sent;
    int received;
    double min_rtt;
    double max_rtt;
    double total_rtt;
};

void calculate_statistics(struct ping_stats *stats) {
    if (stats->received > 0) {
        printf("\n--- Ping statistics ---\n");
        printf("%d packets transmitted, %d received, %d%% packet loss\n",
               stats->sent, stats->received, (stats->sent - stats->received) * 100 / stats->sent);
        printf("round-trip min/avg/max = %.2f/%.2f/%.2f ms\n",
               stats->min_rtt, stats->total_rtt / stats->received, stats->max_rtt);
    } else {
        printf("No packets received.\n");
    }
}

double calculate_rtt(struct timespec *start, struct timespec *end) {
    return (end->tv_sec - start->tv_sec) * 1000.0 + (end->tv_nsec - start->tv_nsec) / 1000000.0;
}

void handle_ping(int sockfd, const char *ip_address, struct ping_stats *stats) {
    struct sockaddr_in addr;
    int addr_len = sizeof(addr);
    struct ping_packet packet;
    struct timespec start_time, end_time;
    
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    memset(packet.msg, 'E', sizeof(packet.msg)); // Fill message with 'E'.
    packet.hdr.un.echo.sequence = 1;
    packet.hdr.checksum = 0;
    
    for (int i = 0; i < MAX_PINGS; i++) {
        packet.hdr.un.echo.sequence = i + 1;
        packet.hdr.checksum = htons(~(packet.hdr.type + packet.hdr.un.echo.id + packet.hdr.un.echo.sequence));
        
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&addr, sizeof(addr)) <= 0) {
            perror("Sendto failed");
            return;
        }
        
        stats->sent++;
        struct timeval tv;
        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));

        int response = recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&addr, &addr_len);
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        
        if (response <= 0) {
            printf("Request timed out for sequence %d\n", i + 1);
        } else {
            double rtt = calculate_rtt(&start_time, &end_time);
            stats->received++;
            if (stats->min_rtt == 0 || rtt < stats->min_rtt) {
                stats->min_rtt = rtt;
            }
            if (rtt > stats->max_rtt) {
                stats->max_rtt = rtt;
            }
            stats->total_rtt += rtt;
            printf("Reply from %s: seq=%d time=%.2f ms\n", ip_address, i + 1, rtt);
        }
        usleep(1000000); // Wait 1 second before sending the next ping
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip_address = argv[1];
    int sockfd;
    struct ping_stats stats = {0, 0, 0, 0, 0};

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = inet_addr(ip_address);
    
    handle_ping(sockfd, ip_address, &stats);

    calculate_statistics(&stats);
    close(sockfd);
    return EXIT_SUCCESS;
}