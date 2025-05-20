//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <signal.h>

#define PACKET_SIZE 64
#define MAX_ATTEMPTS 5
#define TIMEOUT 1

int sockfd;
struct sockaddr_in addr_con;
struct icmp *icmp_hdr;
char packet[PACKET_SIZE];

void signal_handler(int signum) {
    if (signum == SIGINT) {
        printf("\nTerminating program.\n");
        close(sockfd);
        exit(0);
    }
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

void send_ping(const char *ip_addr) {
    struct timeval start_time, end_time;
    struct packet {
        struct icmp hdr;
        char msg[PACKET_SIZE - sizeof(struct icmp)];
    } pckt;

    pckt.hdr.icmp_type = 8; // Echo request
    pckt.hdr.icmp_code = 0;
    pckt.hdr.icmp_id = getpid();
    pckt.hdr.icmp_seq = rand() % 65535;
    gettimeofday(&start_time, NULL);
    pckt.hdr.icmp_cksum = checksum(&pckt, sizeof(pckt));

    sendto(sockfd, &pckt, sizeof(pckt), 0, (struct sockaddr*)&addr_con, sizeof(addr_con));

    socklen_t addr_len = sizeof(addr_con);
    if (recvfrom(sockfd, packet, sizeof(packet), 0, (struct sockaddr*)&addr_con, &addr_len) > 0) {
        gettimeofday(&end_time, NULL);
        double time_taken = (end_time.tv_sec - start_time.tv_sec) * 1000.0; // Convert to ms
        time_taken += (end_time.tv_usec - start_time.tv_usec) / 1000.0; // Add microseconds to milliseconds

        struct iphdr *ip_hdr = (struct iphdr *)packet;
        icmp_hdr = (struct icmp *)(packet + (ip_hdr->ihl << 2)); // Go to the ICMP header
        printf("Response from %s: seq=%d time=%.2f ms\n", ip_addr, icmp_hdr->icmp_seq, time_taken);
    } else {
        printf("Request timed out.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, signal_handler); // Handle SIGINT to cleanup

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    addr_con.sin_family = AF_INET;
    addr_con.sin_port = htons(0);
    inet_pton(AF_INET, argv[1], &addr_con.sin_addr);

    printf("Pinging %s:\n", argv[1]);

    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        send_ping(argv[1]);
        sleep(TIMEOUT);
    }

    close(sockfd);
    return 0;
}