//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

// Function to calculate the checksum
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// Function to perform the ping operation
void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr;
    struct icmp packet;
    struct timespec start, end;
    double time_taken;
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    for (int i = 0; i < PING_COUNT; i++) {
        memset(&packet, 0, sizeof(packet));
        packet.icmp_type = ICMP_ECHO;
        packet.icmp_id = getpid();
        packet.icmp_seq = i + 1;
        packet.icmp_cksum = checksum(&packet, sizeof(packet));

        clock_gettime(CLOCK_MONOTONIC, &start);
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Failed to send packet");
            continue;
        }

        unsigned char buffer[PACKET_SIZE];
        socklen_t len = sizeof(addr);
        if (recvfrom(sockfd, buffer, PACKET_SIZE, 0, (struct sockaddr *)&addr, &len) < 0) {
            perror("Failed to receive packet");
            continue;
        }

        clock_gettime(CLOCK_MONOTONIC, &end);
        time_taken = (end.tv_sec - start.tv_sec) * 1000.0 +
                     (end.tv_nsec - start.tv_nsec) / 1000000.0;

        struct iphdr *ip_header = (struct iphdr *)buffer;
        struct icmp *icmp_response = (struct icmp *)(buffer + (ip_header->ihl << 2));
        printf("Reply from %s: bytes=%d time=%.2f ms\n", ip_address, sizeof(packet), time_taken);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Pinging %s with %d bytes of data:\n", argv[1], PACKET_SIZE);
    ping(argv[1]);

    return 0;
}