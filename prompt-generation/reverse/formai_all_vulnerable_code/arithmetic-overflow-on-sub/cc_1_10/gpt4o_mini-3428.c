//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <signal.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

struct icmp_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

// Function to calculate the checksum of the ICMP header
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        sum += *(unsigned char*)buf;
    }

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// Function to create and send an ICMP echo request
void ping(const char *ip_addr) {
    int sockfd;
    struct sockaddr_in addr_ping;
    struct icmp_packet packet;
    struct timeval start, end;
    socklen_t addr_len = sizeof(addr_ping);
    int sent_packets = 0, received_packets = 0;

    // Create a raw socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(ip_addr);

    // Ping loop
    for (int i = 0; i < PING_COUNT; i++) {
        memset(&packet, 0, sizeof(packet));
        packet.hdr.type = ICMP_ECHO;
        packet.hdr.un.echo.id = getpid();
        packet.hdr.un.echo.sequence = i + 1;
        packet.hdr.checksum = checksum(&packet, sizeof(packet)); // Calculate checksum

        // Get the start time
        gettimeofday(&start, NULL);

        // Send packet
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&addr_ping, sizeof(addr_ping)) <= 0) {
            perror("Ping failed");
            continue;
        }
        sent_packets++;

        // Receive response
        if (recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&addr_ping, &addr_len) > 0) {
            // Get the end time
            gettimeofday(&end, NULL);
            double time_taken = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
            printf("Reply from %s: bytes=%d time=%.2f ms\n", ip_addr, PACKET_SIZE, time_taken);
            received_packets++;
        } else {
            perror("Response failed");
        }

        sleep(1); // Wait before sending the next ping
    }

    // Print summary
    printf("\n--- %s ping statistics ---\n", ip_addr);
    printf("%d packets transmitted, %d received, %.1f%% loss\n", sent_packets, received_packets,
           (sent_packets - received_packets) / (double)sent_packets * 100);

    close(sockfd); // Close the socket
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP Address or Hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Start the ping test
    ping(argv[1]);
    return EXIT_SUCCESS;
}