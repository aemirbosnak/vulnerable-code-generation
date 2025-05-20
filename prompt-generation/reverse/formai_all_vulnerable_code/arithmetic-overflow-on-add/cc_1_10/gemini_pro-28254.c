//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Constants
#define UPDATE_INTERVAL_MS 1000 // 1 second
#define NUM_PAST_SAMPLES 10

// Global variables
double past_samples[NUM_PAST_SAMPLES];
int past_sample_index = 0;

// Function declarations
double get_cpu_usage();

int main() {
    // Print header
    printf("CPU Usage Monitor\n");
    printf("------------------\n");

    // Main loop
    while (1) {
        // Get CPU usage
        double cpu_usage = get_cpu_usage();

        // Store past sample
        past_samples[past_sample_index] = cpu_usage;
        past_sample_index = (past_sample_index + 1) % NUM_PAST_SAMPLES;

        // Calculate average CPU usage
        double avg_cpu_usage = 0;
        for (int i = 0; i < NUM_PAST_SAMPLES; i++) {
            avg_cpu_usage += past_samples[i];
        }
        avg_cpu_usage /= NUM_PAST_SAMPLES;

        // Print CPU usage
        printf("CPU Usage: %.2f%%\n", avg_cpu_usage);

        // Sleep
        usleep(UPDATE_INTERVAL_MS * 1000);
    }

    return 0;
}

double get_cpu_usage() {
    // Get CPU usage from /proc/stat
    FILE *proc_stat = fopen("/proc/stat", "r");
    if (proc_stat == NULL) {
        perror("fopen");
        exit(1);
    }

    // Read CPU usage line
    char line[1024];
    if (fgets(line, sizeof(line), proc_stat) == NULL) {
        perror("fgets");
        exit(1);
    }

    // Parse CPU usage
    int user, nice, system, idle, iowait, irq, softirq;
    if (sscanf(line, "cpu  %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq) != 7) {
        fprintf(stderr, "sscanf failed: %s\n", line);
        exit(1);
    }

    // Close /proc/stat
    fclose(proc_stat);

    // Calculate CPU usage
    double total_time = user + nice + system + idle + iowait + irq + softirq;
    double cpu_usage = 100.0 * (total_time - idle) / total_time;

    return cpu_usage;
}