//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define CPU_INFO_FILE "/proc/stat"
#define SLEEP_INTERVAL 1

typedef struct {
    unsigned long user;
    unsigned long nice;
    unsigned long system;
    unsigned long idle;
    unsigned long iowait;
    unsigned long irq;
    unsigned long softirq;
    unsigned long steal;
    unsigned long guest;
    unsigned long guest_nice;
} CPUInfo;

void parse_cpu_info(CPUInfo *cpu_info, char *line) {
    sscanf(line, "cpu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu",
           &cpu_info->user, &cpu_info->nice, &cpu_info->system,
           &cpu_info->idle, &cpu_info->iowait, &cpu_info->irq,
           &cpu_info->softirq, &cpu_info->steal, 
           &cpu_info->guest, &cpu_info->guest_nice);
}

void read_cpu_info(CPUInfo *cpu_info) {
    FILE *file = fopen(CPU_INFO_FILE, "r");
    if (file == NULL) {
        perror("Could not open CPU info file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    if (fgets(line, sizeof(line), file) != NULL) {
        parse_cpu_info(cpu_info, line);
    }

    fclose(file);
}

double calculate_cpu_usage(CPUInfo *prev_info, CPUInfo *curr_info) {
    unsigned long prev_total = prev_info->user + prev_info->nice + prev_info->system + 
                                prev_info->idle + prev_info->iowait + prev_info->irq + 
                                prev_info->softirq + prev_info->steal;

    unsigned long curr_total = curr_info->user + curr_info->nice + curr_info->system + 
                                curr_info->idle + curr_info->iowait + curr_info->irq + 
                                curr_info->softirq + curr_info->steal;

    unsigned long prev_idle = prev_info->idle + prev_info->iowait;
    unsigned long curr_idle = curr_info->idle + curr_info->iowait;

    unsigned long total_diff = curr_total - prev_total;
    unsigned long idle_diff = curr_idle - prev_idle;

    return (1.0 - (double)idle_diff / total_diff) * 100.0;
}

void display_cpu_usage(double usage) {
    printf("Current CPU Usage: %.2f%%\n", usage);
}

int main() {
    CPUInfo prev_info, curr_info;

    read_cpu_info(&prev_info);
    sleep(SLEEP_INTERVAL); // Wait for a second
    read_cpu_info(&curr_info);
    
    double cpu_usage = calculate_cpu_usage(&prev_info, &curr_info);
    display_cpu_usage(cpu_usage);

    return 0;
}