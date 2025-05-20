//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Function declarations
void display_header();
void display_memory_usage();
void delay(int seconds);

int main() {
    display_header();

    while (1) {
        display_memory_usage();
        delay(2); // Refresh every 2 seconds
    }

    return 0; // Sealed with a final goodbye
}

void display_header() {
    system("clear"); // Clear the terminal for a clean interface
    printf("=====================================\n");
    printf("      🌟 RAM Usage Monitor 🌟      \n");
    printf("=====================================\n");
    printf("  Monitoring your system's RAM usage!\n");
    printf("  Press CTRL+C to exit the monitor\n");
    printf("=====================================\n");
}

void display_memory_usage() {
    FILE *fp;
    char line[256];
    size_t total_memory = 0;
    size_t free_memory = 0;
    
    // Open the /proc/meminfo file
    if ((fp = fopen("/proc/meminfo", "r")) == NULL) {
        perror("Failed to open meminfo");
        exit(EXIT_FAILURE);
    }

    // Read memory information from the file
    while (fgets(line, sizeof(line), fp)) {
        if (sscanf(line, "MemTotal: %zu kB", &total_memory) == 1) {
            // Successfully read total memory
        }
        if (sscanf(line, "MemFree: %zu kB", &free_memory) == 1) {
            // Successfully read free memory
        }
    }
    fclose(fp);

    size_t used_memory = total_memory - free_memory;

    // Display memory usage statistics
    printf("Total Memory: %.2f GB\n", total_memory / 1024.0 / 1024.0);
    printf("Free Memory: %.2f GB\n", free_memory / 1024.0 / 1024.0);
    printf("Used Memory: %.2f GB\n", used_memory / 1024.0 / 1024.0);
    printf("Memory Usage Percentage: %.2f%%\n", (used_memory / (float)total_memory) * 100);
    
    printf("=====================================\n");
}

void delay(int seconds) {
    for(int i = 0; i < seconds; i++) {
        printf("Updating in %d...\r", seconds - i);
        fflush(stdout);
        sleep(1);
    }
}