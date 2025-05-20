//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>
#include <errno.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

// Function to calculate the checksum
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

// Function to send a single ping
void send_ping(int sockfd, struct sockaddr_in *addr, int ping_count) {
    struct icmp pkt;
    struct timeval start_time, end_time;
    int i;

    for (i = 0; i < ping_count; i++) {
        memset(&pkt, 0, sizeof(pkt));
        pkt.icmp_type = ICMP_ECHO;
        pkt.icmp_code = 0;
        pkt.icmp_id = getpid();
        pkt.icmp_seq = i + 1;
        pkt.icmp_cksum = checksum(&pkt, sizeof(pkt));

        // Get the current time
        gettimeofday(&start_time, NULL);

        // Send the packet
        if (sendto(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr *) addr, sizeof(*addr)) <= 0) {
            perror("Failed to send ping");
            exit(EXIT_FAILURE);
        }

        // Receive the response
        char buf[PACKET_SIZE];
        socklen_t addr_len = sizeof(*addr);
        if (recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) addr, &addr_len) < 0) {
            perror("Failed to receive ping");
            continue;
        }

        // Get the end time
        gettimeofday(&end_time, NULL);
        long rtt = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;

        printf("Reply from %s: bytes=%d time=%ld ms\n", inet_ntoa(addr->sin_addr), sizeof(pkt), rtt);

        // Sleep for a second before the next ping
        sleep(1);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd;
    struct sockaddr_in addr;

    // Create a raw socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Pinging %s with %d bytes of data:\n", argv[1], PACKET_SIZE);

    send_ping(sockfd, &addr, PING_COUNT);

    close(sockfd);
    return 0;
}