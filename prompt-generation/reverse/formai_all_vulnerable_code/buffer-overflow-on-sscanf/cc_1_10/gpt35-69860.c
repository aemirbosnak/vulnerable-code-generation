//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: modular
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>

#define INTERVAL 1

struct sys_stats {
    unsigned long long memory_total;
    unsigned long long memory_free;
    unsigned long long memory_used;
};

void get_sys_stats(struct sys_stats *stats) {
    FILE *fp;
    unsigned long long free_memory;
    char buffer[1024];

    fp = fopen("/proc/meminfo", "r");
    if(fp == NULL) {
        perror("fopen()");
        exit(1);
    }

    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "MemTotal: %llu kB\n", &stats->memory_total);

    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "MemFree: %llu kB\n", &free_memory);

    fclose(fp);

    stats->memory_free = free_memory * 1024; // Convert to bytes
    stats->memory_used = stats->memory_total - stats->memory_free;
}

void print_sys_stats(struct sys_stats *stats) {
    printf("Total Memory: %llu\n", stats->memory_total);
    printf("Free Memory: %llu\n", stats->memory_free);
    printf("Used Memory: %llu\n", stats->memory_used);
}

int main() {
    struct sys_stats stats;

    while(1) {
        get_sys_stats(&stats);
        print_sys_stats(&stats);
        sleep(INTERVAL);
    }

    return 0;
}