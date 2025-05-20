//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <time.h>
#include <string.h>

void display_memory_usage(long total, long free, long used) {
    // Clear the console screen for fresh display
    printf("\033[H\033[J"); // ANSI escape code to clear screen
    printf(" ================== RAM Usage Monitor ================== \n");
    printf("                    \U0001F4B0 Memory Overview                    \n");
    printf(" ======================================================= \n");
    
    printf(" Total RAM:   %ld MB\n", total / 1024);
    printf(" Free RAM:    %ld MB\n", free / 1024);
    printf(" Used RAM:    %ld MB\n", used / 1024);
    
    float usage_percentage = (float) used / total * 100;
    printf(" Memory Usage: %.2f%%\n", usage_percentage);
    
    // Fancy visualization of used vs free memory
    printf(" ======================================================= \n");
    printf(" Used Memory Visualization:\n");
    printf(" [");
    int total_blocks = 50; // Total blocks for the visualization
    int used_blocks = (int)(used * total_blocks / total);
    for (int i = 0; i < total_blocks; i++) {
        if (i < used_blocks) {
            printf("▒"); // Block represents used memory
        } else {
            printf("░"); // Block represents free memory
        }
    }
    printf("] %ld MB used\n", used / 1024);
    
    printf(" ======================================================= \n");
    printf(" Press Ctrl+C to exit the monitor. \n\n");
}

int main() {
    struct sysinfo si;
    
    printf("Welcome to the Memory Realm!\n");
    printf("Prepare to embark on a journey of RAM exploration...\n");

    while (1) {
        // Get system information
        if (sysinfo(&si) == 0) {
            long total_memory = si.totalram;
            long free_memory = si.freeram;
            long used_memory = total_memory - free_memory;
            
            display_memory_usage(total_memory, free_memory, used_memory);
        } else {
            perror("Failed to retrieve system information");
        }
        
        sleep(1); // Pause for 1 second before updating the display
    }
    
    return 0; // Program will never reach this as we are in an infinite loop
}