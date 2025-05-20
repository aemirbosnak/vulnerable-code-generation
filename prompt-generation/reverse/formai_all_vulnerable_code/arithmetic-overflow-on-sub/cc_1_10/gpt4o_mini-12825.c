//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define PACKET_SIZE 64
#define ICMP_ECHO 8 
#define ICMP_TIMEOUT 1

typedef struct {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
} ping_packet;

void handle_signal(int signal) {
    // To handle the termination of the program gracefully
    printf("\nPing test stopped.\n");
    exit(0);
}

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result = 0;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *)buf;
    
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr_ping;
    ping_packet packet;
    int ttl_val = 64;
    struct timespec start, end;

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl_val, sizeof(ttl_val));

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(ip_address);
    
    memset(&packet, 0, sizeof(packet));
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    strncpy(packet.msg, "Ping Test Packet", sizeof(packet.msg) - 1);
    packet.hdr.un.echo.sequence = 1;
    packet.hdr.checksum = checksum(&packet, sizeof(packet));

    if (sendto(sockfd, &packet, sizeof(packet), 0,
               (struct sockaddr*)&addr_ping, sizeof(addr_ping)) <= 0) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    clock_gettime(CLOCK_MONOTONIC, &start);

    char buffer[PACKET_SIZE];
    socklen_t addrlen = sizeof(addr_ping);

    if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr_ping, &addrlen) < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    struct icmphdr *recv_hdr = (struct icmphdr *)(buffer + sizeof(struct iphdr));

    if (recv_hdr->type == 0 && recv_hdr->un.echo.id == packet.hdr.un.echo.id) {
        double time_taken = (end.tv_sec - start.tv_sec) * 1000.0 + 
                            (end.tv_nsec - start.tv_nsec) / 1000000.0;
        printf("Received ping from %s: seq=%u, time=%.2f ms\n", ip_address, 
               recv_hdr->un.echo.sequence, time_taken);
    } else {
        printf("Received packet from %s, but no valid PING response\n", ip_address);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, handle_signal);  // Handle Ctrl+C interruption
    ping(argv[1]);

    return 0;
}