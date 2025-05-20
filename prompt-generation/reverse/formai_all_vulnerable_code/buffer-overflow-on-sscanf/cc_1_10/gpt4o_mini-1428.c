//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

void display_memory_usage() {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }
    
    char line[BUFFER_SIZE];
    long total_memory = 0;
    long free_memory = 0;
    
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %ld kB", &total_memory) == 1) {
            continue;
        }
        if (sscanf(line, "MemFree: %ld kB", &free_memory) == 1) {
            continue;
        }
    }
    
    fclose(file);
    
    long used_memory = total_memory - free_memory;
    
    // Surprise style printout
    printf("==================================\n");
    printf("🧠 Memory Usage Monitor 🧠\n");
    printf("==================================\n");
    printf("✨ Total RAM: %ld kB\n", total_memory);
    printf("✨ Free RAM: %ld kB\n", free_memory);
    printf("✨ Used RAM: %ld kB\n", used_memory);
    
    float percentage_used = (float)used_memory / total_memory * 100;
    printf("✨ Percentage Used: %.2f%%\n", percentage_used);
    
    int i;
    printf("✨ RAM Usage Visualization: ");
    for (i = 0; i < (int)percentage_used / 2; i++) {
        printf("🟩");
    }
    for (; i < 50; i++) {
        printf("⬜");
    }
    printf("\n==================================\n");
}

int main() {
    while (1) {
        printf("\033[H\033[J"); // Clear the console
        display_memory_usage();
        sleep(5); // Refresh every 5 seconds
    }
    
    return 0;
}