//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_PINGS 5
#define TARGET "google.com"

typedef struct {
    int successful_pings;
    double total_latency;
} QoSData;

void ping_target(const char *target, QoSData *data) {
    char command[256];
    snprintf(command, sizeof(command), "ping -c %d %s", MAX_PINGS, target);
    
    FILE *ping = popen(command, "r");
    if (ping == NULL) {
        perror("popen failed");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), ping) != NULL) {
        if (strstr(line, "time=") != NULL) {
            double latency;
            sscanf(line, "%*s %*s %*s %*s time=%lf", &latency);
            data->successful_pings++;
            data->total_latency += latency;
            printf("Ping response time: %.2lf ms\n", latency);
        }
    }

    pclose(ping);
}

void display_results(const QoSData *data) {
    if (data->successful_pings == 0) {
        printf("No successful pings recorded.\n");
        return;
    }
    
    double avg_latency = data->total_latency / data->successful_pings;
    printf("Total successful pings: %d\n", data->successful_pings);
    printf("Average latency: %.2lf ms\n", avg_latency);
}

int main() {
    QoSData data = {0, 0.0};
    int interval;

    printf("Welcome to the Network QoS Monitor!\n");
    printf("You are pinging: %s\n", TARGET);
    printf("How often would you like to ping (in seconds)? ");
    scanf("%d", &interval);

    while (1) {
        printf("\n--- Pinging... ---\n");
        ping_target(TARGET, &data);
        display_results(&data);
        
        // Reset for next interval
        data.successful_pings = 0;
        data.total_latency = 0.0;

        printf("Waiting %d seconds before the next ping...\n", interval);
        sleep(interval);
    }

    return 0;
}