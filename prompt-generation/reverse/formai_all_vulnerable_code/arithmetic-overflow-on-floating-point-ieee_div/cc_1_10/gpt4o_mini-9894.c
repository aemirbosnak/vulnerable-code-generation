//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

void get_cpu_times(long long *user, long long *nice, long long *system, 
                   long long *idle, long long *iowait, long long *irq, 
                   long long *softirq, long long *steal, long long *guest, 
                   long long *guest_nice) {
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        sscanf(buffer, "cpu %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",
               user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice);
    } else {
        perror("Failed to read CPU data");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    fclose(fp);
}

double calculate_cpu_usage(long long prev_total, long long prev_idle, 
                            long long total, long long idle) {
    long long total_diff = total - prev_total;
    long long idle_diff = idle - prev_idle;
    return (1.0 - (double)idle_diff / (double)total_diff) * 100.0;
}

int main() {
    long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    long long prev_user, prev_nice, prev_system, prev_idle, prev_iowait, prev_irq, prev_softirq, prev_steal, prev_guest, prev_guest_nice;
    long long total, prev_total;

    // Get initial CPU times
    get_cpu_times(&prev_user, &prev_nice, &prev_system, &prev_idle, 
                   &prev_iowait, &prev_irq, &prev_softirq, &prev_steal, 
                   &prev_guest, &prev_guest_nice);
    prev_total = prev_user + prev_nice + prev_system + prev_idle + 
                  prev_iowait + prev_irq + prev_softirq + prev_steal + 
                  prev_guest + prev_guest_nice;

    while (1) {
        // Sleep for 1 second before measuring again
        sleep(1);

        // Get current CPU times
        get_cpu_times(&user, &nice, &system, &idle, &iowait, &irq, 
                       &softirq, &steal, &guest, &guest_nice);
        total = user + nice + system + idle + iowait + irq + softirq + 
                steal + guest + guest_nice;

        // Calculate the CPU Usage
        double cpu_usage = calculate_cpu_usage(prev_total, prev_idle, total, idle);

        // Print the CPU usage
        printf("CPU Usage: %.2f%%\n", cpu_usage);

        // Update previous values for the next iteration
        prev_user = user;
        prev_nice = nice;
        prev_system = system;
        prev_idle = idle;
        prev_iowait = iowait;
        prev_irq = irq;
        prev_softirq = softirq;
        prev_steal = steal;
        prev_guest = guest;
        prev_guest_nice = guest_nice;
        prev_total = total;
    }

    return 0;
}