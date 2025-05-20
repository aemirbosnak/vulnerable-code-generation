//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/ip_icmp.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

typedef struct ping_packet {
    struct icmphdr header;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
} ping_packet;

unsigned int checksum(void *b, int len) {
    unsigned int sum = 0;
    unsigned short *p = b;

    for (sum = 0; len > 1; len -= 2)
        sum += *p++;
    if (len == 1) 
        sum += *(unsigned char *)p;
    
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    
    return ~sum;
}

void ping(const char *ip_address) {
    struct sockaddr_in addr_ping;
    struct timeval timeout;
    ping_packet packet;
    int sockfd, i, addr_len, rtt;
    struct timespec start_time, end_time;

    // Set up the socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    addr_ping.sin_family = AF_INET;
    addr_ping.sin_port = 0;
    inet_pton(AF_INET, ip_address, &addr_ping.sin_addr);

    // Fill the ping packet
    memset(&packet, 0, sizeof(packet));
    packet.header.type = ICMP_ECHO;
    packet.header.un.echo.id = getpid();
    for (i = 0; i < sizeof(packet.msg) - 1; i++) {
        packet.msg[i] = 'A';
    }
    packet.msg[i] = 0;
    
    packet.header.un.echo.sequence = 1;
    packet.header.checksum = checksum(&packet, sizeof(packet));

    addr_len = sizeof(addr_ping);

    for (i = 0; i < PING_COUNT; i++) {
        // Send the packet
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&addr_ping, addr_len) <= 0) {
            perror("Send failed");
            continue;
        }
        
        // Receive the packet
        char buffer[PACKET_SIZE];
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr_ping, &addr_len) < 0) {
            perror("Receive failed");
            continue;
        }
        
        clock_gettime(CLOCK_MONOTONIC, &end_time);
        rtt = (end_time.tv_sec - start_time.tv_sec) * 1000 + 
              (end_time.tv_nsec - start_time.tv_nsec) / 1000000;

        printf("Reply from %s: time=%d ms\n", ip_address, rtt);
        packet.header.un.echo.sequence++;
        sleep(1);
    }
    
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    printf("Pinging %s:\n", argv[1]);
    ping(argv[1]);
    
    return 0;
}