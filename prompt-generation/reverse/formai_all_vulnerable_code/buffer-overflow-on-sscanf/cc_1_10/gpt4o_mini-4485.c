//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

void display_memory_info() {
    FILE *file;
    char buffer[BUFFER_SIZE];
    long total_memory = 0, free_memory = 0, used_memory = 0;

    // Open the meminfo file
    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    // Read memory info from the file
    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (sscanf(buffer, "MemTotal: %ld kB", &total_memory) == 1) {
            // Successfully read total memory
        } else if (sscanf(buffer, "MemFree: %ld kB", &free_memory) == 1) {
            // Successfully read free memory
        }
    }
    
    fclose(file);
    
    // Calculate used memory
    used_memory = total_memory - free_memory;

    // Display the results in an exciting format
    printf("\n=========================\n");
    printf("🚀 RAM Usage Monitor 🚀\n");
    printf("=========================\n");
    printf("📊 Total Memory: %ld kB\n", total_memory);
    printf("🆓 Free Memory:  %ld kB\n", free_memory);
    printf("🔥 Used Memory:  %ld kB\n", used_memory);
    printf("=========================\n");
    
    // Supercharged Visualization
    printf("💾 Memory Status:\n");
    printf("  (Free) "); 
    for (long i = 0; i < free_memory / 1000; i++) printf("🟩");
    printf("  (Used) ");
    for (long i = 0; i < used_memory / 1000; i++) printf("🟥");
    printf("\n");
    
    printf("=========================\n");
    printf("🎉 You're doing awesome! Keep an eye on your RAM usage!\n");
    printf("=========================\n");
}

int main() {
    display_memory_info();
    return 0;
}