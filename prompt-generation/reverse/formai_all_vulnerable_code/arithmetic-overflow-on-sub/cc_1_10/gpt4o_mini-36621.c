//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <errno.h>

#define MAX_PACKET_SIZE 4096
#define TIMEOUT 1
#define PING_COUNT 4

// Function to calculate checksum
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

// Function to ping a host
void ping(const char *address) {
    struct sockaddr_in addr;
    struct icmp packet;
    struct timeval start, end;
    char buffer[MAX_PACKET_SIZE];
    int sockfd, n, packet_size = sizeof(packet);
    double time_taken;

    // Create raw socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    // Fill in the target address
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(address);

    // Prepare ICMP packet
    memset(&packet, 0, sizeof(packet));
    packet.icmp_type = ICMP_ECHO;
    packet.icmp_id = getpid();
    packet.icmp_seq = 1;
    packet.icmp_cksum = checksum(&packet, packet_size);

    // Send and receive PINGs!
    printf("PING %s: %d bytes of data:\n", address, packet_size);
    for (int i = 0; i < PING_COUNT; i++) {
        gettimeofday(&start, NULL);
        if (sendto(sockfd, &packet, packet_size, 0, (struct sockaddr*)&addr, sizeof(addr)) <= 0) {
            perror("Send failed");
            break;
        }

        // Setup for receiving response
        socklen_t addr_len = sizeof(addr);
        n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr, &addr_len);
        gettimeofday(&end, NULL);

        if (n < 0) {
            perror("Receive failed");
        } else {
            struct iphdr *ip_header = (struct iphdr *)buffer;
            struct icmp *icmp_header = (struct icmp *)(buffer + ip_header->ihl * 4);
            if (icmp_header->icmp_type == ICMP_ECHOREPLY) {
                time_taken = (end.tv_sec - start.tv_sec) * 1000.0;
                time_taken += (end.tv_usec - start.tv_usec) / 1000.0;
                printf("%d bytes from %s: icmp_seq=%d time=%.2f ms\n",
                       n, address, icmp_header->icmp_seq, time_taken);
            }
        }
        sleep(1);
    }

    close(sockfd);
}

// Main function to drive the program
int main(int argc, char *argv[]) {
    printf("\n***************** NETWORK PING TEST *****************\n");
    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    printf("Starting the ping test on %s...\n", argv[1]);
    ping(argv[1]);

    printf("Ping test finished!\n");
    printf("***********************************************\n");
    return 0;
}