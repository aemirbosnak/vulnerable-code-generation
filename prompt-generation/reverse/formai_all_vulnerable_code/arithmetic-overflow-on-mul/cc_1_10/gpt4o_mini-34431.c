//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define PING_COUNT 4

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

// Function to send a ping
void send_ping(int sockfd, struct sockaddr_in *addr, int id, int seq) {
    char packet[PACKET_SIZE];
    struct icmp *icmp_hdr = (struct icmp *)packet;
    struct timespec start, end;
    
    memset(packet, 0, PACKET_SIZE);
    
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = htons(id);
    icmp_hdr->icmp_seq = htons(seq);
    icmp_hdr->icmp_cksum = checksum(icmp_hdr, PACKET_SIZE);
    
    clock_gettime(CLOCK_MONOTONIC, &start);
    if (sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)addr, sizeof(*addr)) <= 0) {
        perror("Error sending ping");
    }
    
    struct sockaddr_in r_addr;
    socklen_t r_addr_len = sizeof(r_addr);
    if (recvfrom(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&r_addr, &r_addr_len) <= 0) {
        perror("Timeout or error in receiving response");
    }
    
    clock_gettime(CLOCK_MONOTONIC, &end);
    
    long ping_time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
    
    printf("Reply from %s: bytes=%d time=%ld ms\n", inet_ntoa(r_addr.sin_addr), PACKET_SIZE, ping_time);
}

// Main function for the ping program
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    int sockfd;
    struct sockaddr_in addr;
    
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address or address not supported: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    printf("Pinging %s...\n", argv[1]);
    
    for (int i = 0; i < PING_COUNT; i++) {
        send_ping(sockfd, &addr, getpid(), i + 1);
        sleep(TIMEOUT);
    }
    
    close(sockfd);
    
    return 0;
}