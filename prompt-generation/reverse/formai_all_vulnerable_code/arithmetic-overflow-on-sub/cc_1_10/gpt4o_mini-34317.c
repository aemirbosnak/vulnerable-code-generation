//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <errno.h>
#include <time.h>
#include <signal.h>

#define PACKET_SIZE 64
#define MAX_WAIT_TIME 1
#define PING_COUNT 4

// Structure for holding the ping statistics
struct ping_statistics {
    int sent;
    int received;
    int lost;
    double rtt_sum;
};

// Function to calculate checksum
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

// Function to send an ICMP ping
void send_ping(int sockfd, struct sockaddr_in *addr, int seq_num, struct ping_statistics *stats) {
    struct icmp *icmp_header;
    char packet[PACKET_SIZE];
    struct timespec start, end;
    double elapsed_time;

    memset(packet, 0, PACKET_SIZE);
    
    icmp_header = (struct icmp *)packet;
    icmp_header->icmp_type = ICMP_ECHO;
    icmp_header->icmp_code = 0;
    icmp_header->icmp_id = getpid();
    icmp_header->icmp_seq = seq_num;
    icmp_header->icmp_cksum = checksum(packet, PACKET_SIZE);
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    if (sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)addr, sizeof(struct sockaddr_in)) <= 0) {
        perror("Send failed");
        return;
    }

    stats->sent++;

    // Wait for reply
    char buffer[PACKET_SIZE];
    struct sockaddr_in reply_addr;
    socklen_t addr_len = sizeof(reply_addr);
    int bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&reply_addr, &addr_len);
    
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    if (bytes_received > 0) {
        struct ip *ip_header = (struct ip *)buffer;
        icmp_header = (struct icmp *)(buffer + (ip_header->ip_hl * 4));

        if (icmp_header->icmp_type == ICMP_ECHOREPLY && icmp_header->icmp_id == getpid()) {
            elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;
            stats->received++;
            stats->rtt_sum += elapsed_time;
            printf("Reply from %s: bytes=%d seq=%d time=%.2f ms\n", inet_ntoa(reply_addr.sin_addr), bytes_received, seq_num, elapsed_time);
        } else {
            printf("Received ICMP packet with unexpected type\n");
        }
    } else {
        printf("Request timed out\n");
        stats->lost++;
    }
}

// Function to print statistics
void print_statistics(struct ping_statistics *stats) {
    printf("--- Ping statistics ---\n");
    printf("%d packets transmitted, %d received, %.1f%% packet loss\n", stats->sent, stats->received, (stats->lost / (double)stats->sent) * 100.0);
    
    if (stats->received > 0) {
        printf("Average round-trip time: %.2f ms\n", stats->rtt_sum / stats->received);
    }
}

// Main function to perform ping test
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }
    
    int sockfd;
    struct sockaddr_in addr;
    struct ping_statistics stats = {0};
    int i;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
        perror("Invalid address");
        close(sockfd);
        return 1;
    }

    for (i = 0; i < PING_COUNT; i++) {
        sleep(1);
        send_ping(sockfd, &addr, i + 1, &stats);
    }

    print_statistics(&stats);
    
    close(sockfd);
    return 0;
}