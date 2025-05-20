//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 5

struct ping_packet {
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

// Function to ping the host
void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr_ping;
    struct ping_packet ping_pkt;
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    int num_sent = 0, num_received = 0;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_port = htons(0);
    addr_ping.sin_addr.s_addr = inet_addr(ip_address);

    for (num_sent = 0; num_sent < PING_COUNT; num_sent++) {
        memset(&ping_pkt, 0, sizeof(ping_pkt));

        ping_pkt.hdr.type = ICMP_ECHO;
        ping_pkt.hdr.un.echo.id = getpid();
        ping_pkt.hdr.un.echo.sequence = num_sent + 1;
        ping_pkt.hdr.checksum = checksum(&ping_pkt, sizeof(ping_pkt));

        if (sendto(sockfd, &ping_pkt, sizeof(ping_pkt), 0, (struct sockaddr *)&addr_ping, sizeof(addr_ping)) <= 0) {
            perror("Ping send failed");
        }

        struct timeval start_time, end_time;
        gettimeofday(&start_time, NULL);

        if (recvfrom(sockfd, &ping_pkt, sizeof(ping_pkt), 0, (struct sockaddr *)&r_addr, &addr_len) <= 0) {
            perror("Ping receive failed");
        } else {
            gettimeofday(&end_time, NULL);
            num_received++;
            long time_taken = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;
            printf("Reply from %s: bytes=%d time=%ld ms\n", ip_address, sizeof(ping_pkt), time_taken);
        }
        
        sleep(1);
    }

    printf("\n--- %s ping statistics ---\n", ip_address);
    printf("%d packets transmitted, %d received, %.2f%% packet loss\n", num_sent, num_received, (num_sent - num_received) / (float)num_sent * 100.0);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Pinging %s...\n", argv[1]);
    ping(argv[1]);

    return 0;
}