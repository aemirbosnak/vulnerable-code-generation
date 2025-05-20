//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: light-weight
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
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 4
#define TIMEOUT 1
#define ICMP_HEADER_LENGTH 8

struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - ICMP_HEADER_LENGTH];
};

// Global variables
volatile sig_atomic_t stop;

void int_handler(int dummy) {
    stop = 1;
}

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short answer = 0;

    for (sum = 0; len > 1; len -= 2) {
        sum += *buf++;
    }
    if (len == 1) {
        sum += *(unsigned char *)buf;
    }
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    answer = ~sum;
    return answer;
}

void send_ping(int sockfd, struct sockaddr_in *addr, int ping_count) {
    struct ping_packet packet;
    memset(&packet, 0, sizeof(packet));
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();
    strcpy(packet.msg, "Ping message!");

    for (int i = 0; i < ping_count; i++) {
        packet.hdr.un.echo.sequence = i + 1;
        packet.hdr.checksum = checksum(&packet, sizeof(packet));

        clock_t start_time = clock();
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *) addr, sizeof(*addr)) <= 0) {
            perror("Send failed");
            continue;
        }

        char buffer[PACKET_SIZE];
        struct sockaddr_in response_addr;
        socklen_t addr_len = sizeof(response_addr);
        memset(buffer, 0, sizeof(buffer));
        
        fd_set read_fds;
        struct timeval tv;
        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;

        FD_ZERO(&read_fds);
        FD_SET(sockfd, &read_fds);

        int activity = select(sockfd + 1, &read_fds, NULL, NULL, &tv);
        if (activity > 0) {
            int bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *) &response_addr, &addr_len);
            if (bytes_received > 0) {
                struct iphdr *ip_header = (struct iphdr *) buffer;
                struct icmphdr *icmp_header = (struct icmphdr *) (buffer + (ip_header->ihl << 2));

                if (icmp_header->type == ICMP_ECHOREPLY && icmp_header->un.echo.id == getpid() && icmp_header->un.echo.sequence == packet.hdr.un.echo.sequence) {
                    double time_taken = (double)(clock() - start_time) / CLOCKS_PER_SEC * 1000;
                    printf("Ping %d: Received reply from %s: seq=%d time=%.3f ms\n", i + 1, inet_ntoa(response_addr.sin_addr), icmp_header->un.echo.sequence, time_taken);
                } else {
                    printf("Ping %d: Received wrong ICMP type or wrong identifier.\n", i + 1);
                }
            } else {
                printf("Ping %d: Failed to receive reply.\n", i + 1);
            }
        } else if (activity == 0) {
            printf("Ping %d: Request timed out.\n", i + 1);
        } else {
            perror("Select failed");
        }

        if (stop) {
            break;
        }

        sleep(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = 0;
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
        perror("Invalid IP Address");
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, int_handler);

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    printf("Pinging %s with %d packets...\n", argv[1], PING_COUNT);
    send_ping(sockfd, &addr, PING_COUNT);

    close(sockfd);
    return 0;
}