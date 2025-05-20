//FormAI DATASET v1.0 Category: Network Ping Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

#define PACKET_SIZE 64
#define PING_TIMEOUT 1

struct ping_pkt {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

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

void ping(int sockfd, struct sockaddr_in *addr) {
    struct ping_pkt pkt;
    struct timeval start, end;
    double rtt;

    memset(&pkt, 0, sizeof(pkt));
    pkt.hdr.type = ICMP_ECHO;
    pkt.hdr.checksum = checksum(&pkt, sizeof(pkt));
    gettimeofday(&start, NULL);
    sendto(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr *)addr, sizeof(*addr));
    char buffer[PACKET_SIZE];
    socklen_t len = sizeof(*addr);
    if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)addr, &len) > 0) {
        gettimeofday(&end, NULL);
        rtt = (double)(end.tv_sec - start.tv_sec) * 1000 + (double)(end.tv_usec - start.tv_usec) / 1000;
        printf("Received %d bytes from %s: icmp_seq=%d ttl=%d time=%.1f ms\n", sizeof(buffer), inet_ntoa(addr->sin_addr), 1, 1, rtt);
    } else {
        printf("Timed out\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        exit(-1);
    }

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        printf("Error creating socket\n");
        exit(-1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        exit(-1);
    }

    for (int i = 0; i < 5; i++) {
        printf("Pinging %s\n", inet_ntoa(addr.sin_addr));
        ping(sockfd, &addr);
        sleep(PING_TIMEOUT);
    }

    close(sockfd);

    return 0;
}