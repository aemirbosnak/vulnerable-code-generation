//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024
#define DEFAULT_INTERVAL 5 // seconds
#define DEFAULT_PACKET_COUNT 10

bool running = true;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP address> [interval] [packet count]\n", argv[0]);
        return 1;
    }

    int sock_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock_fd < 0) {
        perror("Failed to create socket");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(0); // use an ephemeral port
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) != 1) {
        printf("Invalid IP address: %s\n", argv[1]);
        return 1;
    }

    if (bind(sock_fd, (const struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to bind socket");
        return 1;
    }

    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(80); // use HTTP port
    if (inet_pton(AF_INET, argv[1], &dest_addr.sin_addr) != 1) {
        printf("Invalid IP address: %s\n", argv[1]);
        return 1;
    }

    int interval = DEFAULT_INTERVAL;
    if (argc > 2) {
        interval = atoi(argv[2]);
    }

    int packet_count = DEFAULT_PACKET_COUNT;
    if (argc > 3) {
        packet_count = atoi(argv[3]);
    }

    printf("Monitoring QoS to %s every %d seconds with %d packets\n", argv[1], interval, packet_count);

    int seq_num = 0;
    double avg_rtt = 0.0;
    double packet_loss_rate = 0.0;
    int packets_sent = 0;
    int packets_received = 0;

    while (running) {
        for (int i = 0; i < packet_count; i++) {
            char buf[MAX_PACKET_SIZE];
            memset(buf, 0, sizeof(buf));
            char *msg = "PING";
            snprintf(buf, sizeof(buf), "%d:%s", seq_num++, msg);
            int32_t len = strlen(buf);
            int n = sendto(sock_fd, buf, len, 0, (const struct sockaddr *)&dest_addr, sizeof(dest_addr));
            if (n < 0) {
                perror("Failed to send packet");
            } else {
                packets_sent++;
            }
        }

        struct timeval timeout;
        timeout.tv_sec = interval;
        timeout.tv_usec = 0;

        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sock_fd, &read_fds);

        int ready = select(sock_fd + 1, &read_fds, NULL, NULL, &timeout);
        if (ready < 0) {
            perror("Failed to select socket");
        } else if (ready == 0) {
            printf("No response from %s\n", argv[1]);
            packet_loss_rate = 1.0;
        } else {
            char buf[MAX_PACKET_SIZE];
            struct sockaddr_in resp_addr;
            socklen_t resp_len = sizeof(resp_addr);
            memset(&resp_addr, 0, sizeof(resp_addr));
            int n = recvfrom(sock_fd, buf, sizeof(buf), 0, (struct sockaddr *)&resp_addr, &resp_len);
            if (n < 0) {
                perror("Failed to receive packet");
            } else {
                packets_received++;
                char *ptr;
                int resp_seq_num = strtol(buf, &ptr, 10);
                if (resp_seq_num >= seq_num - packet_count || resp_seq_num == -1) {
                    struct timespec timestamp;
                    clock_gettime(CLOCK_MONOTONIC, &timestamp);
                    double rtt = (timestamp.tv_sec - strtol(ptr, &ptr, 10)) + (timestamp.tv_nsec - strtol(ptr, NULL, 10)) / 1e9;
                    avg_rtt = (avg_rtt * (packets_received - 1) + rtt) / packets_received;
                }
            }
        }

        packet_loss_rate = (double)(packets_sent - packets_received) / packets_sent;

        printf("Avg RTT: %.3f ms, Packet Loss Rate: %.3f%%\n", avg_rtt * 1e3, packet_loss_rate * 100);
    }

    close(sock_fd);

    return 0;
}