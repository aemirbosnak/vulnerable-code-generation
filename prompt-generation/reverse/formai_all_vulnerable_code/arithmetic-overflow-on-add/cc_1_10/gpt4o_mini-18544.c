//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/ip_icmp.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define MAX_ATTEMPTS 4
#define ICMP_ECHO 8

typedef struct {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
} ping_packet;

void send_ping(int sockfd, struct sockaddr_in *addr, const char *ip_addr);
void receive_ping(int sockfd);
void ping(const char *ip_addr);
unsigned short checksum(void *b, int len);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ping(argv[1]);
    return 0;
}

void ping(const char *ip_addr) {
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);

    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        send_ping(sockfd, &addr, ip_addr);
        receive_ping(sockfd);
        sleep(1);
    }

    close(sockfd);
}

void send_ping(int sockfd, struct sockaddr_in *addr, const char *ip_addr) {
    ping_packet packet;
    memset(&packet, 0, sizeof(packet));
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    packet.hdr.un.echo.sequence = 1; // Increment for each packet sent
    packet.hdr.checksum = checksum(&packet, sizeof(packet));

    clock_t start_time = clock();
    if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *) addr, sizeof(*addr)) <= 0) {
        perror("Failed to send packet");
        return;
    }

    printf("Ping sent to %s\n", ip_addr);
}

void receive_ping(int sockfd) {
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    char buffer[PACKET_SIZE];
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(sockfd, &read_fds);

    if (select(sockfd + 1, &read_fds, NULL, NULL, &tv) > 0) {
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&r_addr, &addr_len) > 0) {
            struct iphdr *ip_hdr = (struct iphdr *) buffer;
            struct icmphdr *icmp_hdr = (struct icmphdr *) (buffer + (ip_hdr->ihl * 4));
            if (icmp_hdr->type == 0 && icmp_hdr->un.echo.id == getpid()) {
                printf("Received reply from %s: icmp_seq=%d ttl=%d time=%.2f ms\n",
                       inet_ntoa(r_addr.sin_addr),
                       icmp_hdr->un.echo.sequence,
                       ip_hdr->ttl,
                       ((double) (clock() - ((clock_t) icmp_hdr->un.echo.sequence))) / CLOCKS_PER_SEC * 1000.0);
            } else {
                printf("Received erroneous packet from %s\n", inet_ntoa(r_addr.sin_addr));
            }
        }
    } else {
        printf("Request timed out.\n");
    }
}

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;

    if (len == 1)
        sum += *(unsigned char *)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}