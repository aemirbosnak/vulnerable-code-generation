//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <signal.h>
#include <errno.h>

#define PACKET_SIZE     64
#define PING_COUNT      4
#define TIMEOUT         1

// Struct to hold ping statistics
struct ping_stats {
    int sent;
    int received;
    double min_time;
    double max_time;
    double total_time;
};

// Function to calculate checksum for ICMP packets
unsigned short calculate_checksum(void *b, int len) {
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

// Function to create a raw socket for ICMP
int create_socket() {
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

// Function to send ping requests
void send_ping(int sockfd, const char *ip_addr, struct ping_stats *stats) {
    struct sockaddr_in addr;
    struct icmp *icmp_pkt;
    char packet[PACKET_SIZE];
    int addr_len = sizeof(addr);
    struct timeval start_time, end_time;
    
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_addr);
    
    for (int i = 0; i < PING_COUNT; i++) {
        memset(packet, 0, sizeof(packet));
        icmp_pkt = (struct icmp *)packet;
        icmp_pkt->icmp_type = ICMP_ECHO;
        icmp_pkt->icmp_code = 0;
        icmp_pkt->icmp_id = getpid();
        icmp_pkt->icmp_seq = i + 1;
        icmp_pkt->icmp_cksum = calculate_checksum(packet, sizeof(packet));
        
        gettimeofday(&start_time, NULL);
        stats->sent++;

        if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&addr, addr_len) <= 0) {
            perror("Sendto failed");
            continue;
        }

        char recv_buffer[PACKET_SIZE];
        if (recv(sockfd, recv_buffer, sizeof(recv_buffer), 0) > 0) {
            gettimeofday(&end_time, NULL);
            stats->received++;
            double time_taken = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + 
                                (end_time.tv_usec - start_time.tv_usec) / 1000.0;
            printf("Reply from %s: bytes=%d time=%.2f ms\n", ip_addr, PACKET_SIZE, time_taken);
            
            if (stats->min_time == 0 || time_taken < stats->min_time) 
                stats->min_time = time_taken;
            if (time_taken > stats->max_time) 
                stats->max_time = time_taken;
            stats->total_time += time_taken;
        } else {
            perror("Recv failed");
        }

        sleep(1); // Wait for 1 second before sending the next ping
    }
}

// Function to display ping statistics
void display_stats(struct ping_stats *stats) {
    printf("\n--- Ping statistics ---\n");
    printf("%d packets transmitted, %d received, %d%% packet loss\n",
           stats->sent, stats->received, 
           (stats->sent - stats->received) * 100 / stats->sent);
    if (stats->received > 0) {
        printf("round-trip min/avg/max = %.2f/%.2f/%.2f ms\n",
               stats->min_time, 
               stats->total_time / stats->received, 
               stats->max_time);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct ping_stats stats;
    memset(&stats, 0, sizeof(stats));

    int sockfd = create_socket();
    send_ping(sockfd, argv[1], &stats);
    display_stats(&stats);
    
    close(sockfd);
    return 0;
}