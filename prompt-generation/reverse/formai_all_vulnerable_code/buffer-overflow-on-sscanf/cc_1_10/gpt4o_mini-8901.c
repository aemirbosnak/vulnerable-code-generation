//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define PROC_STAT_PATH "/proc/stat"
#define BUF_SIZE 256
#define SLEEP_INTERVAL 1

void read_cpu_usage(long *user, long *nice, long *system, long *idle) {
    FILE *fp = fopen(PROC_STAT_PATH, "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[BUF_SIZE];
    fgets(buffer, BUF_SIZE, fp);
    sscanf(buffer, "cpu %ld %ld %ld %ld", user, nice, system, idle);

    fclose(fp);
}

void calculate_cpu_usage(long user1, long nice1, long system1, long idle1,
                          long user2, long nice2, long system2, long idle2,
                          float *cpu_usage) {
    long idle_diff = idle2 - idle1;
    long total_diff = (user2 + nice2 + system2 + idle2) - (user1 + nice1 + system1 + idle1);

    if (total_diff == 0) {
        *cpu_usage = 0.0;
    } else {
        *cpu_usage = (float)(total_diff - idle_diff) / total_diff * 100.0;
    }
}

int main() {
    long user1, nice1, system1, idle1;
    long user2, nice2, system2, idle2;
    float cpu_usage;

    printf("CPU Usage Monitor\n");
    printf("=================\n");

    // Initial read
    read_cpu_usage(&user1, &nice1, &system1, &idle1);
    sleep(SLEEP_INTERVAL); // Wait for a second

    // Second read
    read_cpu_usage(&user2, &nice2, &system2, &idle2);

    // Calculate CPU usage
    calculate_cpu_usage(user1, nice1, system1, idle1, user2, nice2, system2, idle2, &cpu_usage);

    // Output the results
    printf("CPU Usage: %.2f%%\n", cpu_usage);
    
    return 0;
}