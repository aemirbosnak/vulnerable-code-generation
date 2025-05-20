//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define BUF_SIZE 256

void get_cpu_usage() {
    FILE *fp;
    char buffer[BUF_SIZE];
    
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        return;
    }

    // Read the first line of /proc/stat
    fgets(buffer, BUF_SIZE, fp);
    fclose(fp);
    
    // Parse CPU usage data
    char cpu[5];
    long user, nice, system, idle;
    sscanf(buffer, "%s %ld %ld %ld %ld", cpu, &user, &nice, &system, &idle);
    
    long total_cpu_time = user + nice + system + idle;
    long total_idle_time = idle;

    printf("CPU usage:\n");
    printf("Total CPU time: %ld\n", total_cpu_time);
    printf("Total Idle time: %ld\n", total_idle_time);
}

void get_memory_usage() {
    struct sysinfo memInfo;
    sysinfo(&memInfo);

    unsigned long total_ram = memInfo.totalram;
    unsigned long free_ram = memInfo.freeram;

    printf("Memory usage:\n");
    printf("Total RAM: %lu MB\n", total_ram / (1024 * 1024));
    printf("Free RAM: %lu MB\n", free_ram / (1024 * 1024));

    unsigned long used_ram = total_ram - free_ram;
    printf("Used RAM: %lu MB\n", used_ram / (1024 * 1024));
}

void get_uptime() {
    struct sysinfo memInfo;
    sysinfo(&memInfo);
    
    printf("System uptime: %ld seconds\n", memInfo.uptime);
}

void display_system_info() {
    printf("=== System Resource Monitor ===\n");
    get_cpu_usage();
    printf("\n");
    get_memory_usage();
    printf("\n");
    get_uptime();
    printf("==============================\n");
}

int main() {
    while (1) {
        display_system_info();
        sleep(5); // Wait for 5 seconds before refreshing
    }
    return 0;
}