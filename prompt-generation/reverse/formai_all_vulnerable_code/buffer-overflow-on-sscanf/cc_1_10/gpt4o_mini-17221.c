//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void display_cpu_usage(float usage) {
    printf("\033[H\033[J"); // Clear screen
    printf("=======================================\n");
    printf("    CPU Usage Monitor\n");
    printf("=======================================\n");
    printf(" CPU Usage: %.2f%%\n", usage);
    printf("=======================================\n");
    
    int bars = usage / 2; // Scale for better visual representation
    printf(" CPU Load: |");
    for (int i = 0; i < 50; i++) {
        if (i < bars) {
            printf("█");
        } else {
            printf(" ");
        }
    }
    printf("| %d%%\n", (int)usage);
    printf("=======================================\n\n");
    printf(" Updating every second...\n");
}

float get_cpu_usage() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    unsigned long long idle_time, total_time, user_time, nice_time, sys_time, iowait_time, irq_time, softirq_time, steal_time;
    unsigned long long total_jiffies_1, total_jiffies_2, idle_jiffies_1, idle_jiffies_2;

    file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Failed to read from /proc/stat");
        exit(EXIT_FAILURE);
    }
    
    // Read the first line containing CPU statistics
    fgets(line, sizeof(line), file);
    sscanf(line, "cpu %llu %llu %llu %llu %llu %llu %llu %llu",
           &user_time, &nice_time, &sys_time, &idle_time, 
           &iowait_time, &irq_time, &softirq_time, &steal_time);

    total_time = user_time + nice_time + sys_time + idle_time + 
                 iowait_time + irq_time + softirq_time + steal_time;
    fclose(file);

    sleep(1); // Wait a second to measure CPU load again

    file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Failed to read from /proc/stat");
        exit(EXIT_FAILURE);
    }
    
    // Read the CPU statistics again
    fgets(line, sizeof(line), file);
    sscanf(line, "cpu %llu %llu %llu %llu %llu %llu %llu %llu",
           &user_time, &nice_time, &sys_time, &idle_time, 
           &iowait_time, &irq_time, &softirq_time, &steal_time);

    total_jiffies_2 = user_time + nice_time + sys_time + idle_time + 
                      iowait_time + irq_time + softirq_time + steal_time;
    idle_jiffies_2 = idle_time + iowait_time;

    fclose(file);

    float cpu_usage = ((float)(total_jiffies_2 - total_time) / 
                       (total_jiffies_2 - idle_jiffies_2)) * 100;
    return cpu_usage;
}

int main() {
    while (1) {
        float usage = get_cpu_usage();
        display_cpu_usage(usage);
    }
    return 0;
}