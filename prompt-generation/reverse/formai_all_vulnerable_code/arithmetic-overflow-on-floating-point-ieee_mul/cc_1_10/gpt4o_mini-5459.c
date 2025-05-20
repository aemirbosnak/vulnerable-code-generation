//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_SLEEP_RATE 1000000 // 1 second
#define MAX_WAIT_TIME 1 // 1 second

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

// Function that pings a specific address
void ping(int sockfd, struct sockaddr_in *addr, const char *ip_addr) {
    struct icmp packet;
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    char rcv_buf[PACKET_SIZE];
    int nbytes;
    time_t start_time;
    struct timeval tv_out;

    tv_out.tv_sec = MAX_WAIT_TIME;
    tv_out.tv_usec = 0;

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv_out, sizeof(tv_out));

    // Prepare the ICMP packet
    memset(&packet, 0, sizeof(packet));
    packet.icmp_type = ICMP_ECHO; // Echo Request
    packet.icmp_code = 0; 
    packet.icmp_id = getpid(); // Process ID
    packet.icmp_seq = 1; 
    packet.icmp_cksum = checksum(&packet, sizeof(packet));

    // Send the ping
    start_time = time(NULL);
    if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)addr, sizeof(*addr)) <= 0) {
        perror("Ping send failed");
        return;
    }

    // Wait for a response
    nbytes = recvfrom(sockfd, rcv_buf, sizeof(rcv_buf), 0, (struct sockaddr *)&r_addr, &addr_len);
    if (nbytes <= 0) {
        perror("Ping response failed");
        return;
    }

    // Response received
    time_t end_time = time(NULL);
    double time_taken = difftime(end_time, start_time) * 1000; // Convert to milliseconds

    struct iphdr *ip_header = (struct iphdr*) rcv_buf;
    struct icmp *icmp_header = (struct icmp*)(rcv_buf + (ip_header->ihl*4));

    printf("Reply from %s: bytes=%d time=%.2fms\n", ip_addr, nbytes, time_taken);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip_addr = argv[1];
    struct sockaddr_in addr;
    int sockfd;

    // Create ICMP socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;

    if (inet_pton(AF_INET, ip_addr, &addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address: %s\n", ip_addr);
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Pinging %s:\n", ip_addr);

    // Run the ping process
    for (int i = 0; i < 5; i++) { // Ping 5 times
        ping(sockfd, &addr, ip_addr);
        usleep(PING_SLEEP_RATE);
    }

    close(sockfd);
    printf("Ping test completed.\n");
    return 0;
}