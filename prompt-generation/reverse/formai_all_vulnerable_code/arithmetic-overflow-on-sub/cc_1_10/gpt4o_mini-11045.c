//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>

#define PACKET_SIZE 64
#define NUMBER_OF_PACKETS 10

static volatile int keep_running = 1;

void intHandler(int dummy) {
    keep_running = 0;
}

void print_usage(const char *program_name) {
    printf("Usage: %s <destination_ip>\n", program_name);
}

void calculate_qos(const char *destination_ip) {
    int sockfd;
    struct sockaddr_in addr;
    struct timespec start_time, end_time;
    char buffer[PACKET_SIZE];
    int packets_sent = 0, packets_received = 0;

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(destination_ip);

    while (keep_running && packets_sent < NUMBER_OF_PACKETS) {
        clock_gettime(CLOCK_MONOTONIC, &start_time);
        if (sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, sizeof(addr)) <= 0) {
            perror("Failed to send packet");
            continue;
        }

        packets_sent++;

        ssize_t bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received > 0) {
            clock_gettime(CLOCK_MONOTONIC, &end_time);
            packets_received++;
            long latency = (end_time.tv_sec - start_time.tv_sec) * 1000 + 
                           (end_time.tv_nsec - start_time.tv_nsec) / 1000000;

            printf("Packet %d: Received, Latency: %ld ms\n", packets_sent, latency);
        } else {
            printf("Packet %d: Timeout\n", packets_sent);
        }

        sleep(1); // Wait for 1 second before sending the next packet
    }

    close(sockfd);
    printf("\n--- QoS Monitor Summary ---\n");
    printf("Packets Sent: %d, Packets Received: %d, Packet Loss: %.2f%%\n",
           packets_sent,
           packets_received,
           ((float)(packets_sent - packets_received) / packets_sent) * 100);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    signal(SIGINT, intHandler);
    calculate_qos(argv[1]);

    return 0;
}