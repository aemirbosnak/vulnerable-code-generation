//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <time.h>

#define PACKET_SIZE 64
#define REQUEST_COUNT 5

typedef struct {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
} ping_packet;

unsigned short calculate_checksum(void *paddr, int len) {
    unsigned short *buf = paddr;
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

void create_packet(ping_packet *packet) {
    packet->hdr.type = ICMP_ECHO;
    packet->hdr.un.echo.id = getpid();
    packet->hdr.un.echo.sequence = 1; // We can increment this for multiple packets.
    packet->hdr.checksum = 0; // Initialize checksum to 0.
    strcpy(packet->msg, "Ping Test"); // Custom message can be modified.

    packet->hdr.checksum = calculate_checksum(&packet->hdr, sizeof(packet->hdr) + strlen(packet->msg));
}

void print_statistics(struct timespec start, struct timespec end, const char *ip_address) {
    long time_ns = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
    printf("Ping to %s: Time: %.2f ms\n", ip_address, time_ns / 1e6);
}

int send_ping(int sockfd, struct sockaddr_in *addr, const char *ip_address) {
    ping_packet packet;
    struct timespec start, end;

    create_packet(&packet);
    if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)addr, sizeof(*addr)) <= 0) {
        perror("Ping send failed");
        return -1;
    }

    clock_gettime(CLOCK_MONOTONIC, &start);
    char buffer[PACKET_SIZE];

    socklen_t addr_len = sizeof(*addr);
    if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)addr, &addr_len) <= 0) {
        perror("Ping receive failed");
        return -1;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    print_statistics(start, end, ip_address);
    return 0;
}

void start_ping(const char *ip_address) {
    struct sockaddr_in addr;
    int sockfd;

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    for (int i = 0; i < REQUEST_COUNT; i++) {
        send_ping(sockfd, &addr, ip_address);
        sleep(1); // Wait a second between pings.
    }
    
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *ip_address = argv[1];
    printf("Pinging %s with %d packets...\n", ip_address, REQUEST_COUNT);
    
    start_ping(ip_address);
    
    printf("Ping test complete!\n");
    return 0;
}