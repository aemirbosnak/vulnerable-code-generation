//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <time.h>

// Ping packet structure
struct ping_pkt {
    struct icmphdr hdr; // ICMP header
    char msg[64]; // Message payload
};

// Checksum calculation function
unsigned short calc_checksum(unsigned short *addr, int len)
{
    int nleft = len;
    int sum = 0;
    unsigned short *w = addr;
    unsigned short answer = 0;

    // Add all 16-bit words to the sum
    while (nleft > 1) {
        sum += *w++;
        nleft -= 2;
    }

    // Add the left-over byte, if any
    if (nleft == 1) {
        *(unsigned char *)(&answer) = *(unsigned char *)w;
        sum += answer;
    }

    // Fold sum into 16 bits
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    answer = ~sum;

    return answer;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    // Create raw socket for sending ICMP packets
    int sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock_fd < 0) {
        perror("socket() error");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Send 5 ping packets to destination IP address
    for (int i = 0; i < 5; i++) {
        struct ping_pkt pkt;
        memset(&pkt, 0, sizeof(pkt));

        // Add ICMP header
        pkt.hdr.type = ICMP_ECHO;
        pkt.hdr.code = 0;
        pkt.hdr.checksum = 0;
        pkt.hdr.un.echo.id = htons(getpid());
        pkt.hdr.un.echo.sequence = htons(i+1);
        // Add payload message
        sprintf(pkt.msg, "Hello, world!");

        // Calculate checksum
        pkt.hdr.checksum = calc_checksum((unsigned short*)&pkt, sizeof(pkt));

        // Send the packet
        clock_t start_time = clock();
        if (sendto(sock_fd, &pkt, sizeof(pkt), 0,
                   (struct sockaddr*)&addr, sizeof(addr)) <= 0) {
            perror("sendto() error");
            continue;
        }

        // Receive the reply packet
        struct ping_pkt reply_pkt;
        struct sockaddr_in reply_addr;
        socklen_t reply_addr_len = sizeof(reply_addr);
        if (recvfrom(sock_fd, &reply_pkt, sizeof(reply_pkt), 0,
                     (struct sockaddr*)&reply_addr, &reply_addr_len) <= 0) {
            perror("recvfrom() error");
            continue;
        }

        // Calculate round-trip time
        double rtt = (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000;

        // Parse the reply packet
        if (reply_pkt.hdr.type == ICMP_ECHOREPLY && reply_pkt.hdr.code == 0) {
            printf("Reply from %s: bytes=%lu time=%.2fms TTL=%d\n",
                   inet_ntoa(reply_addr.sin_addr),
                   sizeof(reply_pkt), rtt, reply_pkt.hdr.un.echo.id);
        } else {
            printf("Error: received ICMP packet with type %d and code %d\n",
                   reply_pkt.hdr.type, reply_pkt.hdr.code);
        }

        // Wait 1 second before sending next packet
        sleep(1);
    }

    // Close the socket
    close(sock_fd);

    return 0;
}