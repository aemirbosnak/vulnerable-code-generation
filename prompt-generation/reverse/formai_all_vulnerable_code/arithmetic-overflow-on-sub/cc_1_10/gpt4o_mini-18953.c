//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ifaddrs.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define INTERFACE "eth0"
#define PING_HOST "8.8.8.8" // Google's public DNS
#define PING_COUNT 4
#define REPORT_INTERVAL 5

typedef struct {
    double latency;
    int packet_loss;
    double throughput;
} QoSStats;

void perform_ping(QoSStats *stats) {
    char command[256];
    
    snprintf(command, sizeof(command), "ping -c %d -q %s | grep 'loss' | awk '{print $6}'", PING_COUNT, PING_HOST);
    
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return;
    }
    
    char result[128];
    if (fgets(result, sizeof(result), fp) != NULL) {
        stats->packet_loss = atoi(result);
    } else {
        stats->packet_loss = -1; // Error in fetching packet loss
    }
    pclose(fp);
}

void calculate_latency(QoSStats *stats) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    char command[256];
    snprintf(command, sizeof(command), "ping -c %d %s > /dev/null", PING_COUNT, PING_HOST);
    
    system(command);
    
    clock_gettime(CLOCK_MONOTONIC, &end);
    stats->latency = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;
}

void get_throughput(QoSStats *stats) {
    char command[256];
    snprintf(command, sizeof(command), "iperf -c %s -f m -t 10 -P 1 | tail -n 8 | grep 'sender' | awk '{print $7}'", PING_HOST);
    
    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return;
    }

    char result[128];
    if (fgets(result, sizeof(result), fp) != NULL) {
        stats->throughput = atof(result); // Throughput in Mbits/sec
    } else {
        stats->throughput = -1; // Error in fetching throughput
    }
    pclose(fp);
}

void display_stats(QoSStats *stats) {
    printf("QoS Report:\n");
    printf("===========\n");
    printf("Latency: %.2f ms\n", stats->latency);
    printf("Packet Loss: %d%%\n", stats->packet_loss);
    printf("Throughput: %.2f Mbits/sec\n\n", stats->throughput);
}

int main() {
    QoSStats stats;
    
    while (1) {
        printf("Gathering QoS data...\n");
        
        calculate_latency(&stats);
        perform_ping(&stats);
        get_throughput(&stats);
        display_stats(&stats);
        
        sleep(REPORT_INTERVAL);
    }
    
    return 0;
}