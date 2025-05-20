//FormAI DATASET v1.0 Category: Network Ping Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>

#define PACKET_SIZE 64
#define REQ_TYPE 8
#define REQ_CODE 0
#define REQ_ID 0
#define REQ_SEQ_NUM 0
#define MAXTRIES 3
#define PORTNUM 0

typedef struct {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
} icmp_packet;

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

int sendPacket(int icmp_sock, struct sockaddr_in *ping_addr, int seq_num) {
    icmp_packet pkt;

    pkt.hdr.type = REQ_TYPE;
    pkt.hdr.code = REQ_CODE;
    pkt.hdr.un.echo.id = REQ_ID;
    pkt.hdr.un.echo.sequence = seq_num;
    memset(pkt.msg, 'Q', sizeof(pkt.msg));

    pkt.hdr.checksum = 0;
    pkt.hdr.checksum = checksum(&pkt, sizeof(pkt));

    if (sendto(icmp_sock, &pkt, sizeof(pkt), 0, (struct sockaddr *)ping_addr, sizeof(*ping_addr)) <= 0) {
        perror("Error sending packet");
        return -1;
    }

    return 0;
}

int receivePacket(int icmp_sock, struct sockaddr_in *ping_addr, int seq_num) {
    struct timeval timeout;
    fd_set readfds;

    icmp_packet pkt;
    int ping_addr_len = sizeof(struct sockaddr_in);

    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    FD_ZERO(&readfds);
    FD_SET(icmp_sock, &readfds);

    int rv = select(icmp_sock+1, &readfds, NULL, NULL, &timeout);

    if (rv < 0) {
        perror("Error in select()");
        return -1;
    }

    if (rv == 0) {
        return -2;
    }

    if (recvfrom(icmp_sock, &pkt, sizeof(pkt), 0, (struct sockaddr *)ping_addr, (socklen_t *)&ping_addr_len) <= 0) {
        perror("Error receiving packet");
        return -1;
    }

    if (pkt.hdr.type == 0 && pkt.hdr.code == 0 && pkt.hdr.un.echo.id == REQ_ID && pkt.hdr.un.echo.sequence == seq_num) {
        return 0;
    }

    return -2;
}

int ping(char *host) {
    int icmp_sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (icmp_sock < 0) {
        perror("Error creating socket");
        return -1;
    }

    struct sockaddr_in ping_addr;
    ping_addr.sin_family = AF_INET;

    if (inet_pton(AF_INET, host, &ping_addr.sin_addr) == -1) {
        perror("Error converting IP");
        return -1;
    }

    printf("Pinging host %s...\n", host);

    int seq_num, packets_rcv = 0, packets_lost = 0;
    for (seq_num = 1; seq_num <= MAXTRIES; seq_num++) {
        if (sendPacket(icmp_sock, &ping_addr, seq_num) == -1) {
            packets_lost++;
            printf("Packet %d lost\n", seq_num);
            continue;
        }

        if (receivePacket(icmp_sock, &ping_addr, seq_num) == 0) {
            packets_rcv++;
            printf("Packet %d received\n", seq_num);
        } else {
            packets_lost++;
            printf("Packet %d lost\n", seq_num);
        }

        sleep(1);
    }

    printf("\nSummary:\n");
    printf("Packets sent: %d\n", MAXTRIES);
    printf("Packets received: %d\n", packets_rcv);
    printf("Packets lost: %d\n", packets_lost);

    close(icmp_sock);
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: ./ping hostname\n");
        return -1;
    }

    return ping(argv[1]);
}