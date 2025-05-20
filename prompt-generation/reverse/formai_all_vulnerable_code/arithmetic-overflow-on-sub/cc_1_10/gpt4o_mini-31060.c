//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <time.h>
#include <errno.h>

#define PACKET_SIZE 64
#define PING_COUNT 5

// Structure to hold the ICMP packet
struct icmp_packet {
    struct icmphdr header;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
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

// Function to ping a host
void ping(const char *host) {
    int sockfd;
    struct sockaddr_in addr;
    struct icmp_packet packet;
    struct timespec start, end;
    double time_taken;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(host);

    printf("Pinging %s:\n", host);
    for (int i = 0; i < PING_COUNT; i++) {
        // Prepare ICMP packet
        memset(&packet, 0, sizeof(packet));
        packet.header.type = ICMP_ECHO;
        packet.header.un.echo.id = getpid();
        packet.header.un.echo.sequence = i + 1;
        packet.header.checksum = checksum(&packet, sizeof(packet));

        clock_gettime(CLOCK_MONOTONIC, &start);

        // Send the packet
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Send failed");
            continue;
        }

        char buffer[PACKET_SIZE];
        socklen_t addr_len = sizeof(addr);
        // Wait for the response
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, &addr_len) <= 0) {
            perror("Recv failed");
        } else {
            clock_gettime(CLOCK_MONOTONIC, &end);
            time_taken = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;
            printf("Reply from %s: bytes=%d time=%.2f ms\n", host, PACKET_SIZE, time_taken);
        }

        sleep(1);  // Wait a second before next ping
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname_or_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ping(argv[1]);
    return 0;
}