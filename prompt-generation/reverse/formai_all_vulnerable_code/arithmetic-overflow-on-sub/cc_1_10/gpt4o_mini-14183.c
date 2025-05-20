//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <signal.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_INTERVAL 1
#define NUM_PINGS 5

int pings_sent = 0;
int pings_received = 0;
double total_time = 0.0;

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

void send_ping(int sockfd, struct sockaddr_in *addr, int seq) {
    struct icmp packet;
    packet.icmp_type = ICMP_ECHO;
    packet.icmp_code = 0;
    packet.icmp_id = getpid();
    packet.icmp_seq = seq;
    packet.icmp_cksum = checksum(&packet, sizeof(packet));
    
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)addr, sizeof(*addr));
    pings_sent++;

    char buf[1024];
    socklen_t addr_len = sizeof(*addr);
    if (recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) addr, &addr_len) > 0) {
        gettimeofday(&end, NULL);
        double time_taken = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
        printf("Reply from %s: bytes=%d time=%.2f ms\n", inet_ntoa(addr->sin_addr), PACKET_SIZE, time_taken);
        pings_received++;
        total_time += time_taken;
    }
    else {
        printf("Request timed out for seq = %d\n", seq);
    }
}

void print_summary() {
    printf("\n--- Ping Statistics ---\n");
    printf("Pings sent: %d\n", pings_sent);
    printf("Pings received: %d\n", pings_received);
    printf("Packet loss: %.2f%%\n", ((pings_sent - pings_received) / (float)pings_sent) * 100);
    if (pings_received > 0) {
        printf("Average latency: %.2f ms\n", total_time / pings_received);
    } else {
        printf("Average latency: N/A\n");
    }
}

void signal_handler(int signum) {
    print_summary();
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        return 1;
    }
    
    signal(SIGINT, signal_handler);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    inet_pton(AF_INET, argv[1], &addr.sin_addr);
    
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }
    
    while (pings_sent < NUM_PINGS) {
        send_ping(sockfd, &addr, pings_sent + 1);
        sleep(PING_INTERVAL);
    }
    
    print_summary();
    close(sockfd);
    return 0;
}