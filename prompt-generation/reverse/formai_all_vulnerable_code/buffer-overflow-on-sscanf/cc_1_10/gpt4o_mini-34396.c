//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_BAR_LENGTH 50

void getMemoryUsage(double *total, double *used) {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Could not open /proc/meminfo");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %lf kB", total) == 1) {
            *total /= 1024; // Convert to MB
        } else if (sscanf(line, "MemAvailable: %lf kB", used) == 1) {
            *used = *total - (*used / 1024); // Convert available to used in MB
            break;
        }
    }
    fclose(file);
}

void drawBar(double used, double total) {
    int barLength = (int)((used / total) * MAX_BAR_LENGTH);
    printf("RAM Usage: [%.*s%*s] %.2f MB / %.2f MB\n", 
        barLength, "##################################################", 
        MAX_BAR_LENGTH - barLength, " ", 
        used, total);
}

void displayMemoryUsage() {
    double totalMemory = 0.0, usedMemory = 0.0;
    
    while (1) {
        getMemoryUsage(&totalMemory, &usedMemory);
        printf("\033[H\033[J"); // Clear the terminal
        drawBar(usedMemory, totalMemory);
        usleep(1000000); // Update every second
    }
}

int main() {
    printf("Welcome to the RAM Usage Monitor!\n");
    printf("Monitoring system RAM usage in real-time...\n");
    displayMemoryUsage();
    
    return 0;
}