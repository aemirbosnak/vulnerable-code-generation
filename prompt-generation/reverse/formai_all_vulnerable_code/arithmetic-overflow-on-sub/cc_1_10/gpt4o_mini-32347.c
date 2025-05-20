//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h> 
#include <sys/socket.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

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

// Function to ping an IP address
void ping(const char *ip_addr) {
    int sockfd;
    struct sockaddr_in addr_ping;
    struct icmp *icmp_pkt;
    char packet[PACKET_SIZE];
    struct timeval start, end;
    double time_taken;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(ip_addr);
    
    // Prepare the ICMP packet
    icmp_pkt = (struct icmp *) packet;
    icmp_pkt->icmp_type = ICMP_ECHO;
    icmp_pkt->icmp_code = 0;
    icmp_pkt->icmp_id = getpid();
    icmp_pkt->icmp_seq = 1;
    memset(packet + sizeof(struct icmp), 0, PACKET_SIZE - sizeof(struct icmp));
    icmp_pkt->icmp_cksum = checksum(icmp_pkt, sizeof(struct icmp) + PACKET_SIZE - sizeof(struct icmp));

    printf("Pinging %s:\n", ip_addr);
    for (int i = 0; i < PING_COUNT; i++) {
        // Send the packet
        if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr*)&addr_ping, sizeof(addr_ping)) <= 0) {
            perror("Send failed");
            continue;
        }

        // Receive the reply
        socklen_t addr_len = sizeof(addr_ping);
        gettimeofday(&start, NULL);
        if (recvfrom(sockfd, packet, sizeof(packet), 0, (struct sockaddr*)&addr_ping, &addr_len) <= 0) {
            perror("Reply not received");
            continue;
        }
        gettimeofday(&end, NULL);

        // Calculate the time taken for the ping
        time_taken = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
        printf("Reply from %s: bytes=%d time=%.2fms\n", ip_addr, PACKET_SIZE, time_taken);
        
        // Add a delay between pings
        sleep(1);
    }

    close(sockfd);
}

// Main function to execute the ping
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ping(argv[1]);
    return EXIT_SUCCESS;
}