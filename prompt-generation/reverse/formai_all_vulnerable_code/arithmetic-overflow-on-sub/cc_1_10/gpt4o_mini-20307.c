//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netinet/ip.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 5

// Define the ICMP packet structure
struct icmp_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

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

// Function to send ICMP echo request and receive echo reply
void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr;
    struct icmp_packet packet;
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    struct timespec start, end;
    double time_taken;

    // Create raw socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    // Prepare the ICMP packet
    memset(&packet, 0, sizeof(packet));
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    packet.hdr.un.echo.sequence = 1;
    packet.hdr.checksum = checksum(&packet, sizeof(packet));

    printf("Pinging %s with %d bytes of data:\n", ip_address, PACKET_SIZE);

    for (int i = 0; i < PING_COUNT; i++) {
        // Send ICMP echo request
        clock_gettime(CLOCK_MONOTONIC, &start);
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Sendto failed");
            continue;
        }

        // Wait for echo reply
        if (recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&r_addr, &addr_len) < 0) {
            perror("Recvfrom failed");
            continue;
        }

        clock_gettime(CLOCK_MONOTONIC, &end);
        time_taken = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;

        // Check if the packet received is the one we sent
        if (packet.hdr.type == ICMP_ECHO && packet.hdr.un.echo.id == getpid()) {
            printf("Reply from %s: bytes=%d time=%.2f ms\n", ip_address, PACKET_SIZE, time_taken);
        } else {
            printf("Received invalid reply\n");
        }

        // Sleep for 1 second before next ping
        sleep(1);
    }

    close(sockfd);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ping(argv[1]);
    return 0;
}