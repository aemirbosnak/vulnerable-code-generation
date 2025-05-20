//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <netdb.h>

#define PING_PKT_S 64  // size of packet
#define PING_INTERVAL 1 // interval between pings
#define MAX_WAIT_TIME 1 // max wait time for reply
#define TTL_VALUE 64 // Time to Live

void initialize_ping_socket(int *sockfd, struct sockaddr_in *addr, const char *ip) {
    // Create a raw socket
    if ((*sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(addr, 0, sizeof(*addr));
    addr->sin_family = AF_INET;
    addr->sin_addr.s_addr = inet_addr(ip);
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

void send_ping(int sockfd, struct sockaddr_in *addr) {
    char packet[PING_PKT_S];
    struct icmp {
        unsigned char icmp_type;
        unsigned char icmp_code;
        unsigned short icmp_cksum;
        unsigned short icmp_id;
        unsigned short icmp_seq;
        unsigned char payload[PING_PKT_S - 8];
    } *icmp_hdr;

    icmp_hdr = (struct icmp *) packet;
    memset(packet, 0, sizeof(packet));
    
    icmp_hdr->icmp_type = 8; // ICMP Echo request
    icmp_hdr->icmp_cksum = 0; // initially, checksum is zero
    icmp_hdr->icmp_id = getpid();
    icmp_hdr->icmp_seq = 1;

    // Fill the payload with a peaceful message
    snprintf((char *)icmp_hdr->payload, PING_PKT_S - 8, "Peaceful Ping Message");

    // Calculate the checksum
    icmp_hdr->icmp_cksum = checksum(packet, sizeof(packet));

    // Send the packet
    if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)addr, sizeof(*addr)) <= -1) {
        perror("Packet send failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Ping sent to %s\n", inet_ntoa(addr->sin_addr));
}

void receive_ping(int sockfd) {
    char buffer[1024];
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    struct timeval tv_start, tv_end;

    gettimeofday(&tv_start, NULL);
    if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&r_addr, &addr_len) < 0) {
        perror("Ping response failed");
    } else {
        gettimeofday(&tv_end, NULL);
        long rtt = (tv_end.tv_sec - tv_start.tv_sec) * 1000 + (tv_end.tv_usec - tv_start.tv_usec) / 1000;
        printf("Reply from %s: time=%ld ms\n", inet_ntoa(r_addr.sin_addr), rtt);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP-address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd;
    struct sockaddr_in addr;

    initialize_ping_socket(&sockfd, &addr, argv[1]);

    for (int i = 0; i < 4; i++) {
        send_ping(sockfd, &addr);
        sleep(PING_INTERVAL);
        receive_ping(sockfd);
    }

    close(sockfd);
    printf("Pinging completed peacefully.\n");

    return EXIT_SUCCESS;
}