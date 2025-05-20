//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

#define PING_PKT_S 64
#define PING_SLEEP_RATE 1
#define PING_COUNT 4

struct ping_pkt {
    struct icmphdr hdr;
    char msg[PING_PKT_S - sizeof(struct icmphdr)];
};

int ping_count = 0;

void signal_handler(int signum) {
    printf("\nPing process interrupted. Exiting...\n");
    exit(0);
}

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

void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr_con;
    struct ping_pkt pkt;
    struct sockaddr_in r_addr;
    int addr_len = sizeof(r_addr);
    int msg_count = 0;
    int start_time, end_time;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    addr_con.sin_family = AF_INET;
    addr_con.sin_port = 0;
    addr_con.sin_addr.s_addr = inet_addr(ip_address);

    signal(SIGINT, signal_handler);

    printf("Pinging %s with %d bytes of data:\n", ip_address, PING_PKT_S);

    for (msg_count = 0; msg_count < PING_COUNT; msg_count++) {
        memset(&pkt, 0, sizeof(pkt));
        pkt.hdr.type = ICMP_ECHO;
        pkt.hdr.un.echo.id = getpid();
        pkt.hdr.un.echo.sequence = msg_count + 1;
        pkt.hdr.checksum = checksum(&pkt, sizeof(pkt));

        start_time = time(NULL);
        if (sendto(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr*)&addr_con, sizeof(addr_con)) <= 0) {
            perror("Failed to send packet");
        }

        if (recvfrom(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr*)&r_addr, &addr_len) <= 0) {
            perror("Packet receive failed");
        } else {
            end_time = time(NULL);
            printf("%d bytes from %s: icmp_seq=%d time=%lums\n", PING_PKT_S, ip_address, msg_count + 1, (end_time - start_time) * 1000);
        }

        sleep(PING_SLEEP_RATE);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP_ADDRESS>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ping(argv[1]);

    return EXIT_SUCCESS;
}