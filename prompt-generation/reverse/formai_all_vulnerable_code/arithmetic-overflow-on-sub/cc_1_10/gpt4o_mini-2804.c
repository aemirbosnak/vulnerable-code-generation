//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

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

// Function to perform the ping test
void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr;
    struct ping_packet packet;
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    int n_sent, n_received;
    char buffer[PACKET_SIZE];
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket Creation Failed");
        return;
    }
    
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);
    
    for (n_sent = 0; n_sent < PING_COUNT; n_sent++) {
        memset(&packet, 0, sizeof(packet));
        packet.hdr.type = ICMP_ECHO;
        packet.hdr.un.echo.id = getpid();
        packet.hdr.un.echo.sequence = n_sent + 1;
        packet.hdr.checksum = checksum(&packet, sizeof(packet));
        
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Ping Failed");
            continue;
        }
        
        // Start measuring response time
        struct timeval start, end;
        gettimeofday(&start, NULL);
        
        // Wait for the response
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&r_addr, &addr_len) < 0) {
            perror("Response Receive Failed");
            continue;
        }
        
        gettimeofday(&end, NULL);
        double time_taken = (end.tv_sec - start.tv_sec) * 1e6;
        time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-3; // Convert to ms
        
        printf("Reply from %s: bytes=%d time=%.2f ms\n", ip_address, sizeof(packet), time_taken);
    }
    
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    const char *ip_address = argv[1];
    ping(ip_address);
    
    return 0;
}