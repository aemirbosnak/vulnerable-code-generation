//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define MAX_ATTEMPTS 5

struct icmp_packet {
    struct icmphdr header;
    char payload[PACKET_SIZE - sizeof(struct icmphdr)];
};

int ping(const char *ip) {
    int sockfd;
    struct sockaddr_in addr;
    struct icmp_packet packet;
    struct timeval start_time, end_time;
    struct timeval timeout = {TIMEOUT, 0};
    
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);

    packet.header.type = ICMP_ECHO;
    packet.header.code = 0;
    packet.header.un.echo.sequence = 0;
    packet.header.un.echo.id = getpid();
    packet.header.checksum = 0;

    // Fill the payload with some data
    strcpy(packet.payload, "Ping!");

    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        gettimeofday(&start_time, NULL);
        ssize_t sent = sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&addr, sizeof(addr));
        if (sent <= 0) {
            perror("Send failed");
            continue;
        }

        socklen_t addr_len = sizeof(addr);
        if (recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr*)&addr, &addr_len) <= 0) {
            printf("Request timed out.\n");
        } else {
            gettimeofday(&end_time, NULL);
            double rtt = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + 
                         (end_time.tv_usec - start_time.tv_usec) / 1000.0;
            printf("Reply from %s: time=%.2f ms\n", ip, rtt);
        }
        
        sleep(1);
    }

    close(sockfd);
    return 0;
}

void signal_handler(int signum) {
    printf("\nExiting gracefully...\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP_ADDRESS>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, signal_handler);
    printf("Starting QoS monitor for %s...\n", argv[1]);

    while (1) {
        printf("Pinging %s...\n", argv[1]);
        ping(argv[1]);
        sleep(5); // Repeat every 5 seconds
    }

    return 0;
}