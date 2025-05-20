//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <errno.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define PING_COUNT 4

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

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

void send_ping(int sockfd, struct sockaddr_in *addr) {
    struct ping_packet packet;
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    memset(&packet, 0, sizeof(packet));
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    packet.hdr.un.echo.sequence = 1;
    packet.hdr.checksum = checksum(&packet, sizeof(packet));

    while (1) {
        sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)addr, sizeof(*addr));
        printf("Ping sent to %s\n", inet_ntoa(addr->sin_addr));

        fd_set readset;
        FD_ZERO(&readset);
        FD_SET(sockfd, &readset);

        if (select(sockfd + 1, &readset, NULL, NULL, &timeout) > 0) {
            struct sockaddr_in r_addr;
            socklen_t r_len = sizeof(r_addr);
            recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&r_addr, &r_len);
            printf("Reply from %s: time=%.2f ms\n", inet_ntoa(r_addr.sin_addr), (timeout.tv_sec * 1000.0 + timeout.tv_usec / 1000.0));
        } else {
            printf("Request timed out.\n");
        }

        sleep(1);
        break; // For demo purposes, continuous ping loop is omitted
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
        perror("Invalid address/Address not supported");
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    printf("Pinging %s with %d bytes of data:\n", argv[1], PACKET_SIZE);
    for (int i = 0; i < PING_COUNT; i++) {
        send_ping(sockfd, &addr);
    }

    close(sockfd);
    return 0;
}