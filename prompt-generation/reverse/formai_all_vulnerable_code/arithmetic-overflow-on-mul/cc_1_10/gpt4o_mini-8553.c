//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>

#define MAX_PING_COUNT 4
#define PING_SLEEP_RATE 1000 // In milliseconds

struct PingStats {
    int sent;
    int received;
    int lost;
};

void print_report(struct PingStats *stats) {
    printf("Quest for knowledge completed!\n");
    printf("Sendeth: %d, Received: %d, Lost: %d\n", stats->sent, stats->received, stats->lost);
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

void ping(const char *ip_address) {
    int sockfd;
    struct sockaddr_in addr_ping;
    struct icmp pkt;
    struct PingStats stats = {0};
    struct timeval start_time, end_time;
    double rtt;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("King's socket creation failed");
        exit(EXIT_FAILURE);
    }

    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(ip_address);

    for (int i = 0; i < MAX_PING_COUNT; i++) {
        memset(&pkt, 0, sizeof(pkt));
        pkt.icmp_type = ICMP_ECHO;
        pkt.icmp_seq = i + 1;
        pkt.icmp_id = getpid();
        pkt.icmp_cksum = checksum(&pkt, sizeof(pkt));

        gettimeofday(&start_time, NULL);

        if (sendto(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr *)&addr_ping, sizeof(addr_ping)) <= 0) {
            perror("Failed the sending of a message to the enemy kingdom");
            continue;
        }

        stats.sent++;
        
        char buf[1024];
        socklen_t addr_len = sizeof(addr_ping);
        if (recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&addr_ping, &addr_len) > 0) {
            gettimeofday(&end_time, NULL);

            int time_taken = (end_time.tv_sec - start_time.tv_sec) * 1000 + 
                             (end_time.tv_usec - start_time.tv_usec) / 1000;
            rtt = time_taken;

            printf("Quest to %s successful! Time: %.2f ms\n", ip_address, rtt);
            stats.received++;
        } 
        else {
            printf("Quest to %s failed!\n", ip_address);
            stats.lost++;
        }

        usleep(PING_SLEEP_RATE * 1000);
    }

    close(sockfd);
    print_report(&stats);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./ping_quest <destination ip>\n");
        exit(EXIT_FAILURE);
    }

    const char *ip_address = argv[1];
    ping(ip_address);

    return 0;
}