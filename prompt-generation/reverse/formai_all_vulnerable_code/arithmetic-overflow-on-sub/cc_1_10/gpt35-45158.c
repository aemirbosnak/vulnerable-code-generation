//FormAI DATASET v1.0 Category: Network Ping Test ; Style: scientific
// A Unique C Network Ping Test Example Program
// By [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>

#define PACKET_SIZE 64
#define PING_TIMEOUT 1

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;

    if (len == 1)
        sum += *(unsigned char*) buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;

    return result;
}

void ping(struct sockaddr_in *addr) {
    int sockfd, rc, i;
    char packet[PACKET_SIZE];
    struct icmp *icmp_pkt = (struct icmp*) packet;
    struct timeval start_time, end_time;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Prepare ICMP header
    icmp_pkt->icmp_type = ICMP_ECHO;
    icmp_pkt->icmp_code = 0;
    icmp_pkt->icmp_id = getpid() & 0xFFFF;
    icmp_pkt->icmp_seq = 0;
    memset(icmp_pkt->icmp_data, 0xa5, PACKET_SIZE - sizeof(struct icmp));

    // Calculate ICMP Checksum
    icmp_pkt->icmp_cksum = 0;
    icmp_pkt->icmp_cksum = checksum(icmp_pkt, PACKET_SIZE);

    // Get start time
    gettimeofday(&start_time, NULL);

    // Send ICMP packet
    rc = sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr*)addr, sizeof(*addr));
    if (rc < 0 || rc != PACKET_SIZE) {
        perror("sendto");
    }

    // Receive ICMP reply
    struct sockaddr_in reply_addr;
    socklen_t reply_addr_len = sizeof(reply_addr);
    char reply[PACKET_SIZE];
    struct icmphdr *icmp_reply = (struct icmphdr *) reply;

    rc = recvfrom(sockfd, reply, PACKET_SIZE, 0, (struct sockaddr *)&reply_addr, &reply_addr_len);
    if (rc < 0) {
        printf("Request timed out.\n");
    } else if (icmp_reply->type == ICMP_ECHOREPLY) {
        // Get end time
        gettimeofday(&end_time, NULL);

        // Calculate Round Trip Time (RTT)
        long rtt = (end_time.tv_sec - start_time.tv_sec) * 1000000;
        rtt += end_time.tv_usec - start_time.tv_usec;

        printf("Received ping reply from %s: seq=%u time=%.3f ms\n", inet_ntoa(addr->sin_addr), icmp_pkt->icmp_seq, (float)rtt/1000.0);
    } else {
        printf("Received unknown ICMP packet type %d\n", icmp_reply->type);
    }

    close(sockfd);
}

int main(int argc, char **argv) {
    char *ip_address;
    struct sockaddr_in addr;

    if (argc < 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ip_address = argv[1];
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;

    if (inet_aton(ip_address, &addr.sin_addr) == 0) {
        printf("Invalid IP address: %s\n", ip_address);
        exit(EXIT_FAILURE);
    }

    while(1) {
        printf("Pinging %s...\n", ip_address);
        ping(&addr);
        sleep(PING_TIMEOUT);
    }

    return 0;
}