//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <errno.h>
#include <netinet/in.h>
#include <time.h>

#define PING_PKT_S 64
#define PING_INTERVAL 1 // Interval between pings in seconds
#define PING_COUNT 4    // Number of pings for test

// Define the packet structure
struct ping_packet {
    struct icmphdr hdr; // ICMP header
    char msg[PING_PKT_S - sizeof(struct icmphdr)]; // Message part
};

// Compute the checksum
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

// Main ping function
void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr_ping;
    struct ping_packet pckt;
    struct timespec start, end;
    double elapsed;
    int ping_count = PING_COUNT;
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket error");
        exit(EXIT_FAILURE);
    }

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(ip_address);

    for (int i = 0; i < ping_count; i++) {
        memset(&pckt, 0, sizeof(pckt));
        pckt.hdr.type = ICMP_ECHO;
        pckt.hdr.un.echo.id = getpid(); // Use process ID for identification
        pckt.hdr.un.echo.sequence = i + 1;
        pckt.hdr.checksum = checksum(&pckt, sizeof(pckt));

        clock_gettime(CLOCK_MONOTONIC, &start);
        if (sendto(sockfd, &pckt, sizeof(pckt), 0, (struct sockaddr*)&addr_ping, sizeof(addr_ping)) <= 0) {
            perror("Send error");
            close(sockfd);
            exit(EXIT_FAILURE);
        }

        // Receive the response
        char buffer[1024];
        socklen_t addr_len = sizeof(addr_ping);
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr_ping, &addr_len) <= 0) {
            printf("Ping %d: Request timed out.\n", i + 1);
        } else {
            clock_gettime(CLOCK_MONOTONIC, &end);
            // Calculate time elapsed
            elapsed = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;

            struct iphdr *ip_hdr = (struct iphdr *)buffer;
            struct icmphdr *icmp_hdr = (struct icmphdr *)(buffer + (ip_hdr->ihl * 4));

            if (icmp_hdr->type == ICMP_ECHOREPLY && icmp_hdr->un.echo.id == pckt.hdr.un.echo.id) {
                printf("Ping %d: Reply from %s: bytes=%d time=%.2f ms TTL=%d\n",
                       i + 1,
                       ip_address,
                       PING_PKT_S,
                       elapsed,
                       ip_hdr->ttl);
            } else {
                printf("Ping %d: Invalid reply.\n", i + 1);
            }
        }

        sleep(PING_INTERVAL); // Wait before the next ping
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Validate input IP address format
    struct sockaddr_in sa;
    if (inet_pton(AF_INET, argv[1], &(sa.sin_addr)) <= 0) {
        fprintf(stderr, "Invalid IP address format: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    ping(argv[1]); // Start the ping process
    return 0;
}