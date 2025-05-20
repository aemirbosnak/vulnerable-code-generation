//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PROC_STAT_PATH "/proc/stat"
#define SAMPLE_INTERVAL 1 // Time interval (seconds) between samples

typedef struct CPUUsage {
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long iowait;
    unsigned long long irq;
    unsigned long long softirq;
    unsigned long long steal;
    unsigned long long total;
} CPUUsage;

void get_cpu_usage(CPUUsage *cpu) {
    FILE *file = fopen(PROC_STAT_PATH, "r");
    if (!file) {
        perror("Could not open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char line[128];
    if (fgets(line, sizeof(line), file)) {
        sscanf(line, "cpu %llu %llu %llu %llu %llu %llu %llu %llu",
               &cpu->user, &cpu->nice, &cpu->system, &cpu->idle,
               &cpu->iowait, &cpu->irq, &cpu->softirq, &cpu->steal);
        cpu->total = cpu->user + cpu->nice + cpu->system + cpu->idle +
                     cpu->iowait + cpu->irq + cpu->softirq + cpu->steal;
    }
    fclose(file);
}

double calculate_cpu_percentage(CPUUsage *prev, CPUUsage *curr) {
    unsigned long long total_diff = curr->total - prev->total;
    unsigned long long idle_diff = curr->idle - prev->idle;

    if (total_diff == 0) {
        return 0.0; // Prevent division by zero
    }

    return 100.0 * (1.0 - ((double) idle_diff / (double) total_diff));
}

void display_cpu_usage() {
    CPUUsage prev, curr;

    get_cpu_usage(&prev);
    sleep(SAMPLE_INTERVAL); // Wait for a sample interval
    get_cpu_usage(&curr);

    double cpu_percent = calculate_cpu_percentage(&prev, &curr);
    printf("CPU Usage: %.2f%%\n", cpu_percent);
}

int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "--continuous") == 0) {
        while (1) {
            display_cpu_usage();
            sleep(SAMPLE_INTERVAL);
        }
    } else {
        printf("CPU Usage Monitor\n");
        display_cpu_usage();
    }
    return 0;
}