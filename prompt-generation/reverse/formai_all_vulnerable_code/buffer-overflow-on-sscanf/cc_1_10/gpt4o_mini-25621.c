//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define SLEEP_INTERVAL 1

void read_cpu_time(long long *user, long long *nice, long long *system, long long *idle, long long *iowait, long long *irq, long long *softirq) {
    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        exit(EXIT_FAILURE);
    }
    
    char line[MAX_LINE_LENGTH];
    if (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "cpu %lld %lld %lld %lld %lld %lld %lld", user, nice, system, idle, iowait, irq, softirq);
    }

    fclose(fp);
}

long long calculate_cpu_usage(long long total_user, long long total_nice, long long total_system, long long total_idle, long long total_iowait, long long total_irq, long long total_softirq) {
    long long total = total_user + total_nice + total_system + total_idle + total_iowait + total_irq + total_softirq;
    long long idle_time = total_idle + total_iowait;

    return 100 * (1 - (double)idle_time / total);
}

void display_cpu_usage() {
    long long prev_user, prev_nice, prev_system, prev_idle, prev_iowait, prev_irq, prev_softirq;
    long long curr_user, curr_nice, curr_system, curr_idle, curr_iowait, curr_irq, curr_softirq;

    read_cpu_time(&prev_user, &prev_nice, &prev_system, &prev_idle, &prev_iowait, &prev_irq, &prev_softirq);

    while (1) {
        sleep(SLEEP_INTERVAL);
        read_cpu_time(&curr_user, &curr_nice, &curr_system, &curr_idle, &curr_iowait, &curr_irq, &curr_softirq);
        
        long long total_prev = prev_user + prev_nice + prev_system + prev_idle + prev_iowait + prev_irq + prev_softirq;
        long long total_curr = curr_user + curr_nice + curr_system + curr_idle + curr_iowait + curr_irq + curr_softirq;

        long long total_diff = total_curr - total_prev;
        long long idle_diff = (curr_idle + curr_iowait) - (prev_idle + prev_iowait);

        double cpu_usage = 100.0 * (total_diff - idle_diff) / total_diff;

        printf("CPU Usage: %.2f%%\n", cpu_usage);

        prev_user = curr_user;
        prev_nice = curr_nice;
        prev_system = curr_system;
        prev_idle = curr_idle;
        prev_iowait = curr_iowait;
        prev_irq = curr_irq;
        prev_softirq = curr_softirq;
    }
}

int main() {
    printf("Starting CPU Usage Monitor...\n");
    display_cpu_usage();
    return 0;
}