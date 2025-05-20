//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <time.h>
#include <signal.h>

#define PACKET_SIZE 64
#define MAX_ATTEMPTS 4
#define TIMEOUT 1 // Timeout in seconds for each ping

// Structure to hold the packet information
struct ping_packet {
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

// Function to calculate the checksum of the packet
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

// Function to send ICMP echo requests
void send_ping(int sockfd, struct sockaddr_in *addr) {
    struct ping_packet packet;
    struct sockaddr_in r_addr;
    socklen_t r_addr_len = sizeof(r_addr);
    struct timespec start, end;
    int timeout = 1;
    
    for (int tries = 0; tries < MAX_ATTEMPTS; ++tries) {
        memset(&packet, 0, sizeof(packet));
        packet.hdr.type = ICMP_ECHO;
        packet.hdr.un.echo.id = getpid();
        packet.hdr.un.echo.sequence = tries + 1;
        packet.hdr.checksum = checksum(&packet, sizeof(packet));
        
        clock_gettime(CLOCK_MONOTONIC, &start);
        if (sendto(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)addr, sizeof(*addr)) <= 0) {
            perror("Send failed");
            continue;
        }

        // Receiving the echo reply
        alarm(TIMEOUT);
        memset(&packet, 0, sizeof(packet));
        if (recvfrom(sockfd, &packet, sizeof(packet), 0, (struct sockaddr *)&r_addr, &r_addr_len) <= 0) {
            printf("Ping %d: Timeout\n", tries + 1);
            continue;
        }
        alarm(0); // Cancel the alarm if response received

        clock_gettime(CLOCK_MONOTONIC, &end);
        long elapsed_ns = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
        printf("Ping %d: Received from %s: seq=%d time=%.2f ms\n", 
               tries + 1, inet_ntoa(r_addr.sin_addr), 
               packet.hdr.un.echo.sequence, 
               elapsed_ns / 1000000.0);
    }
}

// Signal handler to handle timeouts
void handle_alarm(int sig) {
    // Just return; the ping will timeout
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    signal(SIGALRM, handle_alarm); // Set up the signal handler for timeouts

    int sockfd;
    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    printf("Pinging %s:\n", argv[1]);
    send_ping(sockfd, &addr);

    close(sockfd);
    return EXIT_SUCCESS;
}