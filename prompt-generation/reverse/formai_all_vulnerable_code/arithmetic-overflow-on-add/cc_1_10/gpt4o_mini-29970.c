//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <sys/time.h>

#define PACKET_SIZE 64
#define PING_INTERVAL 1
#define PING_COUNT 4

// Function to calculate checksum
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

// ICMP echo request packet
void send_ping(int sockfd, const char *ip_addr, int seq_num) {
    struct icmp packet;
    struct sockaddr_in addr;
    struct timeval time_start, time_end;
    socklen_t addr_len = sizeof(addr);
    char buffer[PACKET_SIZE];
    
    memset(&packet, 0, sizeof(packet));
    packet.icmp_type = ICMP_ECHO;
    packet.icmp_code = 0;
    packet.icmp_seq = seq_num;
    packet.icmp_id = getpid();
    packet.icmp_cksum = checksum(&packet, sizeof(packet));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);
    
    gettimeofday(&time_start, NULL);
    sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr));
    int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, &addr_len);
    gettimeofday(&time_end, NULL);
    
    if (n < 0) {
        perror("Ping failed");
        return;
    }

    struct iphdr *ip_header = (struct iphdr *)buffer;
    struct icmp *icmp_response = (struct icmp *)(buffer + (ip_header->ihl << 2));
    
    if (icmp_response->icmp_type == ICMP_ECHOREPLY) {
        long rtt = (time_end.tv_sec - time_start.tv_sec) * 1000 + 
                    (time_end.tv_usec - time_start.tv_usec) / 1000;
        printf("Reply from %s: bytes=%d seq=%d time=%ld ms\n",
                ip_addr, n, seq_num, rtt);
    } else {
        printf("Received unknown ICMP type: %d\n", icmp_response->icmp_type);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }
    
    const char *ip_addr = argv[1];
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    printf("Pinging %s with %d bytes of data:\n", ip_addr, PACKET_SIZE);
    
    for (int i = 0; i < PING_COUNT; i++) {
        send_ping(sockfd, ip_addr, i + 1);
        sleep(PING_INTERVAL);
    }
    
    close(sockfd);
    return 0;
}