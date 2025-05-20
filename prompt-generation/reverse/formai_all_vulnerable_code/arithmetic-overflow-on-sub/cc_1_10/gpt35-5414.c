//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/statvfs.h>

int main(void) {
    int cpuUsage; 
    long memoryUsage; 
    struct statvfs vfs;
    
    printf("CPU Usage Monitor\n");

    while (1) {
        // Read CPU usage
        FILE* fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            printf("Failed to read CPU usage\n");
            break;
        }
        int reads;
        int cpu, user, nice, sys, idle, iowait, irq, softirq, steal, guest, guest_nice;
        reads = fscanf(fp, "cpu %d %d %d %d %d %d %d %d %d %d", &cpu, &user, &nice, &sys, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
        fclose(fp);
        if (reads != 11) {
            printf("Failed to read CPU usage\n");
            break;
        }
        int prevIdle = idle;
        int prevNonIdle = user + nice + sys + irq + softirq + steal;
        int prevTotal = prevIdle + prevNonIdle;
        sleep(1);
        fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            printf("Failed to read CPU usage\n");
            break;
        }
        reads = fscanf(fp, "cpu %d %d %d %d %d %d %d %d %d %d", &cpu, &user, &nice, &sys, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
        fclose(fp);
        if (reads != 11) {
            printf("Failed to read CPU usage\n");
            break;
        }
        int idle_time = idle - prevIdle;
        int non_idle_time = (user + nice + sys + irq + softirq + steal) - prevNonIdle;
        int total_time = idle_time + non_idle_time;
        cpuUsage = (100 * non_idle_time) / total_time;

        // Read memory usage
        if (statvfs("/", &vfs)) {
            printf("Failed to read memory usage\n");
            break;
        }
        memoryUsage = ((vfs.f_blocks - vfs.f_bfree) * vfs.f_frsize) / (1024 * 1024);

        printf("CPU Usage: %d%%, Memory Usage: %ld MB\n", cpuUsage, memoryUsage);
    }

    return 0;
}