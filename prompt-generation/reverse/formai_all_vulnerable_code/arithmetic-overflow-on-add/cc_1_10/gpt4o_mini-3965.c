//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define TIMEOUT 5

struct ping_pkt {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

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

void send_ping(int sockfd, struct sockaddr_in *addr) {
    struct ping_pkt pkt;
    struct timeval start, end;
    socklen_t addr_len = sizeof(*addr);
    
    memset(&pkt, 0, sizeof(pkt));
    pkt.hdr.type = ICMP_ECHO;
    pkt.hdr.code = 0;
    pkt.hdr.un.echo.id = getpid();
    pkt.hdr.un.echo.sequence = 1;
    pkt.hdr.checksum = checksum(&pkt, sizeof(pkt));

    gettimeofday(&start, NULL);
    if (sendto(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr*)addr, addr_len) <= 0) {
        perror("Send failed");
        return;
    }

    char buffer[1024];
    int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)addr, &addr_len);
    if (n <= 0) {
        perror("Receive failed");
        return;
    }
    gettimeofday(&end, NULL);

    struct icmphdr *icmp_hdr = (struct icmphdr *)(buffer + (sizeof(struct iphdr)));
    if (icmp_hdr->type == ICMP_ECHOREPLY && icmp_hdr->un.echo.id == getpid()) {
        long rtt = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
        printf("Reply from %s: seq=%d time=%ld ms\n", inet_ntoa(addr->sin_addr), icmp_hdr->un.echo.sequence, rtt);
    } else {
        printf("Error: Received an unexpected packet\n");
    }
}

void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket Error");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    for (int i = 0; i < 4; i++) {
        send_ping(sockfd, &addr);
        sleep(1);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip_address = argv[1];
    ping(ip_address);

    return 0;
}