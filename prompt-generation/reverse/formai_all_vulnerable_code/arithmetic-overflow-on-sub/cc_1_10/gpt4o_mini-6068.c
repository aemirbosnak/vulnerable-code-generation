//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <time.h>
#include <signal.h>

#define PACKET_SIZE 64
#define PING_INTERVAL 1
#define PING_COUNT 4

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1) {
        sum += *(unsigned char *)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

void ping(const char *ip_addr) {
    int sockfd;
    struct sockaddr_in addr;
    struct ping_packet packet;
    struct sockaddr_in r_addr;
    struct timespec start_time, end_time;
    socklen_t addr_len = sizeof(r_addr);
    int pid = getpid();
    int i;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = inet_addr(ip_addr);

    memset(&packet, 0, sizeof(packet));
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = pid;

    for (i = 0; i < PING_COUNT; i++) {
        packet.hdr.un.echo.sequence = i + 1;
        packet.hdr.checksum = checksum(&packet, sizeof(packet));

        clock_gettime(CLOCK_MONOTONIC, &start_time);
        if (sendto(sockfd, &packet, sizeof(packet), 0,
                   (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Send failed");
            continue;
        }

        char buf[PACKET_SIZE];
        if (recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&r_addr, &addr_len) < 0) {
            perror("Receive failed");
            continue;
        }

        clock_gettime(CLOCK_MONOTONIC, &end_time);
        double time_taken = (end_time.tv_sec - start_time.tv_sec) * 1e3 + 
                            (end_time.tv_nsec - start_time.tv_nsec) / 1e6;

        struct icmphdr *icmp_hdr = (struct icmphdr *)(buf + (r_addr.sin_addr.s_addr));

        if (icmp_hdr->type == ICMP_ECHOREPLY) {
            printf("Reply from %s: bytes=%ld time=%.2f ms\n",
                   ip_addr, sizeof(packet), time_taken);
        } else {
            printf("Got ICMP type: %d\n", icmp_hdr->type);
        }

        sleep(PING_INTERVAL);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname or IP>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *host = argv[1];
    printf("Pinging %s...\n", host);
    ping(host);

    return 0;
}