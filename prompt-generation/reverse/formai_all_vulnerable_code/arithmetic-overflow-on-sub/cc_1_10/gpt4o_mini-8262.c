//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>

#define MAX_HOPS 30
#define TIMEOUT 1

// Function prototypes
void monitor_qos(int sockfd, struct sockaddr_in *addr, int ttl, int hop_count);
double calculate_rtt(struct timeval start, struct timeval end);
void print_summary(double *rtts, int hop_count);

int main() {
    int sockfd;
    struct sockaddr_in addr;
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("8.8.8.8");  // Target address (Google DNS)

    // Start the recursive monitoring of QoS
    printf("Starting QoS Monitoring...\n");
    monitor_qos(sockfd, &addr, 1, 0);

    close(sockfd);
    return 0;
}

void monitor_qos(int sockfd, struct sockaddr_in *addr, int ttl, int hop_count) {
    if (ttl > MAX_HOPS) {
        // Print summary when all hops are done
        return;
    }

    struct timeval start, end;
    char buffer[4096];
    struct icmphdr *icmp_hdr = (struct icmphdr *)(buffer + sizeof(struct ip));

    // Set socket option for TTL
    setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(ttl));

    // Initialize the ICMP packet
    memset(buffer, 0, sizeof(buffer));
    icmp_hdr->type = ICMP_ECHO;
    icmp_hdr->code = 0;
    icmp_hdr->un.echo.id = getpid();
    icmp_hdr->un.echo.sequence = hop_count;
    icmp_hdr->checksum = 0;
    icmp_hdr->checksum = (unsigned short)~(icmp_hdr->type + icmp_hdr->code);

    // Record start time
    gettimeofday(&start, NULL);

    // Send ICMP Echo Request
    sendto(sockfd, buffer, sizeof(struct icmphdr), 0, (struct sockaddr *)addr, sizeof(*addr));

    // Set timeout for receiving the ICMP Reply
    fd_set readfds;
    struct timeval timeout = { TIMEOUT, 0 };
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    int res = select(sockfd + 1, &readfds, NULL, NULL, &timeout);
    if (res > 0) {
        // Receive reply
        socklen_t len = sizeof(*addr);
        recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)addr, &len);

        // Record end time
        gettimeofday(&end, NULL);
        double rtt = calculate_rtt(start, end);
        printf("Hop %2d: RTT = %.2f ms\n", hop_count, rtt);
    } else {
        printf("Hop %2d: Request timed out.\n", hop_count);
    }

    // Recursive call to next hop
    monitor_qos(sockfd, addr, ttl + 1, hop_count + 1);
}

double calculate_rtt(struct timeval start, struct timeval end) {
    return ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
}