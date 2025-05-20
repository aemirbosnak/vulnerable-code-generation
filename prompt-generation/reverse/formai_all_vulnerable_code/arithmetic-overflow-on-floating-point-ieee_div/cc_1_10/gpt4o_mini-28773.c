//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

// Function to get CPU usage
void get_cpu_usage() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        return;
    }

    if (fgets(line, sizeof(line), fp) != NULL) {
        char cpu[5];
        long user, nice, system, idle;
        sscanf(line, "%s %ld %ld %ld %ld", cpu, &user, &nice, &system, &idle);
        long total = user + nice + system + idle;
        printf("CPU Usage: %.2f%%\n", (float)(total - idle) / total * 100);
    } else {
        perror("Error reading CPU info");
    }
    
    fclose(fp);
}

// Function to get memory usage
void get_memory_usage() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    long total_memory = 0, free_memory = 0;

    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Error opening /proc/meminfo");
        return;
    }

    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %ld kB", &total_memory) == 1) {
            continue;
        }
        if (sscanf(line, "MemFree: %ld kB", &free_memory) == 1) {
            break;
        }
    }

    printf("Memory Usage: %.2f%%\n", (float)(total_memory - free_memory) / total_memory * 100);
    
    fclose(fp);
}

// Function to get disk usage
void get_disk_usage() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];

    fp = popen("df -h /", "r");
    if (fp == NULL) {
        perror("Error executing df command");
        return;
    }

    // Skip the first line of headers
    fgets(line, sizeof(line), fp);
    if (fgets(line, sizeof(line), fp) != NULL) {
        char filesystem[20], size[10], used[10], avail[10], use_percentage[10], mounted_on[20];
        sscanf(line, "%s %s %s %s %s %s", filesystem, size, used, avail, use_percentage, mounted_on);
        printf("Disk Usage:\n");
        printf("Filesystems: %s\nSize: %s Used: %s Available: %s Usage: %s Mounted on: %s\n",
               filesystem, size, used, avail, use_percentage, mounted_on);
    }

    pclose(fp);
}

// Main function
int main() {
    printf("System Monitor\n");
    printf("====================\n");

    get_cpu_usage();
    get_memory_usage();
    get_disk_usage();

    printf("====================\n");
    return 0;
}