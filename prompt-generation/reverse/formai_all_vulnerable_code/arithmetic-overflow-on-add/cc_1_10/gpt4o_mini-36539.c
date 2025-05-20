//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: careful
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
    long steal;
    long guest;
    long guest_nice;
} CpuUsage;

void read_cpu_usage(CpuUsage *cpu) {
    FILE *file = fopen(CPU_INFO_FILE, "r");
    if (file == NULL) {
        perror("Error opening /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
               &cpu->user, &cpu->nice, &cpu->system, &cpu->idle,
               &cpu->iowait, &cpu->irq, &cpu->softirq, &cpu->steal,
               &cpu->guest, &cpu->guest_nice);
    }
    fclose(file);
}

void calculate_cpu_usage(CpuUsage *prev, CpuUsage *curr, double *cpu_usage) {
    long prev_total = prev->user + prev->nice + prev->system + prev->idle + 
                      prev->iowait + prev->irq + prev->softirq + prev->steal;
    long curr_total = curr->user + curr->nice + curr->system + curr->idle + 
                      curr->iowait + curr->irq + curr->softirq + curr->steal;

    long idle_delta = curr->idle - prev->idle;
    long total_delta = curr_total - prev_total;

    if (total_delta == 0) {
        *cpu_usage = 0.0;
    } else {
        *cpu_usage = (1.0 - (double)idle_delta / (double)total_delta) * 100.0;
    }
}

int main() {
    CpuUsage prev_usage, curr_usage;

    read_cpu_usage(&prev_usage);
    sleep(SLEEP_INTERVAL); // Sleep for an interval to capture the next usage.

    while (1) {
        read_cpu_usage(&curr_usage);
        double cpu_usage = 0.0;
        calculate_cpu_usage(&prev_usage, &curr_usage, &cpu_usage);
        
        // Print CPU usage
        printf("CPU Usage: %.2f%%\n", cpu_usage);

        // Prepare for next iteration
        prev_usage = curr_usage;
        sleep(SLEEP_INTERVAL); // Sleep for an interval before the next reading.
    }

    return 0;
}