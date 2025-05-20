//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define SLEEP_INTERVAL 3

void clear_screen() {
    printf("\033[H\033[J");  // ANSI escape code to clear screen
}

void show_memory_usage() {
    FILE *file;
    char buffer[BUFFER_SIZE];
    unsigned long total = 0, free = 0, used = 0, cached = 0;

    // Read memory info from /proc/meminfo
    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(1);
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (sscanf(buffer, "MemTotal: %lu kB", &total) == 1)
            continue;
        if (sscanf(buffer, "MemFree: %lu kB", &free) == 1)
            continue;
        if (sscanf(buffer, "Cached: %lu kB", &cached) == 1)
            continue;
    }
    
    fclose(file);
    
    used = total - free - cached;

    printf("Total Memory: %lu kB\n", total);
    printf("Free Memory: %lu kB\n", free);
    printf("Used Memory: %lu kB\n", used);
    printf("Cached Memory: %lu kB\n", cached);
    printf("------------------------\n");
}

void display_graphical_memory_usage(unsigned long used, unsigned long total) {
    float used_percent = ((float)used / (float)total) * 100;
    int bars = (int)(used_percent / 2);  // 50% is the max for 100 chars width
    
    printf("Memory Usage: [");
    for (int i = 0; i < 50; i++) {
        if (i < bars) {
            printf("#");
        } else {
            printf(" ");
        }
    }
    printf("] %.2f%%\n", used_percent);
}

int main() {
    clear_screen();
    printf("Simple C RAM Usage Monitor\n");
    printf("------------------------\n");

    while (1) {
        unsigned long total = 0, free = 0, used = 0;
        
        FILE *file;
        char buffer[BUFFER_SIZE];
        
        file = fopen("/proc/meminfo", "r");
        if (file == NULL) {
            perror("Failed to open /proc/meminfo");
            exit(1);
        }

        while (fgets(buffer, BUFFER_SIZE, file)) {
            if (sscanf(buffer, "MemTotal: %lu kB", &total) == 1)
                continue;
            if (sscanf(buffer, "MemFree: %lu kB", &free) == 1)
                continue;
        }
        
        fclose(file);
        
        used = total - free;

        show_memory_usage();
        display_graphical_memory_usage(used, total);

        sleep(SLEEP_INTERVAL);
        clear_screen();
    }

    return 0;
}