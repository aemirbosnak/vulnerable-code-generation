//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/time.h>

struct ping_packet {
    unsigned char type; // ping request or reply
    unsigned char code;
    unsigned short checksum;
    unsigned short id;
    unsigned short seq;
    struct timeval timestamp;
};

unsigned short checksum(void *b, int len) {
    unsigned short *buffer = b;
    unsigned int sum = 0;
    for (sum = 0; len > 1; len -= 2) {
        sum += *buffer++;
    }
    if (len == 1) {
        sum += *(unsigned char *)buffer;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return ~sum;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s IP Address\n", argv[0]);
        exit(1);
    }
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        printf("Failed to create socket\n");
        exit(1);
    }
    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &target_addr.sin_addr);
    unsigned short seq = 0;
    char send_buf[1024];
    memset(send_buf, 0, sizeof(send_buf));
    struct ping_packet *packet = (struct ping_packet *)send_buf;
    packet->type = 8; // type of echo request
    packet->code = 0;
    packet->id = getpid();
    memset(&packet->timestamp, 0, sizeof(packet->timestamp));
    printf("Starting Ping Test for %s:\n\n", argv[1]);
    while (1) {
        ++seq;
        packet->seq = seq;
        gettimeofday(&packet->timestamp, NULL);
        packet->checksum = 0;
        packet->checksum = checksum(packet, sizeof(struct ping_packet));
        if (sendto(sockfd, send_buf, sizeof(struct ping_packet), 0, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0) {
            printf("Failed to send ping request\n");
            exit(1);
        }
        struct timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 0;
        fd_set fdset;
        FD_ZERO(&fdset);
        FD_SET(sockfd, &fdset);
        if (select(sockfd+1, &fdset, NULL, NULL, &tv) == 1) {
            unsigned char recv_buf[1024];
            struct sockaddr_in recv_addr;
            socklen_t len = sizeof(recv_addr);
            if (recvfrom(sockfd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *)&recv_addr, &len) >= sizeof(struct ping_packet)) {
                struct ping_packet *recv_packet = (struct ping_packet *)recv_buf;
                if (recv_packet->type == 0 || recv_packet->type == 8) {
                    printf("Reply from %s, time=%.2lfms\n", argv[1], (double)(recv_packet->timestamp.tv_sec-packet->timestamp.tv_sec)*1000 + (double)(recv_packet->timestamp.tv_usec-packet->timestamp.tv_usec)/1000);
                }
            }
        } else {
            printf("Request timed out\n");
        }
        printf("\n");
        sleep(1);
    }
    return 0;
}