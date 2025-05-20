//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>

// Cybernetic Node Identifier
#define CYBER_NET "0xLOCUS-3000"
#define MAX_PINGS 5
#define PING_TIMEOUT 1

// Function to calculate the checksum of the packet
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

// Function to send ICMP echo request
void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr;
    struct icmphdr icmp_hdr;
    struct timeval start, end;
    char packet[64];
    int ping_count = 0;
    int ttl = 64;

    printf("%s - Initiating cyber ping to %s...\n", CYBER_NET, ip_address);

    // Create raw socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    while (ping_count < MAX_PINGS) {
        memset(&addr, 0, sizeof(addr));
        memset(&icmp_hdr, 0, sizeof(icmp_hdr));
        memset(packet, 0, sizeof(packet));

        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(ip_address);
        
        icmp_hdr.type = ICMP_ECHO;
        icmp_hdr.un.echo.id = getpid();
        icmp_hdr.un.echo.sequence = ping_count++;
        icmp_hdr.checksum = checksum(&icmp_hdr, sizeof(icmp_hdr));

        gettimeofday(&start, NULL);
        if (sendto(sockfd, &icmp_hdr, sizeof(icmp_hdr), 0, (struct sockaddr*)&addr, sizeof(addr)) <= 0) {
            perror("Failed to send packet");
        }

        char response[64];
        struct sockaddr_in response_addr;
        socklen_t addr_len = sizeof(response_addr);

        if (recvfrom(sockfd, response, sizeof(response), 0, (struct sockaddr*)&response_addr, &addr_len) > 0) {
            gettimeofday(&end, NULL);
            long time_taken = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
            printf("Ping %s: %ld ms\n", ip_address, time_taken);
        } else {
            printf("Ping %s: Request timed out\n", ip_address);
        }

        sleep(PING_TIMEOUT);
    }

    close(sockfd);
    printf("%s - Cyber ping finished for %s.\n", CYBER_NET, ip_address);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];

    // Activate the cyber network pulse
    ping(ip_address);

    return EXIT_SUCCESS;
}