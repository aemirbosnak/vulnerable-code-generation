//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_TIMEOUT 1
#define NUM_PACKETS 4

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;
    
    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        sum += *((unsigned char *)buf);
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    
    return result;
}

void ping(const char *ip_addr) {
    int sockfd;
    struct sockaddr_in addr_ping;
    struct ping_packet packet;
    struct timeval start_time, end_time;
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(ip_addr);

    // Sending ping packets
    for (int i = 0; i < NUM_PACKETS; i++) {
        memset(&packet, 0, sizeof(packet));
        packet.hdr.type = ICMP_ECHO;
        packet.hdr.un.echo.id = getpid();
        packet.hdr.un.echo.sequence = i + 1;
        packet.hdr.checksum = checksum(&packet, sizeof(packet));
        
        gettimeofday(&start_time, NULL);
        
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&addr_ping, sizeof(addr_ping)) <= 0) {
            perror("Send failed");
            continue;
        }

        char buffer[1024];
        socklen_t addr_len = sizeof(addr_ping);
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr_ping, &addr_len) > 0) {
            gettimeofday(&end_time, NULL);
            double rtt = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec) / 1000.0;
            printf("Reply from %s: time=%.2f ms\n", ip_addr, rtt);
        } else {
            printf("Request timed out.\n");
        }
        
        sleep(1); // wait before sending the next ping
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ping(argv[1]);

    return EXIT_SUCCESS;
}