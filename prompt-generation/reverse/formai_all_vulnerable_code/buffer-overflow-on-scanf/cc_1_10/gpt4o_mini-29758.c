//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

void display_memory_usage() {
    FILE *meminfo;
    char buffer[BUFFER_SIZE];

    meminfo = fopen("/proc/meminfo", "r");
    if (meminfo == NULL) {
        perror("Could not open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    printf("Memory Usage:\n");
    while (fgets(buffer, BUFFER_SIZE, meminfo)) {
        if (strstr(buffer, "MemTotal") || strstr(buffer, "MemFree") ||
            strstr(buffer, "Buffers") || strstr(buffer, "Cached") ||
            strstr(buffer, "SwapTotal") || strstr(buffer, "SwapFree")) {
            printf("%s", buffer);
        }
    }
    fclose(meminfo);
}

void calculate_and_display_usage() {
    FILE *meminfo;
    char buffer[BUFFER_SIZE];
    long memTotal = 0, memFree = 0, buffers = 0, cached = 0;

    meminfo = fopen("/proc/meminfo", "r");
    if (meminfo == NULL) {
        perror("Could not open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, BUFFER_SIZE, meminfo)) {
        if (strstr(buffer, "MemTotal")) {
            sscanf(buffer, "MemTotal: %ld kB", &memTotal);
        } else if (strstr(buffer, "MemFree")) {
            sscanf(buffer, "MemFree: %ld kB", &memFree);
        } else if (strstr(buffer, "Buffers")) {
            sscanf(buffer, "Buffers: %ld kB", &buffers);
        } else if (strstr(buffer, "Cached")) {
            sscanf(buffer, "Cached: %ld kB", &cached);
        }
    }
    fclose(meminfo);

    long usedMemory = memTotal - memFree - buffers - cached;
    float usedMemoryPercent = ((float)usedMemory / (float)memTotal) * 100;

    printf("Used Memory: %ld kB (%.2f%%)\n", usedMemory, usedMemoryPercent);
}

int main() {
    int choice;
    while (1) {
        printf("\n=== RAM Usage Monitor ===\n");
        printf("1. Display Memory Usage\n");
        printf("2. Calculate and Display Used Memory\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_memory_usage();
                break;
            case 2:
                calculate_and_display_usage();
                break;
            case 3:
                printf("Exiting RAM Usage Monitor. Goodbye!\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
        sleep(2); // Wait 2 seconds before showing the menu again
    }

    return 0;
}