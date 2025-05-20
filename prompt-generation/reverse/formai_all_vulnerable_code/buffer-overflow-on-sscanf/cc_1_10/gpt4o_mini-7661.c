//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void display_memory_usage() {
    FILE *file;
    char line[256];
    long total_mem = 0, free_mem = 0, buffer_mem = 0, cached_mem = 0;

    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Could not open /proc/meminfo");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %ld kB", &total_mem) == 1) {
            // Total memory captured!
        } else if (sscanf(line, "MemFree: %ld kB", &free_mem) == 1) {
            // Free memory captured!
        } else if (sscanf(line, "Buffers: %ld kB", &buffer_mem) == 1) {
            // Buffer memory captured!
        } else if (sscanf(line, "Cached: %ld kB", &cached_mem) == 1) {
            // Cached memory captured!
        }
    }
    fclose(file);

    long used_mem = total_mem - free_mem - buffer_mem - cached_mem;
    long mem_percentage = (used_mem * 100) / total_mem;

    // Clear the terminal screen
    printf("\033[H\033[J");

    // Cheerful display
    printf("🎉🎉 Welcome to the Cheerful RAM Usage Monitor! 🎉🎉\n");
    printf("-----------------------------------------------\n");
    printf("Total Memory:        %ld kB\n", total_mem);
    printf("Free Memory:         %ld kB\n", free_mem);
    printf("Used Memory:         %ld kB\n", used_mem);
    printf("Buffers:             %ld kB\n", buffer_mem);
    printf("Cached:              %ld kB\n", cached_mem);
    printf("\n");
    
    printf("Memory Usage:        %ld%%\n", mem_percentage);
    printf("-----------------------------------------------\n");

    if (mem_percentage < 50) {
        printf("🎈 You're a memory champ! Keep it up! 🎈\n");
    } else if (mem_percentage < 80) {
        printf("😊 Memory usage is moderate. All is well! 😊\n");
    } else {
        printf("😱 Oh no! Memory usage is quite high! Time to tidy up! 😱\n");
    }
    
    printf("-----------------------------------------------\n");
}

int main() {
    while (1) {
        display_memory_usage();
        // Sleep for 2 seconds before updating the view
        sleep(2);
    }
    return 0;
}