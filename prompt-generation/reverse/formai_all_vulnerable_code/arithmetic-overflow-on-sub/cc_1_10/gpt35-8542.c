//FormAI DATASET v1.0 Category: Network Ping Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define PACKET_SIZE 64    // icmp packet size, 64 is standard
#define MAX_WAIT_TIME 5   // seconds to wait for response
#define MAX_NO_PACKETS 3  // number of packets to send  

// Method for checksum calculation
unsigned short calculate_checksum(unsigned short *addr, int len) {
    int nleft = len;
    int sum = 0;
    unsigned short *w = addr;
    unsigned short answer = 0;

    while (nleft > 1) {
        sum += *w++;
        nleft -= 2;
    }

    if (nleft == 1) {
        *(unsigned char *)(&answer) = *(unsigned char *)w;
        sum += answer;
    }

    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    answer = ~sum;
    return answer;
}

// Main function for ping test
void ping(char *ip_addr, int packet_ttl) {
    struct timeval start_tv, end_tv;  // Used for packet RTT calculation

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);  // Socket creation
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(0);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    addr.sin_addr.s_addr = inet_addr(ip_addr);

    int ttl = packet_ttl;
    if (setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl)) < 0) {
        perror("setsockopt failed");
        exit(0);
    }

    int sequence_no = getpid();  // Sequence number to identify packets
    char send_packet[PACKET_SIZE], recv_packet[PACKET_SIZE];

    // ICMP message structure
    struct icmp *icmp_hdr = (struct icmp *)send_packet;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = getpid() & 0xFFFF;
    icmp_hdr->icmp_seq = 0;
    memset(icmp_hdr->icmp_data, 0xa5, PACKET_SIZE - sizeof(struct icmp));
    icmp_hdr->icmp_cksum = calculate_checksum((unsigned short *)icmp_hdr, PACKET_SIZE);

    int packets_sent = 0;
    int packets_received = 0;
    while (packets_sent < MAX_NO_PACKETS) {
        packets_sent++;
        gettimeofday(&start_tv, NULL);  // Start timer
        if (sendto(sockfd, send_packet, sizeof(send_packet), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            perror("sendto failed");
            continue;
        }

        socklen_t addr_len = sizeof(addr);
        int recv_len = recvfrom(sockfd, recv_packet, sizeof(recv_packet), 0, (struct sockaddr *)&addr, &addr_len);
        if (recv_len < 0) {
            printf("Packet %d lost\n", packets_sent);
            continue;
        }

        gettimeofday(&end_tv, NULL);  // Stop timer
        double rtt = ((double)(end_tv.tv_sec - start_tv.tv_sec) * 1000.0) + ((double)(end_tv.tv_usec - start_tv.tv_usec) / 1000.0);
        printf("Packet %d received, RTT = %.3f ms\n", packets_sent, rtt);

        packets_received++;
        sleep(1);  // Wait for 1 second before sending next packet
    }

    printf("\nPing statistics for %s:\n", ip_addr);
    printf("Packets: Sent = %d, Received = %d, Lost = %d (%.2f%% loss)\n", MAX_NO_PACKETS, packets_received, MAX_NO_PACKETS - packets_received, (((MAX_NO_PACKETS - packets_received) * 1.0) / MAX_NO_PACKETS) * 100.0);

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {  // Check if IP address is provided
        printf("Please provide IP address to ping\n");
        return -1;
    }

    char *ip_addr = argv[1];
    int packet_ttl = 64;  // Default TTL value

    printf("Pinging %s with %d bytes of data and TTL=%d\n\n", ip_addr, PACKET_SIZE, packet_ttl);

    ping(ip_addr, packet_ttl);

    return 0;
}