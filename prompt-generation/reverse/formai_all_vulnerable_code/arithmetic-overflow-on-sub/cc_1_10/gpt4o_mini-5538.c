//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <errno.h>

#define PACKET_SIZE 64
#define PING_COUNT 5
#define TIMEOUT 1

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

volatile int running = 1;

void handle_signal(int signal) {
    running = 0;
}

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

void ping(const char *ip_addr) {
    int sockfd;
    struct sockaddr_in addr;
    struct ping_packet packet;
    struct timeval timeout;
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    inet_pton(AF_INET, ip_addr, &addr.sin_addr);
    
    for (int i = 0; i < PING_COUNT && running; i++) {
        memset(&packet, 0, sizeof(packet));
        packet.hdr.type = ICMP_ECHO;
        packet.hdr.un.echo.id = getpid();
        packet.hdr.un.echo.sequence = i + 1;
        packet.hdr.checksum = checksum(&packet, sizeof(packet));

        clock_t start_time = clock();
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Ping request failed");
            continue;
        }
        
        char response[PACKET_SIZE];
        if (recvfrom(sockfd, response, sizeof(response), 0, (struct sockaddr *)&r_addr, &addr_len) <= 0) {
            perror("Ping response failed");
            continue;
        }

        clock_t end_time = clock();
        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000; // Convert to ms

        struct iphdr *ip_header = (struct iphdr *)response;
        struct icmphdr *icmp_header = (struct icmphdr *)(response + (ip_header->ihl * 4));
        if (icmp_header->type == ICMP_ECHOREPLY && icmp_header->un.echo.id == getpid()) {
            printf("Ping to %s: %d bytes from %s: icmp_seq=%d time=%.2f ms\n",
                   ip_addr, PACKET_SIZE, inet_ntoa(r_addr.sin_addr),
                   icmp_header->un.echo.sequence, time_taken);
        }
        sleep(1); // Rate limit ping requests
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    signal(SIGINT, handle_signal);
    ping(argv[1]);
    return EXIT_SUCCESS;
}