//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <time.h>
#include <errno.h>

#define PACKET_SIZE 64
#define TIMEOUT 1

// Structure for our ping packet
struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

// Function to calculate the checksum of packets
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

// Function to send a ping
void send_ping(int sockfd, struct sockaddr_in *addr, int ping_seq) {
    struct ping_packet packet;
    struct timeval start_time, end_time;

    memset(&packet, 0, sizeof(packet));
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    packet.hdr.un.echo.sequence = ping_seq;
    gettimeofday(&start_time, NULL);
    packet.hdr.checksum = checksum(&packet, sizeof(packet));

    // Send ICMP request
    if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)addr, sizeof(*addr)) <= 0) {
        perror("Send failed");
        return;
    }

    // Wait for a reply
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    ssize_t recv_len;
    char buffer[PACKET_SIZE];

    recv_len = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&r_addr, &addr_len);
    gettimeofday(&end_time, NULL);
    if (recv_len <= 0) {
        perror("Receive failed");
        return;
    }

    // Process the response
    struct iphdr *ip_hdr = (struct iphdr *)buffer;
    struct icmphdr *icmp_hdr = (struct icmphdr *)(buffer + (ip_hdr->ihl * 4));

    if (icmp_hdr->type == ICMP_ECHOREPLY && icmp_hdr->un.echo.id == getpid()) {
        printf("Reply from %s: seq=%d time=%.2f ms\n",
               inet_ntoa(r_addr.sin_addr), ping_seq,
               (end_time.tv_sec - start_time.tv_sec) * 1000.0 +
               (end_time.tv_usec - start_time.tv_usec) / 1000.0);
    } else {
        printf("Received an unexpected ICMP packet\n");
    }
}

// Function to setup a socket and ping
void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr;

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    printf("Pinging %s with %d bytes of data:\n", ip_address, PACKET_SIZE);
    for (int seq = 1; seq <= 4; seq++) {
        send_ping(sockfd, &addr, seq);
        sleep(1); // Wait a second between pings
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ping(argv[1]);
    return 0;
}