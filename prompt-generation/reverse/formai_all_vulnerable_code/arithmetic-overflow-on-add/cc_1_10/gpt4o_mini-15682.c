//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>
#include <errno.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

// Function to calculate checksum of the packet
unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        sum += *((unsigned char*)buf);
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// Function to create an ICMP packet
void create_packet(struct icmp *icmp_hdr) {
    memset(icmp_hdr, 0, sizeof(struct icmp));
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = getpid();
    icmp_hdr->icmp_seq = 1;
    icmp_hdr->icmp_cksum = checksum(icmp_hdr, sizeof(struct icmp));
}

// Function to perform the ping test
void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr;
    struct icmp icmp_hdr;
    struct timeval start_time, end_time;
    char packet[PACKET_SIZE];
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    for (int i = 0; i < PING_COUNT; i++) {
        create_packet(&icmp_hdr);
        memcpy(packet, &icmp_hdr, sizeof(icmp_hdr));

        // Record start time for response
        gettimeofday(&start_time, NULL);
        
        // Sending the packet
        if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr*)&addr, sizeof(addr)) <= 0) {
            perror("Failed to send packet");
            continue;
        }

        socklen_t addr_len = sizeof(addr);
        // Receiving the reply
        if (recvfrom(sockfd, packet, sizeof(packet), 0, (struct sockaddr*)&addr, &addr_len) < 0) {
            perror("Failed to receive packet");
            continue;
        }
        
        // Record end time after receiving reply
        gettimeofday(&end_time, NULL);
        
        // Calculating time taken for reply
        long time_taken = ((end_time.tv_sec - start_time.tv_sec) * 1000) +
                          ((end_time.tv_usec - start_time.tv_usec) / 1000);
        
        printf("Ping to %s: %ld ms\n", ip_address, time_taken);
        sleep(1); // Wait between pings
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Initiating ping test to %s...\n", argv[1]);
    ping(argv[1]);

    printf("Ping test completed.\n");
    return 0;
}