//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <sys/sysinfo.h>

#define CPU_USAGE_ERROR     -1
#define CPU_USAGE_INTERVAL  1
#define LINE_SIZE           1024

float calculate_cpu_usage(uint64_t *prev_total, uint64_t *prev_idle) {
    uint64_t current_idle, current_total;
    char line[LINE_SIZE];
    unsigned long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;

    FILE *fp = fopen("/proc/stat", "r");

    fgets(line, LINE_SIZE, fp);
    sscanf(line, "cpu %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);

    fclose(fp);

    current_idle = idle + iowait;
    current_total = user + nice + system + idle + iowait + irq + softirq + guest + guest_nice;

    float usage = ((current_total - *prev_total) - (current_idle - *prev_idle)) * 100.0 / (current_total - *prev_total);
    *prev_idle = current_idle;
    *prev_total = current_total;

    return usage;
}

int main(int argc, char *argv[]) {
    uint64_t prev_total = 0, prev_idle = 0;
    struct sysinfo si;
    int total_memory, used_memory;

    while (1) {
        if (sysinfo(&si) != 0) {
            fprintf(stderr, "Error retrieving system memory information.\n");
            exit(EXIT_FAILURE);
        }

        total_memory = si.totalram / 1024;
        used_memory = (si.totalram - si.freeram) / 1024;

        float cpu_usage = calculate_cpu_usage(&prev_total, &prev_idle);
        printf("CPU usage: %0.2f%% \t\t Memory usage: %d/%dMB\n", cpu_usage, used_memory, total_memory);

        sleep(CPU_USAGE_INTERVAL);
    }

    return CPU_USAGE_ERROR;
}