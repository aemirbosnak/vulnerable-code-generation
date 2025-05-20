//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

// Structure for ICMP header
struct icmp_packet {
    struct icmp header;
    char payload[PACKET_SIZE - sizeof(struct icmp)];
};

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

// Function to send a ping
void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr;
    struct icmp_packet packet;
    struct timeval start, end;
    int addr_len = sizeof(addr);
    int sent = 0, received = 0;

    // Create RAW socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket error");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    for (int i = 0; i < PING_COUNT; i++) {
        memset(&packet, 0, sizeof(packet));
        packet.header.icmp_type = ICMP_ECHO;
        packet.header.icmp_id = getpid();
        packet.header.icmp_seq = i + 1;
        gettimeofday(&start, NULL);
        packet.header.icmp_cksum = checksum(&packet, sizeof(packet));

        // Send the packet
        if (sendto(sockfd, &packet, sizeof(packet), 0, 
                   (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Send error");
            continue;
        }
        sent++;

        // Wait for the reply
        if (recvfrom(sockfd, &packet, sizeof(packet), 0, 
                     (struct sockaddr *)&addr, &addr_len) > 0) {
            gettimeofday(&end, NULL);
            double time_taken = (end.tv_sec - start.tv_sec) * 1000.0;
            time_taken += (end.tv_usec - start.tv_usec) / 1000.0;
            printf("Reply from %s: bytes=%d time=%.2f ms\n", ip_address, 
                   sizeof(packet), time_taken);
            received++;
        } else {
            perror("Receive error");
        }
        sleep(1); // Wait before next ping
    }

    printf("--- %s ping statistics ---\n", ip_address);
    printf("%d packets transmitted, %d received, %.1f%% packet loss\n",
           sent, received, ((sent - received) / (double)sent) * 100.0);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    ping(argv[1]);
    
    return EXIT_SUCCESS;
}