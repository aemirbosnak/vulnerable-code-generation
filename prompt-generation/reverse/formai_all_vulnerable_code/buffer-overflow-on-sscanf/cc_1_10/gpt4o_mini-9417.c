//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#define NUM_CPU 4  // Monitor first n CPUs

void get_cpu_times(unsigned long long *cpu_times) {
    FILE *file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char line[256];
    if (fgets(line, sizeof(line), file) != NULL) {
        char cpu[5];
        sscanf(line, "%s %Lu %Lu %Lu %Lu %Lu %Lu %Lu %Lu", cpu,
               &cpu_times[0], &cpu_times[1], &cpu_times[2],
               &cpu_times[3], &cpu_times[4], &cpu_times[5],
               &cpu_times[6], &cpu_times[7]);
    }

    fclose(file);
}

void display_cpu_usage(unsigned long long *prev_cpu_times, unsigned long long *curr_cpu_times) {
    unsigned long long prev_idle = prev_cpu_times[3] + prev_cpu_times[4];
    unsigned long long curr_idle = curr_cpu_times[3] + curr_cpu_times[4];

    unsigned long long prev_total = 0, curr_total = 0;
    for (int i = 0; i < 8; i++) {
        prev_total += prev_cpu_times[i];
        curr_total += curr_cpu_times[i];
    }

    unsigned long long idle_diff = curr_idle - prev_idle;
    unsigned long long total_diff = curr_total - prev_total;

    if (total_diff == 0) return; // Avoid division by zero

    double usage = (1.0 - (double)idle_diff / total_diff) * 100;
    printf("CPU Usage: %.2f%%\n", usage);
}

void display_header() {
    printf("\n");
    printf("*******************************************\n");
    printf("             C CPU Usage Monitor          \n");
    printf("*******************************************\n");
    printf("Press Ctrl+C to exit...\n\n");
}

int main() {
    unsigned long long prev_cpu_times[8] = {0};
    unsigned long long curr_cpu_times[8] = {0};

    // Initial read of CPU times
    get_cpu_times(prev_cpu_times);
    
    display_header();
    
    while (1) {
        sleep(1);  // Refresh every second

        // Read CPU times again
        get_cpu_times(curr_cpu_times);

        // Calculate and display CPU usage
        display_cpu_usage(prev_cpu_times, curr_cpu_times);
        
        // Update previous CPU times for the next iteration
        memcpy(prev_cpu_times, curr_cpu_times, sizeof(prev_cpu_times));
    }

    return 0;
}