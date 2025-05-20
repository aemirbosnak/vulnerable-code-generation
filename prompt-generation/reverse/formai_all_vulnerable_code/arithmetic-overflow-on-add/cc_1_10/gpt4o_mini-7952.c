//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <time.h>
#include <signal.h>

#define MAX_IP_LENGTH 16
#define BUFFER_SIZE 64
#define PING_COUNT 5

volatile sig_atomic_t keep_running = 1;

void handle_sigint(int sig) {
    keep_running = 0;
}

void ping(const char *ip_address) {
    struct sockaddr_in addr;
    int sockfd;
    char buffer[BUFFER_SIZE];
    struct timespec start, end;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    // Prepare the ping packet (ICMP echo request)
    for (int i = 0; i < PING_COUNT && keep_running; i++) {
        memset(buffer, 0, BUFFER_SIZE);
        buffer[0] = 8; // ICMP Echo Request
        buffer[1] = 0; // Type of service
        buffer[2] = 0; // Identifier
        buffer[3] = 0; // Sequence number
        buffer[4] = i; // Sequence number

        clock_gettime(CLOCK_MONOTONIC, &start);

        // Send the packet
        if (sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Send failed");
            continue;
        }

        // Wait for the reply
        socklen_t len = sizeof(addr);
        if (recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&addr, &len) < 0) {
            perror("Receive failed");
            continue;
        }

        clock_gettime(CLOCK_MONOTONIC, &end);
        long round_trip_time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;

        printf("Reply from %s: bytes=%ld time=%ld ms\n", ip_address, sizeof(buffer), round_trip_time);
        
        // Sleep before sending the next ping
        sleep(1);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP_ADDRESS>\n", argv[0]);
        return 1;
    }

    const char *ip_address = argv[1];
    signal(SIGINT, handle_sigint);

    printf("Pinging %s with %d bytes of data:\n", ip_address, BUFFER_SIZE);
    ping(ip_address);

    printf("Ping test completed.\n");
    return 0;
}