//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <errno.h>

// Constants
#define PACKET_SIZE 64
#define PING_COUNT 4

// Function prototypes
unsigned short checksum(void *b, int len);
void ping(const char *ip_address, int count);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ip-address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ping(argv[1], PING_COUNT);
    return 0;
}

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

// Function to send ping requests
void ping(const char *ip_address, int count) {
    int sockfd;
    struct sockaddr_in addr;
    struct icmp packet;
    struct timeval timeout;
    char recvbuf[PACKET_SIZE];
    int addr_len = sizeof(addr);
    fd_set fds;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set timeout for recv
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    // Prepare the destination address
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    for (int i = 0; i < count; i++) {
        // Prepare the ICMP packet
        memset(&packet, 0, sizeof(packet));
        packet.icmp_type = ICMP_ECHO;
        packet.icmp_code = 0;
        packet.icmp_id = getpid();
        packet.icmp_seq = i + 1;
        packet.icmp_cksum = checksum(&packet, sizeof(packet));

        // Send the packet
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Packet send failed");
            continue;
        }

        // Wait for a response
        FD_ZERO(&fds);
        FD_SET(sockfd, &fds);
        int result = select(sockfd + 1, &fds, NULL, NULL, &timeout);

        if (result > 0) {
            recvfrom(sockfd, recvbuf, sizeof(recvbuf), 0, (struct sockaddr *)&addr, &addr_len);
            struct iphdr *ip_header = (struct iphdr *)recvbuf;
            struct icmp *icmp_response = (struct icmp *)(recvbuf + (ip_header->ihl * 4));
            if (icmp_response->icmp_type == ICMP_ECHOREPLY && icmp_response->icmp_id == packet.icmp_id) {
                printf("Received response from %s: seq=%d time=%.2f ms\n", 
                    ip_address, 
                    icmp_response->icmp_seq, 
                    (double)(clock() - i) / CLOCKS_PER_SEC * 1000);
            }
        } else {
            printf("Request timed out for seq=%d\n", i + 1);
        }

        sleep(1);  // Wait before sending next ping
    }

    close(sockfd);
}