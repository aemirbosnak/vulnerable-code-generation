//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <errno.h>

#define PACKET_SIZE 64
#define PING_COUNT 4

struct ping_packet {
    struct icmp hdr;
    char msg[PACKET_SIZE - sizeof(struct icmp)];
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

void ping(const char *addr) {
    int sockfd;
    struct sockaddr_in target;
    struct ping_packet packet;
    struct timeval start_time, end_time;
    socklen_t addr_len = sizeof(target);
    struct icmp *icmp_hdr;

    if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket Error");
        exit(EXIT_FAILURE);
    }

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    if (inet_pton(AF_INET, addr, &target.sin_addr) <= 0) {
        perror("Invalid Address");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < PING_COUNT; i++) {
        memset(&packet, 0, sizeof(packet));
        packet.hdr.icmp_type = ICMP_ECHO;
        packet.hdr.icmp_id = getpid();
        packet.hdr.icmp_seq = i + 1;
        strcpy(packet.msg, "Ping Test");

        packet.hdr.icmp_cksum = checksum(&packet, sizeof(packet));

        gettimeofday(&start_time, NULL);
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&target, sizeof(target)) <= 0) {
            perror("Sendto Error");
            exit(EXIT_FAILURE);
        }

        if (recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&target, &addr_len) < 0) {
            perror("Recvfrom Error");
            exit(EXIT_FAILURE);
        }
        gettimeofday(&end_time, NULL);
        
        long elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;
        
        icmp_hdr = &packet.hdr;
        if (icmp_hdr->icmp_type == ICMP_ECHOREPLY && icmp_hdr->icmp_id == getpid()) {
            printf("Reply from %s: bytes=%d time=%ld ms\n", addr, PACKET_SIZE, elapsed_time);
        } else {
            printf("Received packet that is not ECHO_REPLY\n");
        }
        
        sleep(1);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP Address or Hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ping(argv[1]);
    return EXIT_SUCCESS;
}