//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

// Function to calculate the checksum for ICMP packets
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

// Function to create and send an ICMP echo request
void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in recv_addr;
    struct icmp packet;
    struct timespec start, end;
    int addr_len = sizeof(recv_addr);
    
    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket error");
        exit(EXIT_FAILURE);
    }

    // Prepare the ICMP packet
    memset(&packet, 0, sizeof(packet)); 
    packet.icmp_type = ICMP_ECHO; 
    packet.icmp_code = 0;          
    packet.icmp_id = getpid();        
    packet.icmp_seq = 1;              
    packet.icmp_cksum = checksum(&packet, sizeof(packet));

    // Target address struct
    memset(&recv_addr, 0, sizeof(recv_addr));
    recv_addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, ip_address, &recv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    printf("Pinging %s...\n", ip_address);

    // Send the packet
    clock_gettime(CLOCK_MONOTONIC, &start);
    if (sendto(sockfd, &packet, sizeof(packet), 0, 
               (struct sockaddr *)&recv_addr, sizeof(recv_addr)) <= 0) {
        perror("Sending error");
        exit(EXIT_FAILURE);
    }

    // Prepare to receive response
    char buffer[1024];
    if (recvfrom(sockfd, buffer, sizeof(buffer), 0, 
                 (struct sockaddr *)&recv_addr, (socklen_t *)&addr_len) <= 0) {
        perror("Receiving error");
        exit(EXIT_FAILURE);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate time taken
    double time_taken = (end.tv_sec - start.tv_sec) * 1000.0;      // sec to ms
    time_taken += (end.tv_nsec - start.tv_nsec) / 1000000.0;  // ns to ms

    printf("Response from %s: time=%.2f ms\n", ip_address, time_taken);

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address or hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *target_ip = argv[1];
    ping(target_ip);

    return EXIT_SUCCESS;
}