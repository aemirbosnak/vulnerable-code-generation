//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

// A noble function to summon the spirit of CPU statistics
void summon_cpu_stats(long *user, long *nice, long *system, long *idle, long *iowait, long *irq, long *softirq) {
    FILE *file = fopen("/proc/stat", "r");
    if (file == NULL) {
        perror("Alas! The file of stats could not be opened!");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, file);
    fclose(file);

    // Parse the data as if deciphering an ancient scroll.
    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld", user, nice, system, idle, iowait, irq, softirq);
}

// A noble function to calculate the current CPU usage
void calculate_cpu_usage(long *last_idle, long *last_total) {
    long user, nice, system, idle, iowait, irq, softirq;
    
    // Summon the new stats
    long current_idle = 0;
    long current_total = 0;

    summon_cpu_stats(&user, &nice, &system, &idle, &iowait, &irq, &softirq);

    // The total and idle time be summoned from the depths of the CPU statistics!
    current_idle = idle + iowait;
    current_total = user + nice + system + current_idle + irq + softirq;

    // Bestowing the current values unto the last values
    *last_idle = current_idle;
    *last_total = current_total;
}

// A noble function to print the tale of the CPU usage
void print_cpu_usage(long last_idle, long last_total) {
    long user, nice, system, idle, iowait, irq, softirq;

    // Summon the new stats once again
    summon_cpu_stats(&user, &nice, &system, &idle, &iowait, &irq, &softirq);
    
    long current_idle = idle + iowait;
    long current_total = user + nice + system + current_idle + irq + softirq;

    // Compute the difference in time
    long idle_diff = current_idle - last_idle;
    long total_diff = current_total - last_total;

    float cpu_usage = (1.0f - (float)idle_diff / total_diff) * 100.0f; 

    // Bestow upon the townsfolk the tale of CPU usage
    printf("Hark! The CPU hath been used: %.2f%%\n", cpu_usage);
}

int main() {
    long last_idle = 0, last_total = 0;
    // First invocation to conjure the prior state of the CPU
    summon_cpu_stats(&(long){0}, &(long){0}, &(long){0}, &(long){0}, &(long){0}, &(long){0}, &(long){0});
    calculate_cpu_usage(&last_idle, &last_total);

    while (1) {
        // Let time flow as the sands in an hourglass
        sleep(1);

        // Unveil the current CPU usage before the townsfolk
        print_cpu_usage(last_idle, last_total);
    }
    
    return 0;
}