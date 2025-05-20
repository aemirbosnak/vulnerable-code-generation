//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_INTERVAL 1
#define MAX_PINGS 5

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
    if (len == 1)
        sum += *(unsigned char *)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr_ping;
    struct ping_packet packet;
    struct timespec start_time, end_time;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    addr_ping.sin_family = AF_INET;
    addr_ping.sin_port = htons(0);
    addr_ping.sin_addr.s_addr = inet_addr(ip_address);

    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    strncpy(packet.msg, "PingTestMessage", sizeof(packet.msg) - 1);
    packet.hdr.un.echo.sequence = 0;

    for (int i = 0; i < MAX_PINGS; i++) {
        packet.hdr.checksum = checksum(&packet, sizeof(packet));

        clock_gettime(CLOCK_MONOTONIC, &start_time);

        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&addr_ping, sizeof(addr_ping)) <= 0) {
            perror("Send failed");
            break;
        }

        // Prepare to receive the reply
        char buffer[PACKET_SIZE];
        socklen_t addr_len = sizeof(addr_ping);
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr_ping, &addr_len) <= 0) {
            perror("Receive failed");
            break;
        }

        clock_gettime(CLOCK_MONOTONIC, &end_time);
        double time_taken = (end_time.tv_sec - start_time.tv_sec) * 1e9; // to nanoseconds
        time_taken = (time_taken + (end_time.tv_nsec - start_time.tv_nsec)) * 1e-6; // to milliseconds

        struct iphdr *ip = (struct iphdr *) buffer;
        struct icmphdr *icmp = (struct icmphdr *) (buffer + (ip->ihl << 2));

        if (icmp->type == ICMP_ECHOREPLY && icmp->un.echo.id == getpid()) {
            printf("Reply from %s: bytes=%d time=%.2f ms\n", ip_address, PACKET_SIZE, time_taken);
        }

        packet.hdr.un.echo.sequence++;
        sleep(PING_INTERVAL);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Starting ping test to %s...\n", argv[1]);
    ping(argv[1]);

    printf("Ping test completed.\n");
    return EXIT_SUCCESS;
}