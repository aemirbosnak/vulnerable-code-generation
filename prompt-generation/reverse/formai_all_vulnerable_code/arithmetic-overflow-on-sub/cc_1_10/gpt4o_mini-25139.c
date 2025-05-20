//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define PING_COUNT 4

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

int sockfd, ping_count = 0;

void handle_alarm(int sig) {
    // Handle alarm signal for timeout
    printf("Request timed out.\n");
    exit(1);
}

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        sum += *(unsigned char *)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (unsigned short)(~sum);
}

void ping(char *ip_address) {
    struct sockaddr_in addr_ping;
    struct ping_packet packet;
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    struct timeval start, end;
    double time_taken;

    addr_ping.sin_family = AF_INET;
    addr_ping.sin_port = 0;
    addr_ping.sin_addr.s_addr = inet_addr(ip_address);

    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    memset(packet.msg, 0, sizeof(packet.msg));
    strcpy(packet.msg, "Ping Test");
    packet.hdr.un.echo.sequence = ping_count++;
    packet.hdr.checksum = checksum(&packet, sizeof(packet));

    if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr_ping, sizeof(addr_ping)) <= 0) {
        perror("Send failed");
        return;
    }

    gettimeofday(&start, NULL);

    if (recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&r_addr, &addr_len) <= 0) {
        perror("Recv failed");
        return;
    }

    gettimeofday(&end, NULL);
    time_taken = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;

    printf("Reply from %s: bytes=%d time=%.2f ms\n", ip_address, PACKET_SIZE, time_taken);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    signal(SIGALRM, handle_alarm);
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &(struct timeval){TIMEOUT, 0}, sizeof(struct timeval));

    for (int i = 0; i < PING_COUNT; i++) {
        ping(argv[1]);
        sleep(1);
    }

    close(sockfd);
    return 0;
}