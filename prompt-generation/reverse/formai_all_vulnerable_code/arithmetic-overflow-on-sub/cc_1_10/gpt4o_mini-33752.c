//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <signal.h>

#define BUFFER_SIZE 1024
#define PORT 8080
#define PACKET_COUNT 10
#define TIMEOUT 2

volatile sig_atomic_t flag = 0;

void handle_signal(int sig) {
    flag = 1;
}

double calculate_rtt(struct timeval start, struct timeval end) {
    return (double)(end.tv_sec - start.tv_sec) * 1000.0 + (double)(end.tv_usec - start.tv_usec) / 1000.0;
}

void ping(const char* ip_address) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    struct timeval start_time, end_time;
    double rtt[PACKET_COUNT];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    signal(SIGINT, handle_signal);

    for (int i = 0; i < PACKET_COUNT; i++) {
        gettimeofday(&start_time, NULL);

        if (sendto(sockfd, "Ping", strlen("Ping"), 0, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            perror("Send failed");
            continue;
        }

        fd_set readfds;
        struct timeval timeout;
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;

        int activity = select(sockfd + 1, &readfds, NULL, NULL, &timeout);
        if (activity < 0) {
            perror("Select error");
            continue;
        } else if (activity == 0) {
            printf("Request timed out\n");
            rtt[i] = -1;
        } else {
            socklen_t addr_len = sizeof(server_addr);
            recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&server_addr, &addr_len);
            gettimeofday(&end_time, NULL);
            rtt[i] = calculate_rtt(start_time, end_time);
            printf("Received response: %s, RTT: %.2f ms\n", buffer, rtt[i]);
        }

        if (flag) {
            break;
        }

        usleep(100000); // Sleep to space out pings
    }

    close(sockfd);
}

void print_rtt_statistics(double* rtt, int count) {
    double min = -1, max = 0, total = 0, avg = 0;
    int valid_count = 0;

    for (int i = 0; i < count; i++) {
        if (rtt[i] >= 0) {
            valid_count++;
            total += rtt[i];
            if (min == -1 || rtt[i] < min) {
                min = rtt[i];
            }
            if (rtt[i] > max) {
                max = rtt[i];
            }
        }
    }
    
    if (valid_count > 0) {
        avg = total / valid_count;
    }

    printf("\nRTT Statistics:\n");
    printf("Minimum RTT: %.2f ms\n", min);
    printf("Maximum RTT: %.2f ms\n", max);
    printf("Average RTT: %.2f ms\n", avg);
    printf("Packets sent: %d\n", count);
    printf("Packets received: %d\n", valid_count);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IPADDRESS>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    double rtt[PACKET_COUNT] = {0};
    printf("Pinging %s with %d packets:\n", argv[1], PACKET_COUNT);
    ping(argv[1]);
    
    print_rtt_statistics(rtt, PACKET_COUNT);

    return 0;
}