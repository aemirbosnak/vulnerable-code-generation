//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <errno.h>
#include <time.h>
#include <signal.h>

// Define the packet size
#define PACKET_SIZE 64
#define PING_INTERVAL 1
#define MAX_PINGS 4

// Function to calculate checksum
unsigned short calculate_checksum(void *b, int len) {
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

// Function to perform the ping
void ping(const char *ip_addr) {
    int sockfd;
    struct sockaddr_in address;
    struct icmphdr icmp_hdr;
    char packet[PACKET_SIZE];
    struct timespec start, end;

    // Create a raw socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the address structure
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    if (inet_pton(AF_INET, ip_addr, &address.sin_addr) <= 0) {
        perror("Invalid address or address not supported");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Fill the ICMP header
    memset(&icmp_hdr, 0, sizeof(icmp_hdr));
    icmp_hdr.type = ICMP_ECHO;
    icmp_hdr.code = 0;
    icmp_hdr.un.echo.id = getpid();
    icmp_hdr.un.echo.sequence = 1;

    // Set the timeout for receiving responses
    struct timeval timeout;
    timeout.tv_sec = PING_INTERVAL;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    for (int i = 0; i < MAX_PINGS; i++) {
        // Prepare the packet
        memcpy(packet, &icmp_hdr, sizeof(icmp_hdr));
        icmp_hdr.checksum = calculate_checksum(packet, sizeof(icmp_hdr));

        // Send the ping request
        clock_gettime(CLOCK_MONOTONIC, &start);
        if (sendto(sockfd, packet, sizeof(icmp_hdr), 0, (struct sockaddr *)&address, sizeof(address)) <= 0) {
            perror("Ping request failed");
        } else {
            printf("Ping sent to %s\n", ip_addr);
        }

        // Receive the ping reply
        int addr_len = sizeof(address);
        if (recvfrom(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&address, &addr_len) < 0) {
            perror("Ping reply not received");
        } else {
            clock_gettime(CLOCK_MONOTONIC, &end);
            double time_taken = (end.tv_sec - start.tv_sec) * 1e3; // seconds to milliseconds
            time_taken += (end.tv_nsec - start.tv_nsec) / 1e6; // nanoseconds to milliseconds
            printf("Reply from %s: time=%.2f ms\n", ip_addr, time_taken);
        }

        // Wait before sending the next ping
        sleep(PING_INTERVAL);
    }

    close(sockfd);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ping(argv[1]);
    return 0;
}