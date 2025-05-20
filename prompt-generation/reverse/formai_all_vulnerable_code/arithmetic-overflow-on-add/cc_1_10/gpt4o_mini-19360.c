//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <time.h>
#include <errno.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

void calculate_checksum(struct icmphdr *icmph) {
    unsigned short *ptr = (unsigned short *)icmph;
    int n = sizeof(struct icmphdr) + sizeof(struct ping_packet) - sizeof(struct icmphdr);
    unsigned int sum = 0;

    for (int i = 0; i < n/2; i++) {
        sum += *ptr++;
        if (sum > 0xFFFF) {
            sum -= 0xFFFF;
        }
    }
    icmph->checksum = htons(~sum);
}

void perform_ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr_ping;
    char buffer[PACKET_SIZE];
    struct ping_packet pkt;
    struct timeval start_time, end_time;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&pkt, 0, sizeof(pkt));
    pkt.hdr.type = ICMP_ECHO;
    pkt.hdr.un.echo.id = getpid();
    memcpy(pkt.msg, "Ping!", 5);
    calculate_checksum(&pkt.hdr);

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(ip_address);

    printf("🎉 Initiating the ping carnival for %s! 🎉\n", ip_address);
    
    for (int i = 0; i < PING_COUNT; i++) {
        gettimeofday(&start_time, NULL);
        
        ssize_t sent = sendto(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr*)&addr_ping, sizeof(addr_ping));
        if (sent < 0) {
            perror("Packet failed to send");
            continue;
        }

        socklen_t addr_len = sizeof(addr_ping);
        ssize_t received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr_ping, &addr_len);
        if (received < 0) {
            perror("Packet failed to receive");
            continue;
        }

        gettimeofday(&end_time, NULL);
        long seconds = end_time.tv_sec - start_time.tv_sec;
        long microseconds = end_time.tv_usec - start_time.tv_usec;
        long elapsed = seconds * 1000 + microseconds / 1000;

        struct iphdr* ip_header = (struct iphdr*)buffer;
        struct icmphdr* icmp_header = (struct icmphdr*)(buffer + (ip_header->ihl << 2));
        
        printf("🌊 Ping %d to %s: TTL=%d Time=%.3f ms 🌊\n", i + 1, ip_address, ip_header->ttl, (float)elapsed);
        
        sleep(1); // Wait for a second before the next ping
    }
    
    close(sockfd);
    printf("🎊 The ping carnival for %s has concluded! 🎊\n", ip_address);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    perform_ping(argv[1]);

    return EXIT_SUCCESS;
}