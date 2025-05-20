//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>

#define PACKET_SIZE 64
#define PING_COUNT 10

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

void ping(const char *ip_addr) {
    int sockfd;
    struct sockaddr_in addr;
    struct icmp packet;
    struct timeval start, end;
    int sent = 0, received = 0;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);

    for (int i = 0; i < PING_COUNT; i++) {
        memset(&packet, 0, sizeof(packet));
        packet.icmp_type = ICMP_ECHO;
        packet.icmp_code = 0;
        packet.icmp_id = getpid();
        packet.icmp_seq = i;
        packet.icmp_cksum = checksum(&packet, sizeof(packet));

        gettimeofday(&start, NULL);

        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            perror("Send failed");
            continue;
        }
        sent++;

        char buffer[PACKET_SIZE];
        socklen_t addr_len = sizeof(addr);
        
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, &addr_len) > 0) {
            gettimeofday(&end, NULL);
            struct timeval rtt;
            timersub(&end, &start, &rtt);
            printf("Reply from %s: seq=%d time=%ld.%06lds\n", ip_addr, i + 1, rtt.tv_sec, rtt.tv_usec);
            received++;
        } else {
            printf("Request timed out for seq=%d\n", i + 1);
        }

        sleep(1); // Wait a second between pings
    }

    close(sockfd);
    printf("Sent: %d, Received: %d, Loss: %.2f%%\n", sent, received, ((float)(sent - received) / sent) * 100);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Pinging %s with %d packets:\n", argv[1], PING_COUNT);
    ping(argv[1]);

    return EXIT_SUCCESS;
}