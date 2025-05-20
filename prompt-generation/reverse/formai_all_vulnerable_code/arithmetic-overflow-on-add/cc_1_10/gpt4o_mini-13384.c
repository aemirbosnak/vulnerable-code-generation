//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_CPUS 128

void get_cpu_usage(double cpu_usage[], int cpu_count) {
    FILE *file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    int cpu_index = 0;

    while (cpu_index < cpu_count && fgets(buffer, sizeof(buffer), file)) {
        if (strncmp(buffer, "cpu", 3) != 0) {
            continue;
        }

        long idle, total;
        long user, nice, system, irq, softirq, steal, guest, guest_nice;

        sscanf(buffer + 3, "%ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
               &user, &nice, &system, &irq, &softirq, &steal, &guest, &guest_nice);

        idle = nice + (guest + guest_nice);
        total = user + nice + system + irq + softirq + steal + idle;

        cpu_usage[cpu_index++] = (double)total - (double)idle;
    }

    fclose(file);
}

void print_cpu_usage(double cpu_usage[], int cpu_count, unsigned long prev_total[], unsigned long prev_idle[]) {
    printf("\nCPU Usage:\n");
    printf("----------\n");
    printf("CPU   | Usage %%\n");
    printf("------|---------\n");

    for (int i = 0; i < cpu_count; i++) {
        double usage = 0.0;
        unsigned long total = (unsigned long)cpu_usage[i];
        unsigned long idle = prev_idle[i];

        if (total - prev_total[i] > 0) {
            usage = 100.0 * (total - prev_total[i] - (idle - prev_idle[i])) / (total - prev_total[i]);
        }

        printf("CPU%d  | %.2f%%\n", i, usage);
        prev_total[i] = total;  // Update for next iteration
        prev_idle[i] = idle;     // Update for next iteration
    }
    printf("----------\n");
}

int main() {
    double cpu_usage[MAX_CPUS];
    unsigned long prev_total[MAX_CPUS] = {0};
    unsigned long prev_idle[MAX_CPUS] = {0};
    int cpu_count = sysconf(_SC_NPROCESSORS_ONLN);

    printf("Energetic CPU Usage Monitor!\n");
    printf("Monitoring CPU usage every second. Press Ctrl+C to exit.\n\n");

    while (1) {
        get_cpu_usage(cpu_usage, cpu_count);
        sleep(1);

        unsigned long cpu_reading[MAX_CPUS];
        get_cpu_usage(cpu_reading, cpu_count);
        print_cpu_usage(cpu_reading, cpu_count, prev_total, prev_idle);
    }

    return 0;
}