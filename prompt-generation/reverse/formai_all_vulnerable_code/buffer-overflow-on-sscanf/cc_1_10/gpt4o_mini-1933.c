//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void get_memory_usage(long *total, long *free, long *available) {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %ld kB", total) == 1) {
            continue;
        } else if (sscanf(line, "MemFree: %ld kB", free) == 1) {
            continue;
        } else if (sscanf(line, "MemAvailable: %ld kB", available) == 1) {
            continue;
        }
    }
    
    fclose(file);
}

void print_memory_usage() {
    long total = 0, free = 0, available = 0;
    get_memory_usage(&total, &free, &available);

    long used = total - free;

    printf("Total Memory: %ld kB\n", total);
    printf("Free Memory: %ld kB\n", free);
    printf("Used Memory: %ld kB\n", used);
    printf("Available Memory: %ld kB\n", available);
    printf("---------------------------------------\n");
}

int main() {
    printf("RAM Usage Monitor\n");
    printf("-------------------\n");
    
    while (1) {
        print_memory_usage();
        printf("\n");
        sleep(1); // Sleep for 1 second before updating the information
    }

    return 0;
}