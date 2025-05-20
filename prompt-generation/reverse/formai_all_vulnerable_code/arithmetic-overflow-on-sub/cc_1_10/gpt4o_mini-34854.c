//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

// Structure to hold the ping statistics
typedef struct {
    int sent;
    int received;
    double min_time;
    double max_time;
    double total_time;
} PingStats;

// Function to calculate the checksum
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        sum += *(unsigned char *)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// Function to create and send an ICMP echo request
void ping_echo(const char *ip_addr, PingStats *stats) {
    int sockfd;
    struct sockaddr_in addr;
    struct icmp *icmp_hdr;
    struct timeval start_time, end_time;
    char packet[PACKET_SIZE];
    int addr_len = sizeof(struct sockaddr_in);

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);
    memset(packet, 0, PACKET_SIZE);

    icmp_hdr = (struct icmp *)packet;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = getpid();
    icmp_hdr->icmp_seq = stats->sent;
    icmp_hdr->icmp_cksum = checksum(packet, PACKET_SIZE);

    gettimeofday(&start_time, NULL);
    if (sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)&addr, addr_len) <= 0) {
        perror("Packet send failed");
        close(sockfd);
        return;
    }
    
    // Wait for the echo reply
    char recv_packet[PACKET_SIZE];
    if (recvfrom(sockfd, recv_packet, sizeof(recv_packet), 0, (struct sockaddr *)&addr, &addr_len) > 0) {
        gettimeofday(&end_time, NULL);
        double rtt = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec) / 1000.0;

        printf("Reply from %s: bytes=%d time=%.2fms\n", ip_addr, PACKET_SIZE, rtt);
        stats->received++;
        stats->total_time += rtt;
        if (stats->min_time == 0 || rtt < stats->min_time) {
            stats->min_time = rtt;
        }
        if (rtt > stats->max_time) {
            stats->max_time = rtt;
        }
    }

    stats->sent++;
    close(sockfd);
}

// Function to display ping statistics
void display_statistics(PingStats stats) {
    printf("\n--- Ping statistics for %d packets sent ---\n", stats.sent);
    printf("%d received, %d lost (%.2f%% loss)\n", stats.received, stats.sent - stats.received,
           ((double)(stats.sent - stats.received) / stats.sent) * 100);
    if (stats.received > 0) {
        printf("Round-trip min/avg/max = %.2f/%.2f/%.2f ms\n", stats.min_time, stats.total_time / stats.received, stats.max_time);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    PingStats stats = {0, 0, .0, .0, .0};
    const char *ip_addr = argv[1];

    for (int i = 0; i < PING_COUNT; i++) {
        ping_echo(ip_addr, &stats);
        sleep(1); // wait before sending the next ping
    }

    display_statistics(stats);
    return EXIT_SUCCESS;
}