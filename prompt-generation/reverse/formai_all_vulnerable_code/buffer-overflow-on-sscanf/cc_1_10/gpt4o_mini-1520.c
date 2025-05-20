//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define CPU_INFO_FILE "/proc/stat"
#define SLEEP_INTERVAL 1

typedef struct {
    long user;
    long nice;
    long system;
    long idle;
    long iowait;
    long irq;
    long softirq;
    long total;
} CPUInfo;

void get_cpu_info(CPUInfo *cpu_info) {
    FILE *fp = fopen(CPU_INFO_FILE, "r");
    if (!fp) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), fp); // Read the first line

    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld",
           &cpu_info->user,
           &cpu_info->nice,
           &cpu_info->system,
           &cpu_info->idle,
           &cpu_info->iowait,
           &cpu_info->irq,
           &cpu_info->softirq);

    cpu_info->total = cpu_info->user + cpu_info->nice + cpu_info->system +
                      cpu_info->idle + cpu_info->iowait + cpu_info->irq +
                      cpu_info->softirq;

    fclose(fp);
}

double calculate_cpu_usage(CPUInfo *prev_info, CPUInfo *curr_info) {
    long prev_total = prev_info->total;
    long curr_total = curr_info->total;

    long total_diff = curr_total - prev_total;
    long idle_diff = curr_info->idle - prev_info->idle;

    // Calculate CPU usage as a percentage
    return 100.0 * (1.0 - (double)idle_diff / total_diff);
}

void display_cpu_usage() {
    CPUInfo prev_info, curr_info;

    // Get initial CPU information
    get_cpu_info(&prev_info);

    while (1) {
        sleep(SLEEP_INTERVAL);

        // Get current CPU information
        get_cpu_info(&curr_info);
        
        // Calculate CPU usage
        double usage = calculate_cpu_usage(&prev_info, &curr_info);
        
        // Update previous info for the next iteration
        prev_info = curr_info;

        // Print the CPU usage
        printf("\rCPU Usage: %.2f%%    ", usage);
        fflush(stdout);
    }
}

int main() {
    printf("Starting CPU Usage Monitor...\nPress Ctrl+C to stop.\n");
    display_cpu_usage();
    return 0;
}