//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define NUM_CORES 4
#define SAMPLE_INTERVAL 1

struct cpu_usage {
    long utime;  // user time
    long stime;  // system time
};

void read_cpu_usage(struct cpu_usage *usage) {
    FILE *fp;
    char buffer[256];
    int core;
    
    memset(usage, 0, sizeof(struct cpu_usage)); // Initialize to zero
    
    fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Failed to open /proc/stat");
        return;
    }

    // Read line starting with "cpu"
    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer + 4, "%ld %ld", &usage->utime, &usage->stime);

    fclose(fp);
}

void display_usage(double usage) {
    printf("CPU Usage: %.2f%%\n", usage);
}

int main() {
    struct cpu_usage usage_prev, usage_curr;
    double cpu_usage_percentage;

    read_cpu_usage(&usage_prev);

    while (1) {
        sleep(SAMPLE_INTERVAL);
        read_cpu_usage(&usage_curr);

        long total_prev = usage_prev.utime + usage_prev.stime;
        long total_curr = usage_curr.utime + usage_curr.stime;

        // Calculate the difference
        long diff_utime = usage_curr.utime - usage_prev.utime;
        long diff_stime = usage_curr.stime - usage_prev.stime;
        long total_diff = total_curr - total_prev;

        // Avoid division by zero
        if (total_diff > 0) {
            cpu_usage_percentage = ((double)(diff_utime + diff_stime) / total_diff) * 100.0;
        } else {
            cpu_usage_percentage = 0.0; // If no change, usage is zero
        }

        display_usage(cpu_usage_percentage);

        // Update previous usage
        usage_prev = usage_curr;
    }

    return 0;
}