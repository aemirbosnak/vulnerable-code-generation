//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

#define MEM_BUF_SIZE 128

void print_memory_usage() {
    struct sysinfo si;
    FILE* fp;
    char line[MEM_BUF_SIZE], field[MEM_BUF_SIZE], value[MEM_BUF_SIZE];
    long mem_total, mem_free, mem_cached, mem_available;

    // Get system information
    sysinfo(&si);

    // Get memory information from /proc/meminfo
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        return;
    }

    while (fgets(line, MEM_BUF_SIZE, fp)) {
        sscanf(line, "%s %s", field, value);
        if (strcmp(field, "MemTotal:") == 0) {
            mem_total = strtol(value, NULL, 10);
        } else if (strcmp(field, "MemFree:") == 0) {
            mem_free = strtol(value, NULL, 10);
        } else if (strcmp(field, "Cached:") == 0) {
            mem_cached = strtol(value, NULL, 10);
        } else if (strcmp(field, "MemAvailable:") == 0) {
            mem_available = strtol(value, NULL, 10);
        }
    }
    fclose(fp);

    // Calculate memory usage percentage
    long mem_used = mem_total - (mem_free + mem_cached + mem_available);
    double mem_percent = (double) mem_used / (double) mem_total * 100.0;

    // Print memory usage statistics
    printf("Total memory: %lu KB\n", mem_total);
    printf("Free memory: %lu KB\n", mem_free);
    printf("Cached memory: %lu KB\n", mem_cached);
    printf("Available memory: %lu KB\n", mem_available);
    printf("Used memory: %lu KB (%.2f%%)\n", mem_used, mem_percent);
}

int main() {
    while(1) {
        print_memory_usage();
        sleep(10);
    }
    return 0;
}