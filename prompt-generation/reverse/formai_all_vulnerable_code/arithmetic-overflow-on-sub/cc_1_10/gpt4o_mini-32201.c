//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define MAX_CPUS 16
#define SLEEP_INTERVAL 1 // seconds
#define CPU_COUNT 4

typedef struct {
    int cpu_id;
    double usage;
} cpu_info;

cpu_info cpus[CPU_COUNT];

void read_cpu_usage() {
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    int cpu_number = 0;

    while (cpu_number < CPU_COUNT && fgets(buffer, sizeof(buffer), fp)) {
        if (strncmp(buffer, "cpu", 3) == 0) {
            long long user, nice, sys, idle, iowait, irq, softirq, steal;
            sscanf(buffer, "cpu%d %lld %lld %lld %lld %lld %lld %lld %lld", 
                    &cpu_number, &user, &nice, &sys, &idle, &iowait, &irq, &softirq, &steal);

            long long total = user + nice + sys + idle + iowait + irq + softirq + steal;
            
            // Calculate CPU utilization percentage
            if (cpu_number < CPU_COUNT) {
                cpus[cpu_number].cpu_id = cpu_number;
                cpus[cpu_number].usage = 100.0 * (total - idle) / total;
            }
        }
    }

    fclose(fp);
}

void *display_usage(void *arg) {
    while (1) {
        printf("\033[H\033[J"); // Clear the screen
        printf("CPU Usage Monitor:\n");
        printf("-------------------\n");
        read_cpu_usage();

        for (int i = 0; i < CPU_COUNT; i++) {
            printf("CPU %d Usage: %.2f%%\n", cpus[i].cpu_id, cpus[i].usage);
        }
        
        sleep(SLEEP_INTERVAL);
    }
    return NULL;
}

int main() {
    pthread_t thread_id;

    // Create a thread to continuously show CPU usage
    if (pthread_create(&thread_id, NULL, display_usage, NULL) != 0) {
        perror("Failed to create thread");
        return EXIT_FAILURE;
    }

    // Wait for the thread to finish (it won't in this case)
    pthread_join(thread_id, NULL);

    return 0;
}