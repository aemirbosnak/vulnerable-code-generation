//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 5
#define TIMEOUT 1

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

void ping(const char *target_ip) {
    int sockfd;
    struct sockaddr_in addr;
    struct icmp packet;
    struct sockaddr_in r_addr;
    char buffer[PACKET_SIZE];
    struct timespec start, end;
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(target_ip);
    
    for (int i = 0; i < PING_COUNT; i++) {
        memset(&packet, 0, sizeof(packet));
        packet.icmp_type = ICMP_ECHO;
        packet.icmp_code = 0;
        packet.icmp_id = getpid();
        packet.icmp_seq = i + 1;
        packet.icmp_cksum = checksum(&packet, sizeof(packet));

        clock_gettime(CLOCK_MONOTONIC, &start);
        
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *) &addr, sizeof(addr)) <= 0) {
            perror("Send failed");
            continue;
        }

        // Wait for a response
        fd_set fds;
        struct timeval tv;
        
        FD_ZERO(&fds);
        FD_SET(sockfd, &fds);
        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;

        int select_result = select(sockfd + 1, &fds, NULL, NULL, &tv);
        if (select_result > 0) {
            socklen_t addr_len = sizeof(r_addr);
            int recv_len = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&r_addr, &addr_len);
            clock_gettime(CLOCK_MONOTONIC, &end);

            if (recv_len > 0) {
                double elapsed = (end.tv_sec - start.tv_sec) * 1e3;
                elapsed += (end.tv_nsec - start.tv_nsec) / 1e6;
                printf("Reply from %s: Time=%.2f ms\n", target_ip, elapsed);
            }
        } else {
            printf("Request timed out for %s\n", target_ip);
        }
        sleep(1);
    }
    
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <target_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    const char *target_ip = argv[1];
    printf("Starting QoS monitor for %s...\n", target_ip);
    ping(target_ip);

    return 0;
}