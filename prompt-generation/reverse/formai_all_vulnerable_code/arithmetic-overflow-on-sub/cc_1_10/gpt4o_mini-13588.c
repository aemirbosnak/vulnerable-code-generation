//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <time.h>
#include <signal.h>
#include <errno.h>

#define PACKET_SIZE 64
#define PING_SLEEP_TIMEOUT 1
#define MAX_WAIT_TIME 1
#define MAX_LOSS 100

static volatile int keep_running = 1;

void handle_sigint(int sig) {
    keep_running = 0;
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

void send_ping(int sockfd, struct sockaddr_in *addr) {
    struct icmp pkt;
    memset(&pkt, 0, sizeof(pkt));
    
    pkt.icmp_type = ICMP_ECHO;
    pkt.icmp_code = 0;
    pkt.icmp_id = htons(getpid());
    pkt.icmp_seq = htons(1);
    pkt.icmp_cksum = checksum(&pkt, sizeof(pkt));
    
    sendto(sockfd, &pkt, sizeof(pkt), 0, (struct sockaddr *)addr, sizeof(*addr));
}

void receive_ping(int sockfd, struct sockaddr_in *addr) {
    char buffer[PACKET_SIZE];
    socklen_t addr_len = sizeof(*addr);
    clock_t start_time = clock();
    
    if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)addr, &addr_len) < 0) {
        printf("Request timed out.\n");
        return;
    }

    clock_t end_time = clock();
    double rtt = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000.0;
    printf("Received reply from %s: RTT=%.2f ms\n", inet_ntoa(addr->sin_addr), rtt);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd;
    struct sockaddr_in addr;
    struct sigaction sa;

    sa.sa_handler = handle_sigint;
    sigaction(SIGINT, &sa, NULL);

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Pinging %s with 64 bytes of data:\n", argv[1]);

    while (keep_running) {
        send_ping(sockfd, &addr);
        receive_ping(sockfd, &addr);
        sleep(PING_SLEEP_TIMEOUT);
    }

    close(sockfd);
    printf("\nExiting...\n");
    return 0;
}