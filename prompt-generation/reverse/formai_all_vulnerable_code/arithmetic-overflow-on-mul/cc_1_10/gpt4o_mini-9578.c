//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <errno.h>
#include <time.h>

#define PACKET_SIZE 64
#define PING_COUNT 5

typedef struct {
    struct sockaddr_in addr;
    int sockfd;
    int sent_count;
    int received_count;
    int min_rtt;
    int max_rtt;
    long total_rtt;
} PingData;

void calculate_rtt(PingData *ping_data, struct timespec start, struct timespec end) {
    long rtt = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
    ping_data->total_rtt += rtt;
    
    if (ping_data->min_rtt == -1 || rtt < ping_data->min_rtt) {
        ping_data->min_rtt = rtt;
    }
    if (ping_data->max_rtt == -1 || rtt > ping_data->max_rtt) {
        ping_data->max_rtt = rtt;
    }
}

void send_ping(PingData *ping_data, const char *ip_addr) {
    char packet[PACKET_SIZE];
    struct timespec start, end;

    ping_data->sent_count++;
    clock_gettime(CLOCK_MONOTONIC, &start);

    if (sendto(ping_data->sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&ping_data->addr, sizeof(ping_data->addr)) <= 0) {
        perror("Ping send error");
        return;
    }

    socklen_t len = sizeof(ping_data->addr);
    if (recvfrom(ping_data->sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&ping_data->addr, &len) > 0) {
        clock_gettime(CLOCK_MONOTONIC, &end);
        ping_data->received_count++;
        calculate_rtt(ping_data, start, end);
        printf("Reply from %s: Bytes=%d time=%ld ms\n", ip_addr, (int)sizeof(packet), (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000);
    } else {
        perror("Ping recv error");
    }
}

void print_summary(PingData *ping_data) {
    printf("\n--- Ping statistics ---\n");
    printf("%d packets transmitted, %d received, %.1f%% packet loss\n",
           ping_data->sent_count, ping_data->received_count,
           100.0 * (ping_data->sent_count - ping_data->received_count) / ping_data->sent_count);
    
    if (ping_data->received_count > 0) {
        printf("round-trip min/avg/max = %d/%ld/%d ms\n",
               ping_data->min_rtt, ping_data->total_rtt / ping_data->received_count, ping_data->max_rtt);
    }
}

void initialize_ping_data(PingData *ping_data, const char *ip_addr) {
    memset(ping_data, 0, sizeof(PingData));
    ping_data->min_rtt = -1;
    ping_data->max_rtt = -1;
    ping_data->total_rtt = 0;

    ping_data->sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (ping_data->sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&ping_data->addr, 0, sizeof(ping_data->addr));
    ping_data->addr.sin_family = AF_INET;
    ping_data->addr.sin_addr.s_addr = inet_addr(ip_addr);
    ping_data->addr.sin_port = htons(0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    PingData ping_data;
    initialize_ping_data(&ping_data, argv[1]);
    
    for (int i = 0; i < PING_COUNT; i++) {
        send_ping(&ping_data, argv[1]);
        sleep(1);
    }
    
    print_summary(&ping_data);

    close(ping_data.sockfd);
    return 0;
}