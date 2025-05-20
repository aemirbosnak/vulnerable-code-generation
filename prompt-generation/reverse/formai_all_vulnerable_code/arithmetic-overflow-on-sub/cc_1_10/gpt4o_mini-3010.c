//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>

#define PING_PACKET_SIZE 64
#define PING_COUNT 4
#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0

struct icmp_packet {
    struct icmphdr header;
    char msg[PING_PACKET_SIZE - sizeof(struct icmphdr)];
};

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

// Function to create and send an ICMP echo request
void ping(const char *ip_address) {
    struct sockaddr_in addr;
    int sockfd;
    struct icmp_packet packet;
    int addr_len = sizeof(addr);
    char recv_buf[1024];
    int sent, received;
    clock_t start, end;
    double elapsed;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    addr.sin_addr.s_addr = inet_addr(ip_address);

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        return;
    }

    for (int i = 0; i < PING_COUNT; i++) {
        // Prepare the ICMP packet
        memset(&packet, 0, sizeof(packet));
        packet.header.type = ICMP_ECHO_REQUEST;
        packet.header.un.echo.id = getpid();
        packet.header.un.echo.sequence = i + 1;
        packet.header.checksum = checksum(&packet, sizeof(packet));

        // Get the start time and send the packet
        start = clock();
        if ((sent = sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, addr_len)) <= 0) {
            perror("Packet send failed");
            continue;
        }

        // Wait for a response
        if ((received = recvfrom(sockfd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *)&addr, &addr_len)) > 0) {
            end = clock();
            elapsed = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
            struct iphdr *ip = (struct iphdr *)recv_buf;
            struct icmphdr *icmp = (struct icmphdr *)(recv_buf + (ip->ihl * 4));

            // Check for valid ICMP reply
            if (icmp->type == ICMP_ECHO_REPLY && icmp->un.echo.id == getpid()) {
                printf("Reply from %s: bytes=%d time=%.2lf ms\n", ip_address, received, elapsed);
            } else {
                printf("Received invalid ICMP packet\n");
            }
        } else {
            printf("No reply from %s\n", ip_address);
        }

        sleep(1);  // Wait a second before sending the next ping
    }

    close(sockfd);
}

// Main function to drive the ping test
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ping(argv[1]);
    return 0;
}