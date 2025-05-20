//FormAI DATASET v1.0 Category: Network Ping Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>

#define PACKET_SIZE     4096
#define MAX_WAIT_TIME   5
#define MAX_NO_PACKETS  3
#define IP_HEADER_SIZE  20
#define ICMP_HEADER_SIZE 8

unsigned short checksum(void *b, int len);

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("usage: %s <ip-address>\n", argv[0]);
        return 0;
    }

    char *ip = argv[1];
    struct in_addr dest_addr;
    if (!inet_aton(ip, &dest_addr)) {
        printf("Inavlid IP address.\n");
        return 0;
    }

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket error");
        return 0;
    }
    int pack_no = 0;
    struct sockaddr_in dest;
    dest.sin_family = AF_INET;
    dest.sin_addr = dest_addr;

    char sendpacket[PACKET_SIZE];
    char recvpacket[PACKET_SIZE];
    bzero(sendpacket, PACKET_SIZE);
    bzero(recvpacket, PACKET_SIZE);
    struct icmp *icmp;
    int len = ICMP_HEADER_SIZE + sizeof(struct timeval);
    icmp = (struct icmp *)(sendpacket);
    icmp->icmp_type = ICMP_ECHO;
    icmp->icmp_code = 0;
    icmp->icmp_seq = pack_no++;
    icmp->icmp_id = getpid();
    memset(icmp->icmp_data, 0xa5, len);
    struct timeval *tval;
    tval = (struct timeval *)(icmp->icmp_data);
    gettimeofday(tval, NULL);
    icmp->icmp_cksum = checksum(icmp, len);

    // Start sending packets
    int sent_count = 0;
    while (sent_count < MAX_NO_PACKETS) {
        int sent_len = sendto(sockfd, sendpacket, len, 0, (struct sockaddr *)&dest, sizeof(dest));
        if (sent_len < 0) {
            perror("sendto error");
            return 0;
        }
        sent_count++;
        sleep(1);
    }

    // Start receiving packets
    int recv_count = 0;
    while (recv_count < MAX_NO_PACKETS) {
        socklen_t fromlen = sizeof(dest);
        int recv_len = recvfrom(sockfd, recvpacket, PACKET_SIZE, 0, (struct sockaddr *)&dest, &fromlen);
        if (recv_len < 0) {
            perror("recvfrom error");
            return 0;
        }
        struct ip *ip = (struct ip *)recvpacket;
        int ip_header_len = ip->ip_hl << 2;
        struct icmp *icmp = (struct icmp *)(recvpacket + ip_header_len);
        int icmp_header_len = ICMP_HEADER_SIZE;
        if (recv_len - ip_header_len < ICMP_HEADER_SIZE) {
            printf("Inavlid ICMP packet.\n");
            return 0;
        }
        if (icmp->icmp_type == ICMP_ECHOREPLY) {
            if (icmp->icmp_id != getpid()) {
                continue;
            }
            struct timeval *tvsend = (struct timeval *)(icmp->icmp_data);
            struct timeval tvrecv;
            gettimeofday(&tvrecv, NULL);
            double rtt = (tvrecv.tv_sec - tvsend->tv_sec) * 1000.0 + (tvrecv.tv_usec - tvsend->tv_usec) / 1000.0;
            printf("Packet %d RTT %.3fms\n", icmp->icmp_seq, rtt);
            recv_count++;
        }
        sleep(1);
    }

    if (close(sockfd) == -1) {
        perror("close error");
        return 0;
    }

    return 0;
}

/* Calculate checksum */
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