//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SLEEP_TIME 2

void displayMemoryUsage() {
    FILE *file;
    char buffer[256];
    long total_memory = 0, free_memory = 0, used_memory = 0;

    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        if (sscanf(buffer, "MemTotal: %ld kB", &total_memory) == 1) {
            continue;
        }
        if (sscanf(buffer, "MemFree: %ld kB", &free_memory) == 1) {
            continue;
        }
    }
    fclose(file);

    used_memory = total_memory - free_memory;

    float used_memory_percent = ((float)used_memory / total_memory) * 100;

    // Clear the terminal for neat output!
    printf("\033[H\033[J"); // ANSI escape codes to clear the screen
    
    // Print Memory Statistics
    printf("🏗️ Memory Usage Monitor 🏗️\n");
    printf("==========================\n");
    printf("Total Memory: %ld kB\n", total_memory);
    printf("Free Memory: %ld kB\n", free_memory);
    printf("Used Memory: %ld kB (%.2f%% used)\n", used_memory, used_memory_percent);
    printf("==========================\n");
}

int main() {
    printf("🚀 Welcome to the Awesome RAM Usage Monitor! 🚀\n");
    printf("Your computer's memory is about to be closely watched!\n");
    
    while (1) {
        displayMemoryUsage();
        sleep(SLEEP_TIME); // Sleep for a while to get updated memory info
    }

    return 0; // This line will never be reached
}