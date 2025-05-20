//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <string.h>

void displayMemoryUsage(long total, long free, long used) {
    // Compute percentages
    float used_percentage = ((float)used / total) * 100;
    float free_percentage = ((float)free / total) * 100;

    // Display header
    printf("\033[1;34m");
    printf("\n=====================\n");
    printf("   RAM Usage Monitor  \n");
    printf("=====================\n\033[0m");

    // Display total, used, and free memory
    printf("Total Memory: \033[1;32m%ld MB\033[0m\n", total / 1024);
    printf("Used Memory:  \033[1;33m%ld MB (%.2f%%)\033[0m\n", used / 1024, used_percentage);
    printf("Free Memory:  \033[1;36m%ld MB (%.2f%%)\033[0m\n", free / 1024, free_percentage);
    
    // Display a fancy memory usage bar
    printf("\nMemory Usage Bar:\n");
    int bar_length = 50; // Length of the memory bar
    int used_bar_length = (int)((used_percentage / 100) * bar_length);
    int free_bar_length = bar_length - used_bar_length;

    // Display the used portion
    printf("\033[1;33m[");
    for (int i = 0; i < used_bar_length; i++) {
        printf("=");
    }
    // Display the free portion
    for (int i = 0; i < free_bar_length; i++) {
        printf(" ");
    }
    printf("]\033[0m %d%% Used\n", (int)used_percentage);

    printf("\033[1;34m=====================\n\033[0m");
}

int main() {
    while (1) {
        // System information for memory usage
        struct sysinfo memInfo;
        if (sysinfo(&memInfo) != 0) {
            perror("sysinfo");
            return 1;
        }

        // Gather data
        long total_memory = memInfo.totalram;
        long free_memory = memInfo.freeram;
        long used_memory = total_memory - free_memory;

        // Display memory usage
        displayMemoryUsage(total_memory, free_memory, used_memory);
        
        // Refresh every 2 seconds
        sleep(2);
        // Clear the console for the next refresh
        printf("\033[H\033[J");
    }
    return 0;
}