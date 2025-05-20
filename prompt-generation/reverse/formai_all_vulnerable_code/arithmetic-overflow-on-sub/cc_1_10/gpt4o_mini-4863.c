//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

typedef struct {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
} pingPacket;

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

void ping(const char *ip_addr) {
    int sockfd;
    struct sockaddr_in addr;
    pingPacket packet;
    struct sockaddr_in r_addr;
    int addr_len = sizeof(r_addr);
    int n_sent, n_received;
    struct timespec start, end;

    // Create raw socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);

    for (int count = 0; count < PING_COUNT; count++) {
        memset(&packet, 0, sizeof(packet));
        packet.hdr.type = ICMP_ECHO;
        packet.hdr.un.echo.id = getpid();
        packet.hdr.un.echo.sequence = count + 1;
        packet.hdr.checksum = checksum(&packet, sizeof(packet));

        clock_gettime(CLOCK_MONOTONIC, &start);
        n_sent = sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr));
        
        if (n_sent <= 0) {
            perror("Send failed");
            continue;
        }

        // Wait for response
        n_received = recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&r_addr, &addr_len);
        
        if (n_received <= 0) {
            perror("Receive failed");
            continue;
        }

        clock_gettime(CLOCK_MONOTONIC, &end);
        double rtt = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;

        // Verify if this is the correct response
        if (packet.hdr.type == ICMP_ECHOREPLY && packet.hdr.un.echo.id == getpid()) {
            printf("Reply from %s: bytes=%d time=%.2f ms\n", ip_addr, n_received, rtt);
        } else {
            printf("Received invalid response from %s\n", ip_addr);
        }

        // Sleep before sending next ping
        sleep(1);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_addr = argv[1];
    
    printf("Starting ping test to %s:\n", ip_addr);
    ping(ip_addr);
    
    return 0;
}