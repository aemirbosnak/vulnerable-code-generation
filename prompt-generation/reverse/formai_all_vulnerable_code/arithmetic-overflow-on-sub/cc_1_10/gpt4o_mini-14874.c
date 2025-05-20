//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/ip_icmp.h>
#include <time.h>

#define PING_PKT_S 64  // Packet Size
#define PING_SLEEP_RATE 1000000  // Time between Pings

// ICMP Header
struct ping_pkt {
    struct icmphdr hdr;
    char msg[PING_PKT_S - sizeof(struct icmphdr)];
};

// Function to calculate checksum
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

// Function to perform Ping
void ping(const char *ip_addr) {
    int sockfd;
    struct sockaddr_in r_addr;
    struct ping_pkt pkt;
    struct timeval start_time, end_time, timeout_tv;
    int addr_len, msg_count = 0, packet_sent, packet_receive = 0;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket Error");
        exit(EXIT_FAILURE);
    }

    r_addr.sin_family = AF_INET;
    r_addr.sin_addr.s_addr = inet_addr(ip_addr);

    printf("Pinging %s with %d bytes of data\n", ip_addr, PING_PKT_S);

    while (1) {
        memset(&pkt, 0, sizeof(pkt));
        pkt.hdr.type = ICMP_ECHO;
        pkt.hdr.un.echo.id = getpid();
        pkt.hdr.un.echo.sequence = msg_count++;
        pkt.hdr.checksum = checksum(&pkt, sizeof(pkt));

        gettimeofday(&start_time, NULL);
        packet_sent = sendto(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr*)&r_addr, sizeof(r_addr));
        if (packet_sent <= 0) {
            perror("Sendto Error");
            continue;
        }

        // Setting timeout for recvfrom
        timeout_tv.tv_sec = 1; 
        timeout_tv.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout_tv, sizeof(timeout_tv));

        addr_len = sizeof(r_addr);
        if (recvfrom(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr*)&r_addr, &addr_len) > 0) {
            gettimeofday(&end_time, NULL);
            double time_taken = (end_time.tv_sec - start_time.tv_sec) * 1000.0;
            time_taken += (end_time.tv_usec - start_time.tv_usec) / 1000.0;
            printf("Reply from %s: bytes=%d time=%.2f ms\n", ip_addr, packet_sent, time_taken);
            packet_receive++;
        } else {
            printf("Request timed out.\n");
        }

        // Sleep between pings
        usleep(PING_SLEEP_RATE);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    ping(argv[1]);
    return 0;
}