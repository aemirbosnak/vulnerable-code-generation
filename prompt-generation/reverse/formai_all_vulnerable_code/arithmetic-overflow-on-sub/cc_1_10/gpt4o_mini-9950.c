//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: visionary
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
#include <signal.h>
#include <time.h>

#define PACKET_SIZE 64
#define TIMEOUT 1

typedef struct {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
} ping_packet;

int sockfd;
struct sockaddr_in target_addr;
int ping_count = 0;

void handler(int sig) {
    printf("\nPing operation interrupted. Sent %d packets.\n", ping_count);
    exit(0);
}

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
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof timeout);

    ping_packet packet;
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    memset(packet.msg, 0, sizeof(packet.msg));
    snprintf(packet.msg, sizeof(packet.msg), "Ping message from PID: %d", getpid());
    packet.hdr.un.echo.sequence = ping_count++;
    packet.hdr.checksum = checksum(&packet, sizeof(packet)); 

    clock_t start_time, end_time;
    socklen_t addr_len = sizeof(target_addr);
    start_time = clock();

    if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&target_addr, addr_len) <= 0) {
        perror("Failed to send packet");
        return;
    }

    char buffer[PACKET_SIZE];
    if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&target_addr, &addr_len) <= 0) {
        printf("Request timed out.\n");
        return;
    }

    end_time = clock();
    double rtt = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000;

    struct iphdr *ip_header = (struct iphdr *)(buffer + sizeof(struct icmphdr));
    struct icmphdr *icmp_header = (struct icmphdr *)(buffer + ip_header->ihl * 4);

    if (icmp_header->type == ICMP_ECHOREPLY && icmp_header->un.echo.id == getpid()) {
        printf("Reply from %s: bytes=%d time=%.2f ms\n", ip_addr, PACKET_SIZE, rtt);
    } else {
        printf("Unexpected ICMP packet received.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, handler);
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, argv[1], &target_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    printf("Pinging %s with %d bytes of data:\n", argv[1], PACKET_SIZE);
    while (1) {
        ping(argv[1]);
        sleep(1);
    }

    close(sockfd);
    return 0;
}