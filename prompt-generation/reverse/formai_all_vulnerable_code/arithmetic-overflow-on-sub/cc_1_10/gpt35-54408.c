//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define ICMP_ECHO_REQUEST 8
#define ICMP_ECHO_REPLY 0

struct icmp_packet {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint16_t id;
    uint16_t sequence;
};

uint16_t checksum(void *buffer, int size) {
    uint16_t *data = (uint16_t *) buffer;
    uint32_t sum = 0;
    while (size > 1) {
        sum += *data++;
        size -= 2;
    }
    if (size == 1) {
        sum += *(uint8_t *) data;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    return (uint16_t) ~sum;
}

double ping(int sockfd, char *ip) {
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, ip, &addr.sin_addr) != 1) {
        printf("Invalid IP address: %s\n", ip);
        exit(1);
    }

    struct icmp_packet packet = {0};
    packet.type = ICMP_ECHO_REQUEST;
    packet.code = 0;
    packet.checksum = checksum(&packet, sizeof(packet));
    packet.id = getpid();
    packet.sequence = 0;

    clock_t t = clock();
    sendto(sockfd, &packet, sizeof(packet), 0, (const struct sockaddr *) &addr, sizeof(addr));
    char buffer[256];
    int bytes = recvfrom(sockfd, buffer, 256, 0, NULL, NULL);
    t = clock() - t;

    if (bytes < sizeof(struct iphdr) + sizeof(struct icmp_packet)) {
        printf("Received malformed packet\n");
        exit(1);
    }

    struct iphdr *ip_header = (struct iphdr *) buffer;
    struct icmp_packet *icmp_reply = (struct icmp_packet *) (buffer + sizeof(struct iphdr));

    if (icmp_reply->type != ICMP_ECHO_REPLY || icmp_reply->id != getpid()) {
        printf("Received unexpected ICMP packet\n");
        exit(1);
    }

    double time_ms = ((double) t) / (CLOCKS_PER_SEC / 1000);
    printf("Received reply from %s in %.2lf ms\n", ip, time_ms);
    return time_ms;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    double total_time = 0;
    int count = 10;
    for (int i = 0; i < count; i++) {
        double time_ms = ping(sockfd, argv[1]);
        total_time += time_ms;
        sleep(1);
    }

    double avg_time = total_time / count;
    printf("Average round trip time: %.2lf ms\n", avg_time);

    close(sockfd);
    return 0;
}