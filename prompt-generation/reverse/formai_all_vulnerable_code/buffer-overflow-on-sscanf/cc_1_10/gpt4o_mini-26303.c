//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LEN 256

void get_memory_info(long *total, long *free, long *available, long *buffers, long *cached) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Unable to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LEN];
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %ld kB", total) == 1) continue;
        if (sscanf(line, "MemFree: %ld kB", free) == 1) continue;
        if (sscanf(line, "MemAvailable: %ld kB", available) == 1) continue;
        if (sscanf(line, "Buffers: %ld kB", buffers) == 1) continue;
        if (sscanf(line, "Cached: %ld kB", cached) == 1) continue;
    }
    
    fclose(fp);
}

void display_memory_usage(long total, long free, long available, long buffers, long cached) {
    long used = total - free;
    long effective_used = used - (buffers + cached);
    
    printf("\n");
    printf("Total RAM: %ld kB\n", total);
    printf("Free RAM: %ld kB\n", free);
    printf("Available RAM: %ld kB\n", available);
    printf("Buffers: %ld kB\n", buffers);
    printf("Cached: %ld kB\n", cached);
    printf("Used RAM: %ld kB\n", used);
    printf("Effective Used RAM: %ld kB\n", effective_used);
    
    // Visual representation
    int total_bar = total / 1024;      // Convert to MB
    int used_bar = used / 1024;        // Convert to MB
    int available_bar = available / 1024; // Convert to MB
    int effective_used_bar = effective_used / 1024; // Convert to MB

    printf("\nMemory Usage (in MB):\n");
    printf("Total: [%s%*s]\n", "=", total_bar, "");
    printf("Used:  [%s%*s]\n", "=", used_bar, "");
    printf("Free:  [%s%*s]\n", "=", available_bar, "");
    printf("Buffers/Cached: [%s%*s]\n", "=", effective_used_bar, "");

    fflush(stdout);
}

int main() {
    long total, free, available, buffers, cached;
    
    while (1) {
        get_memory_info(&total, &free, &available, &buffers, &cached);
        display_memory_usage(total, free, available, buffers, cached);
        sleep(1); // Update every second
    }
    
    return 0;
}