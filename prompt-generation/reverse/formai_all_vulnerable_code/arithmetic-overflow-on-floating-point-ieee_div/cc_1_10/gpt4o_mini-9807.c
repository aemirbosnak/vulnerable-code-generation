//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define INTERVAL 1
#define CPU_INFO_FILE "/proc/stat"

void get_cpu_times(long long *user, long long *nice, long long *system,
                   long long *idle, long long *iowait, long long *irq,
                   long long *softirq, long long *steal, long long *guest,
                   long long *guest_nice) {
    FILE *fp = fopen(CPU_INFO_FILE, "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), fp); // Read the first line which contains the CPU info

    sscanf(buffer, "cpu %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",
           user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice);

    fclose(fp);
}

long long calculate_cpu_usage(long long total_time1, long long total_time2) {
    return (total_time2 - total_time1);
}

int main() {
    long long user1, nice1, system1, idle1, iowait1, irq1, softirq1, steal1, guest1, guest_nice1;
    long long user2, nice2, system2, idle2, iowait2, irq2, softirq2, steal2, guest2, guest_nice2;

    while (1) {
        // Get CPU times at first interval
        get_cpu_times(&user1, &nice1, &system1, &idle1, &iowait1, &irq1, 
                       &softirq1, &steal1, &guest1, &guest_nice1);
        sleep(INTERVAL);
        // Get CPU times after interval
        get_cpu_times(&user2, &nice2, &system2, &idle2, &iowait2, &irq2, 
                       &softirq2, &steal2, &guest2, &guest_nice2);

        long long total1 = user1 + nice1 + system1 + idle1 + iowait1 + 
                           irq1 + softirq1 + steal1 + guest1 + guest_nice1;
        long long total2 = user2 + nice2 + system2 + idle2 + iowait2 + 
                           irq2 + softirq2 + steal2 + guest2 + guest_nice2;

        long long idle_diff = (idle2 - idle1);
        long long total_diff = (total2 - total1);

        double cpu_usage = 100.0 * (total_diff - idle_diff) / total_diff;

        // Print results
        printf("CPU Usage: %.2f%%\n", cpu_usage);
        fflush(stdout);
    }

    return 0;
}