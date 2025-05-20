//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 4
#define TIMEOUT 1

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;

    if (len == 1)
        sum += *(unsigned char*)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);

    result = ~sum;
    return result;
}

void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr_ping;
    struct icmp *icmp_hdr;
    char packet[PACKET_SIZE];
    struct timeval start_time, end_time;
    struct timeval timeout;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    addr_ping.sin_family = AF_INET;
    addr_ping.sin_port = htons(0);
    addr_ping.sin_addr.s_addr = inet_addr(ip_address);

    memset(packet, 0, sizeof(packet));

    icmp_hdr = (struct icmp *)packet;
    icmp_hdr->icmp_type = ICMP_ECHO;
    icmp_hdr->icmp_code = 0;
    icmp_hdr->icmp_id = getpid();
    icmp_hdr->icmp_seq = 1;

    for (int i = 0; i < PING_COUNT; i++) {
        icmp_hdr->icmp_cksum = 0;
        icmp_hdr->icmp_cksum = checksum(packet, PACKET_SIZE);

        gettimeofday(&start_time, NULL);
        if (sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)&addr_ping, sizeof(addr_ping)) <= 0) {
            perror("Send failed");
            continue;
        }

        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

        char recv_buf[PACKET_SIZE];
        socklen_t addr_len = sizeof(addr_ping);

        if (recvfrom(sockfd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *)&addr_ping, &addr_len) > 0) {
            gettimeofday(&end_time, NULL);
            double elapsed = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + 
                             (end_time.tv_usec - start_time.tv_usec) / 1000.0;

            printf("Reply from %s: bytes=%d time=%.2f ms\n", ip_address, PACKET_SIZE, elapsed);
        } else {
            printf("Request timed out for %s\n", ip_address);
        }

        sleep(1); // wait before next ping
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("*************************************\n");
    printf("      Retro Network Ping Test       \n");
    printf("        by RetroCoder 2023         \n");
    printf("*************************************\n");

    ping(argv[1]);

    printf("Ping test completed.\n");
    return 0;
}