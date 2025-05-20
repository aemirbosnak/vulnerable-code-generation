//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <errno.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define MAX_ATTEMPTS 4

typedef struct {
    struct sockaddr_in addr;
    char *target;
    int attempts;
    int received;
} PingData;

void print_banner() {
    printf("====================================\n");
    printf("       CYBERPUNK PING TEST         \n");
    printf("====================================\n");
    printf("A netrunner's companion for testing the \n");
    printf("stability of networks in a cybernetic world.\n\n");
}

void init_ping_data(PingData *ping, const char *target) {
    memset(ping, 0, sizeof(PingData));
    ping->target = strdup(target);
    ping->attempts = MAX_ATTEMPTS;
    ping->addr.sin_family = AF_INET;
    ping->addr.sin_port = htons(0);
    
    if (inet_pton(AF_INET, target, &ping->addr.sin_addr) <= 0) {
        fprintf(stderr, "Error parsing IP address\n");
        exit(EXIT_FAILURE);
    }
}

void send_ping(int sockfd, PingData *ping) {
    char packet[PACKET_SIZE];
    struct timespec start, end;
    
    for (int i = 0; i < ping->attempts; i++) {
        memset(packet, 0, PACKET_SIZE);
        snprintf(packet, PACKET_SIZE, "Ping #%d from Cybernet Terminal", i+1);

        clock_gettime(CLOCK_MONOTONIC, &start);
        if (sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)&ping->addr, sizeof(ping->addr)) < 0) {
            fprintf(stderr, "Send failed: %s\n", strerror(errno));
            continue;
        }

        char buffer[PACKET_SIZE];
        struct sockaddr_in from;
        socklen_t fromlen = sizeof(from);

        // Set timeout for receiving response
        struct timeval tv;
        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv,sizeof(tv));

        ssize_t bytes_received = recvfrom(sockfd, buffer, PACKET_SIZE, 0, (struct sockaddr *)&from, &fromlen);
        clock_gettime(CLOCK_MONOTONIC, &end);

        if (bytes_received < 0) {
            printf("Response from %s: Request timed out!\n", ping->target);
        } else {
            long ping_time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
            printf("Response from %s: bytes=%zd time=%ld ms\n", ping->target, bytes_received, ping_time);
            ping->received++;
        }
        sleep(1);
    }
}

void print_summary(PingData *ping) {
    printf("\n--- Cyberpunk Ping Statistics ---\n");
    printf("%d packets transmitted, %d received, %.1f%% packet loss\n",
           ping->attempts, ping->received,
           ((ping->attempts - ping->received) / (float)ping->attempts) * 100);
}

int main(int argc, char *argv[]) {
    print_banner();
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    PingData ping;
    init_ping_data(&ping, argv[1]);

    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    send_ping(sockfd, &ping);
    
    print_summary(&ping);

    free(ping.target);
    close(sockfd);
    return 0;
}