//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/ip_icmp.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>
#include <errno.h>
#include <signal.h>

#define PACKET_SIZE 64
#define PING_INTERVAL 1
#define TIMEOUT 1
#define MAX_PINGS 4

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

volatile sig_atomic_t stop_ping = 0;

void handle_alarm(int sig) {
    stop_ping = 1;
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
    int sockfd;
    struct sockaddr_in addr;
    struct ping_packet pkt;
    struct timespec start, end;
    int pkt_count, addr_len = sizeof(addr);
    char buf[1024];
    struct timeval tv;

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket error");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);

    memset(&pkt, 0, sizeof(pkt));
    pkt.hdr.type = ICMP_ECHO;
    pkt.hdr.un.echo.id = getpid();
    strcpy(pkt.msg, "Ping Test Packet");

    for (pkt_count = 0; pkt_count < MAX_PINGS && !stop_ping; pkt_count++) {
        pkt.hdr.un.echo.sequence = pkt_count + 1;
        pkt.hdr.checksum = checksum(&pkt, sizeof(pkt));
        
        clock_gettime(CLOCK_MONOTONIC, &start);
        if (sendto(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr*)&addr, sizeof(addr)) <= 0) {
            perror("Send error");
        }

        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

        if (recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&addr, &addr_len) <= 0) {
            perror("Receive error");
        } else {
            clock_gettime(CLOCK_MONOTONIC, &end);
            double rtt = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;
            printf("Reply from %s: bytes=%d time=%.2f ms\n", ip_addr, PACKET_SIZE, rtt);
        }

        sleep(PING_INTERVAL);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGALRM, handle_alarm);
    
    printf("Pinging %s with %d bytes of data:\n", argv[1], PACKET_SIZE);
    ping(argv[1]);

    return 0;
}