//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/ip_icmp.h>
#include <time.h>
#include <errno.h>

#define PACKET_SIZE 64
#define PING_TIMEOUT 1
#define MAX_ATTEMPTS 4

// Define ICMP header structure
struct icmp_packet {
    struct icmphdr header;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

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

// Function to send ICMP echo request
int ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr_ping;
    struct icmp_packet packet;
    struct sockaddr_in addr_recv;
    socklen_t addr_len = sizeof(addr_recv);
    char buffer[PACKET_SIZE];
    struct timeval start_time, end_time;
    int attempts, received;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(ip_address);

    // Prepare the ICMP packet
    memset(&packet, 0, sizeof(packet));
    packet.header.type = ICMP_ECHO;
    packet.header.un.echo.id = getpid();
    packet.header.un.echo.sequence = 1;
    packet.header.checksum = checksum(&packet, sizeof(packet));

    for (attempts = 0; attempts < MAX_ATTEMPTS; attempts++) {
        gettimeofday(&start_time, NULL);
        sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr_ping, sizeof(addr_ping));
        
        received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr_recv, &addr_len);
        gettimeofday(&end_time, NULL);
        
        if (received < 0) {
            perror("Receive failed");
            printf("Ping to %s failed.\n", ip_address);
        } else if (received > 0 && (buffer[20] == ICMP_ECHO)) {
            long elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000 + 
                               (end_time.tv_usec - start_time.tv_usec) / 1000;
            printf("Reply from %s: bytes=%d time=%ld ms\n", ip_address, received, elapsed_time);
        }
        sleep(1);
    }

    close(sockfd);
    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip_address = argv[1];
    printf("Pinging %s:\n", ip_address);
    ping(ip_address);
    return 0;
}