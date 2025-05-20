//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void get_memory_usage(double *total, double *free, double *used) {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Unable to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %lf kB", total) == 1) {
            *total /= 1024; // Convert kB to MB
        } else if (sscanf(line, "MemFree: %lf kB", free) == 1) {
            *free /= 1024; // Convert kB to MB
        } else if (sscanf(line, "MemAvailable: %lf kB", free) == 1) {
            *free /= 1024; // Convert kB to MB
        }
    }
    fclose(file);
    *used = *total - *free;
}

void display_memory_usage() {
    double total_memory, free_memory, used_memory;
    get_memory_usage(&total_memory, &free_memory, &used_memory);

    printf("+-------------------+\n");
    printf("| Memory Usage      |\n");
    printf("+-------------------+\n");
    printf("| Total Memory: %.2f MB |\n", total_memory);
    printf("| Free Memory:  %.2f MB |\n", free_memory);
    printf("| Used Memory:  %.2f MB |\n", used_memory);
    printf("+-------------------+\n");
}

void monitoring_loop() {
    while (1) {
        display_memory_usage();
        printf("Press Ctrl+C to exit...\n");

        // Clear the terminal and refresh every 1 second
        sleep(1);
        printf("\033[H\033[J");  // ANSI escape code to clear the screen
    }
}

int main() {
    printf("RAM Usage Monitor v1.0\n");
    printf("------------------------\n");
    monitoring_loop();
    return 0;
}