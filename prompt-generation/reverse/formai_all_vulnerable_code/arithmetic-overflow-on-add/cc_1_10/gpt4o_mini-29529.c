//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <signal.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>

#define PING_SLEEP_RATE 1000000 // Sleep for 1 second (in microseconds)
#define PACKET_SIZE 64
#define MAX_PINGS 5

int ping_count = 0;
int sent_count = 0, received_count = 0;

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
    struct sockaddr_in addr_ping;
    struct icmp icp;
    struct timeval start_time, end_time;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket Error");
        exit(1);
    }

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(ip_address);

    while (ping_count < MAX_PINGS) {
        memset(&icp, 0, sizeof(icp));
        icp.icmp_type = ICMP_ECHO;
        icp.icmp_id = getpid();
        icp.icmp_seq = ping_count;
        icp.icmp_cksum = checksum(&icp, sizeof(icp));

        gettimeofday(&start_time, NULL);
        sent_count++;

        if (sendto(sockfd, &icp, sizeof(icp), 0, (struct sockaddr*)&addr_ping, sizeof(addr_ping)) <= 0) {
            perror("Send Error");
        }

        char buffer[PACKET_SIZE];
        socklen_t addr_len = sizeof(addr_ping);
        recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr_ping, &addr_len);
        gettimeofday(&end_time, NULL);

        struct iphdr *ip_header = (struct iphdr *)buffer;
        if (ip_header->ihl >= 5) {
            received_count++;
            long rtt = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;
            printf("Ping %d: Reply from %s: time=%ld ms\n", ping_count + 1, ip_address, rtt);
        }

        ping_count++;
        usleep(PING_SLEEP_RATE);
    }

    printf("\n--- %s ping statistics ---\n", ip_address);
    printf("%d packets transmitted, %d received, %.2f%% packet loss\n", sent_count, received_count, 
            ((sent_count - received_count) / (float)sent_count) * 100);
    
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ip_address>\n", argv[0]);
        exit(1);
    }

    const char *ip_address = argv[1];
    ping(ip_address);
    return 0;
}