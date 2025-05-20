//FormAI DATASET v1.0 Category: Network Ping Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#define PACKET_SIZE 64

struct icmp_header {
    unsigned char type;
    unsigned char code;
    unsigned short checksum;
    unsigned short id;
    unsigned short sequence;
    struct timespec timestamp;
};

// Calculate the checksum of the icmp header
unsigned short calculate_checksum(unsigned short *buffer, int length) {
    unsigned long sum = 0;
    while (length > 1) {
        sum += *buffer;
        buffer++;
        length -= 2;
    }
    if (length == 1) {
        sum += *(unsigned char *)buffer;
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return ~sum;
}

// Send an icmp echo request packet to the specified address
void send_ping(int sockfd, struct sockaddr_in *addr, int seq) {
    struct icmp_header icmp;
    memset(&icmp, 0, sizeof(struct icmp_header));
    icmp.type = 8; // echo request
    icmp.code = 0;
    icmp.checksum = calculate_checksum((unsigned short *)&icmp, sizeof(struct icmp_header));
    icmp.id = getpid();
    icmp.sequence = seq;
    clock_gettime(CLOCK_MONOTONIC, &icmp.timestamp);
    ssize_t ret = sendto(sockfd, &icmp, sizeof(struct icmp_header), 0, (struct sockaddr *)addr, sizeof(struct sockaddr_in));
    if (ret < 0) {
        perror("sendto");
    }
}

// Receive an icmp echo reply packet from the specified address
int receive_ping(int sockfd, struct sockaddr_in *addr, int seq, struct timespec *timestamp) {
    char buffer[PACKET_SIZE];
    struct sockaddr_in ping_addr;
    socklen_t addr_len = sizeof(struct sockaddr_in);
    ssize_t ret = recvfrom(sockfd, buffer, PACKET_SIZE, 0, (struct sockaddr *)&ping_addr, &addr_len);
    if (ret < 0) {
        perror("recvfrom");
    }
    struct icmp_header *icmp = (struct icmp_header *)buffer;
    if (icmp->type == 0 && icmp->id == getpid() && icmp->sequence == seq) {
        *timestamp = icmp->timestamp;
        return 1;
    }
    return 0;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        return 0;
    }

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        return 0;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    int ret = inet_pton(AF_INET, argv[1], &addr.sin_addr);
    if (ret <= 0) {
        perror("inet_pton");
        return 0;
    }

    int i;
    int seq = 1;
    int received = 0;
    struct timespec start_time, end_time, elapsed_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    for (i = 0; i < 4; i++) {
        send_ping(sockfd, &addr, seq);
        seq++;
        if (receive_ping(sockfd, &addr, seq-1, &end_time)) {
            received++;
            elapsed_time.tv_sec = end_time.tv_sec - start_time.tv_sec;
            elapsed_time.tv_nsec = (end_time.tv_nsec - start_time.tv_nsec) % 1000000000;
            printf("%d bytes from %s: icmp_seq=%d time=%.2f ms\n",
                PACKET_SIZE, argv[1], i+1, elapsed_time.tv_sec*1000.0 + elapsed_time.tv_nsec/1000000.0);
        }
        else {
            printf("Request timed out.\n");
        }
        usleep(500000);
    }
    close(sockfd);

    if (received > 0) {
        printf("%d packets transmitted, %d received, %.0f%% packet loss\n",
            seq-1, received, (seq-1-received)*100.0/(seq-1));
    }
    else {
        printf("No packets received.\n");
    }

    return 0;
}