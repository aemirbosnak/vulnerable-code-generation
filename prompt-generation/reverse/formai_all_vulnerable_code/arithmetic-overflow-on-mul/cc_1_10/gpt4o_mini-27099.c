//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <time.h>
#include <signal.h>

#define PING_INTERVAL 1  // Ping every second
#define PING_COUNT 10    // Number of pings to send

// ICMP packet structure
struct ping_pkt {
    struct icmphdr hdr;
    char msg[64];
};

// Global variables to maintain statistics
int ping_count = 0;
int loss_count = 0;
struct timespec last_send_time;

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

// Function to send ping requests
void send_ping(int sockfd, struct sockaddr_in *addr) {
    struct ping_pkt packet;
    memset(&packet, 0, sizeof(packet));
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    packet.hdr.un.echo.sequence = ping_count++;
    packet.hdr.checksum = checksum(&packet, sizeof(packet));

    clock_gettime(CLOCK_MONOTONIC, &last_send_time);

    if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)addr, sizeof(*addr)) <= 0) {
        perror("Ping failed");
        loss_count++;
    }
}

// Function to receive ping responses
void receive_ping(int sockfd) {
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    char buf[1024];

    // Set a timeout for recvfrom
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

    int bytes_received = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr*)&r_addr, &addr_len);
    if (bytes_received <= 0) {
        loss_count++;
        return;
    }
    
    struct iphdr *ip_header = (struct iphdr *)buf;
    struct icmphdr *icmp_header = (struct icmphdr *)(buf + (ip_header->ihl * 4));

    // Ignore non-echo replies
    if (icmp_header->type != ICMP_ECHOREPLY) {
        return;
    }

    struct timespec now;
    clock_gettime(CLOCK_MONOTONIC, &now);
    long latency = (now.tv_sec - last_send_time.tv_sec) * 1000 + 
                   (now.tv_nsec - last_send_time.tv_nsec) / 1000000;
    
    printf("Reply from %s: bytes=%d time=%ld ms\n", 
           inet_ntoa(r_addr.sin_addr), bytes_received, latency);
}

// Signal handler for cleanup
void cleanup(int signum) {
    printf("\nPing statistics:\n");
    printf("%d packets transmitted, %d received, %%%d packet loss\n",
           ping_count, ping_count - loss_count, (loss_count * 100) / ping_count);
    exit(0);
}

int main() {
    signal(SIGINT, cleanup);

    int sockfd;
    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    addr.sin_addr.s_addr = inet_addr("8.8.8.8"); // Example: pinging Google DNS

    while (ping_count < PING_COUNT) {
        send_ping(sockfd, &addr);
        receive_ping(sockfd);
        sleep(PING_INTERVAL);
    }

    cleanup(0);
    close(sockfd);
    return 0;
}