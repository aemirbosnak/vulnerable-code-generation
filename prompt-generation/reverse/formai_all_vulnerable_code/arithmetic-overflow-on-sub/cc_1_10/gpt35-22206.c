//FormAI DATASET v1.0 Category: Network Ping Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PING_TIMEOUT 1000
#define BUFFER_SIZE 1024
#define MAX_HOP_COUNT 64

typedef struct {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint32_t identifier;
    uint32_t sequence_number;
} icmp_header_t;

unsigned short calculate_checksum(void *buffer, unsigned int bytes) {
    unsigned short *buf = (unsigned short *) buffer;
    unsigned long sum = 0;
    while (bytes > 1) {
        sum += *buf++;
        bytes -= 2;
    }
    if (bytes == 1) {
        sum += *(unsigned char *) buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (unsigned short) (~sum);
}

void ping(int sockfd, struct sockaddr_in *remote_addr) {
    char buffer[BUFFER_SIZE] = {0};
    icmp_header_t *icmp_header = (icmp_header_t *) buffer;
    icmp_header->type = 8;
    icmp_header->code = 0;
    icmp_header->identifier = getpid();
    icmp_header->checksum = 0;
    icmp_header->sequence_number = 1;
    icmp_header->checksum = calculate_checksum(icmp_header, sizeof(icmp_header_t));
    struct timeval tv_start, tv_end;
    gettimeofday(&tv_start, NULL);
    sendto(sockfd, buffer, sizeof(icmp_header_t), 0, (struct sockaddr *) remote_addr, sizeof(struct sockaddr_in));
    unsigned char recv_buffer[BUFFER_SIZE] = {0};
    ssize_t recv_bytes = 0;
    int hop_number = 1;
    while (hop_number <= MAX_HOP_COUNT) {
        memset(&recv_buffer, 0, BUFFER_SIZE);
        struct sockaddr_in recv_addr;
        socklen_t recv_addr_len = sizeof(recv_addr);
        alarm(2);
        recv_bytes = recvfrom(sockfd, recv_buffer, BUFFER_SIZE, 0, (struct sockaddr *) &recv_addr, &recv_addr_len);
        if (recv_bytes > 0) {
            printf("%d. Hop: %s\n", hop_number, inet_ntoa(recv_addr.sin_addr));
        } else {
            printf("%d. Hop: Timeout!\n", hop_number);
        }
        hop_number++;
    }
    gettimeofday(&tv_end, NULL);
    double seconds_elapsed = (double) (tv_end.tv_usec - tv_start.tv_usec) / 1000000 + (double) (tv_end.tv_sec - tv_start.tv_sec);
    printf("Time elapsed: %f seconds\n", seconds_elapsed);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *hostname = argv[1];
    struct sockaddr_in remote_addr;
    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(80);
    if (inet_aton(hostname, &remote_addr.sin_addr) == 0) {
        printf("Hostname '%s' is invalid.\n", hostname);
        exit(EXIT_FAILURE);
    }
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    ping(sockfd, &remote_addr);
    close(sockfd);
    return EXIT_SUCCESS;
}