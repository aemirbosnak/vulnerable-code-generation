//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

void get_cpu_times(long *user, long *nice, long *system, long *idle, long *iowait, long *irq, long *softirq) {
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Could not open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    if (fgets(buffer, BUFFER_SIZE, fp) == NULL) {
        perror("Failed to read from /proc/stat");
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    fclose(fp);
    
    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld",
           user, nice, system, idle, iowait, irq, softirq);
}

void calculate_cpu_usage(long prev_user, long prev_nice, long prev_system, long prev_idle, long prev_iowait, long prev_irq, long prev_softirq,
                          long curr_user, long curr_nice, long curr_system, long curr_idle, long curr_iowait, long curr_irq, long curr_softirq) {
    long total_prev = prev_user + prev_nice + prev_system + prev_idle + prev_iowait + prev_irq + prev_softirq;
    long total_curr = curr_user + curr_nice + curr_system + curr_idle + curr_iowait + curr_irq + curr_softirq;

    long total_diff = total_curr - total_prev;
    long idle_diff = curr_idle - prev_idle;

    double usage = ((double)(total_diff - idle_diff) / total_diff) * 100.0;
    printf("CPU Usage: %.2f%%\n", usage);
}

int main() {
    printf("Starting CPU Usage Monitor...\n");
    long user, nice, system, idle, iowait, irq, softirq;
    long prev_user, prev_nice, prev_system, prev_idle, prev_iowait, prev_irq, prev_softirq;

    get_cpu_times(&prev_user, &prev_nice, &prev_system, &prev_idle, &prev_iowait, &prev_irq, &prev_softirq);

    while (1) {
        sleep(1); // sleep for 1 second
        
        get_cpu_times(&user, &nice, &system, &idle, &iowait, &irq, &softirq);

        calculate_cpu_usage(prev_user, prev_nice, prev_system, prev_idle, prev_iowait, prev_irq, prev_softirq,
                             user, nice, system, idle, iowait, irq, softirq);
        
        // Update previous values for next measurement
        prev_user = user;
        prev_nice = nice;
        prev_system = system;
        prev_idle = idle;
        prev_iowait = iowait;
        prev_irq = irq;
        prev_softirq = softirq;
    }

    return 0;
}