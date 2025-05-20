//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PING_COUNT 4
#define IPERF_DURATION 10
#define BUFFER_SIZE 1024

double average(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return (double)sum / size;
}

double calculate_packet_loss(int sent, int received) {
    return ((double)(sent - received) / sent) * 100;
}

void ping_test(const char *host) {
    int ping_output[PING_COUNT];
    int received = 0;
    
    printf("Pinging %s...\n", host);
    
    for (int i = 0; i < PING_COUNT; i++) {
        char command[128];
        snprintf(command, sizeof(command), "ping -c 1 %s | grep 'time='", host);
        FILE *fp = popen(command, "r");
        if (fp == NULL) {
            printf("Failed to run ping command\n");
            return;
        }

        char buffer[BUFFER_SIZE];
        if (fgets(buffer, sizeof(buffer), fp) != NULL) {
            // Extracting the time value
            char *time_pos = strstr(buffer, "time=");
            if (time_pos) {
                ping_output[i] = atoi(time_pos + 5); // Convert string to int (ms)
                printf("Ping: %d ms\n", ping_output[i]);
                received++;
            }
        }

        pclose(fp);
        usleep(100000); // Sleep for 100 ms between pings
    }

    double avg_ping = average(ping_output, received);
    double packet_loss = calculate_packet_loss(PING_COUNT, received);

    printf("Average Ping: %.2f ms\n", avg_ping);
    printf("Packet Loss: %.2f%%\n", packet_loss);
}

void iperf_test(const char *server_ip) {
    printf("Running iPerf test to %s...\n", server_ip);
    char command[128];
    snprintf(command, sizeof(command), "iperf3 -c %s -t %d", server_ip, IPERF_DURATION);
    
    int status = system(command);
    if (status == -1) {
        perror("iperf command failed");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ping_host> <iperf_server_ip>\n", argv[0]);
        return 1;
    }

    const char *ping_host = argv[1];
    const char *iperf_server_ip = argv[2];

    printf("Network Quality of Service (QoS) Monitor\n");
    printf("=========================================\n");
    
    // Perform ping test
    ping_test(ping_host);
    
    // Perform iperf test
    iperf_test(iperf_server_ip);
    
    printf("=========================================\n");
    printf("QoS Monitoring Completed.\n");
    
    return 0;
}