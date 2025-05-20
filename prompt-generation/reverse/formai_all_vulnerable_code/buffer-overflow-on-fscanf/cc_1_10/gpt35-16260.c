//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/statvfs.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

typedef struct cpu_info {
    unsigned long long int user;
    unsigned long long int nice;
    unsigned long long int system;
    unsigned long long int idle;
    unsigned long long int iowait;
    unsigned long long int irq;
    unsigned long long int softirq;
} CPUInfo;

int main() {
    // Calculate CPU usage every second for 10 seconds
    int num_seconds = 10;
    int num_samples = num_seconds;
    int sample_time_usec = 1000000; // 1 second

    CPUInfo initial_cpu_info, current_cpu_info, diff_cpu_info, previous_diff_cpu_info;
    memset(&initial_cpu_info, 0, sizeof(CPUInfo));
    memset(&current_cpu_info, 0, sizeof(CPUInfo));
    memset(&diff_cpu_info, 0, sizeof(CPUInfo));
    memset(&previous_diff_cpu_info, 0, sizeof(CPUInfo));

    FILE* fp = fopen("/proc/stat", "r");
    fscanf(fp, "cpu %llu %llu %llu %llu %llu %llu %llu", &initial_cpu_info.user, &initial_cpu_info.nice, &initial_cpu_info.system, &initial_cpu_info.idle, &initial_cpu_info.iowait, &initial_cpu_info.irq, &initial_cpu_info.softirq);
    fclose(fp);
    printf("Initializing CPU usage monitor...\n");

    for (int i = 0; i < num_samples; i++) {
        usleep(sample_time_usec);

        fp = fopen("/proc/stat", "r");
        fscanf(fp, "cpu %llu %llu %llu %llu %llu %llu %llu", &current_cpu_info.user, &current_cpu_info.nice, &current_cpu_info.system, &current_cpu_info.idle, &current_cpu_info.iowait, &current_cpu_info.irq, &current_cpu_info.softirq);
        fclose(fp);

        diff_cpu_info.user = current_cpu_info.user - initial_cpu_info.user;
        diff_cpu_info.nice = current_cpu_info.nice - initial_cpu_info.nice;
        diff_cpu_info.system = current_cpu_info.system - initial_cpu_info.system;
        diff_cpu_info.idle = current_cpu_info.idle - initial_cpu_info.idle;
        diff_cpu_info.iowait = current_cpu_info.iowait - initial_cpu_info.iowait;
        diff_cpu_info.irq = current_cpu_info.irq - initial_cpu_info.irq;
        diff_cpu_info.softirq = current_cpu_info.softirq - initial_cpu_info.softirq;

        unsigned long long int total_cpu_diff = diff_cpu_info.user + diff_cpu_info.nice + diff_cpu_info.system + diff_cpu_info.idle + diff_cpu_info.iowait + diff_cpu_info.irq + diff_cpu_info.softirq;
        float cpu_percentage = ((float)(total_cpu_diff - diff_cpu_info.idle) / (float)total_cpu_diff) * 100.0;
        printf("CPU usage: %.2f%%\n", cpu_percentage);

        previous_diff_cpu_info = diff_cpu_info;
        initial_cpu_info = current_cpu_info;
    }

    return 0;
}