//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

void parse_memory_info(unsigned long *total, unsigned long *free, unsigned long *available) {
    FILE *meminfo = fopen("/proc/meminfo", "r");
    if (meminfo == NULL) {
        perror("Could not open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, meminfo)) {
        if (sscanf(buffer, "MemTotal: %lu kB", total)) continue;
        if (sscanf(buffer, "MemFree: %lu kB", free)) continue;
        if (sscanf(buffer, "MemAvailable: %lu kB", available)) continue;
    }

    fclose(meminfo);
}

void display_memory_usage() {
    unsigned long total, free, available;

    parse_memory_info(&total, &free, &available);

    unsigned long used = total - free;

    printf("Memory Usage Statistics:\n");
    printf("------------------------\n");
    printf("Total Memory:      %lu kB\n", total);
    printf("Free Memory:       %lu kB\n", free);
    printf("Used Memory:       %lu kB\n", used);
    printf("Available Memory:  %lu kB\n", available);
    printf("------------------------\n");
    
    double usage_percent = (double) used / total * 100;
    printf("Memory Usage Percent: %.2f%%\n", usage_percent);
}

void monitor_memory_usage(int interval) {
    while (1) {
        system("clear");
        display_memory_usage();
        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    int interval = 2; // Default to 2 seconds
    if (argc > 1) {
        interval = atoi(argv[1]);
        if (interval <= 0) {
            fprintf(stderr, "Interval must be a positive integer.\n");
            return EXIT_FAILURE;
        }
    }

    printf("Starting RAM Usage Monitor every %d seconds...\n", interval);
    monitor_memory_usage(interval);

    return 0;
}