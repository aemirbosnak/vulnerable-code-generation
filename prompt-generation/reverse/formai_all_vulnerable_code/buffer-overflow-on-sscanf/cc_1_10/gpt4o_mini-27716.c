//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>

#define BUFFER_SIZE 256
#define SLEEP_TIME 1

void getCPUUsage(uint64_t *user, uint64_t *nice, uint64_t *system, uint64_t *idle) {
    FILE *file;
    char buffer[BUFFER_SIZE];

    // Open /proc/stat to read CPU stats
    file = fopen("/proc/stat", "r");
    if (!file) {
        perror("Error opening /proc/stat");
        exit(EXIT_FAILURE);
    }

    fgets(buffer, sizeof(buffer), file);
    sscanf(buffer, "cpu %llu %llu %llu %llu", user, nice, system, idle);
    
    fclose(file);
}

void drawUsageBar(double usage) {
    int barWidth = 50; // Width of the bar in characters
    int filledLength = (int)(usage * barWidth / 100.0); 
    int emptyLength = barWidth - filledLength;

    printf("CPU Usage: [");
    for (int i = 0; i < filledLength; i++) printf("=");
    for (int i = 0; i < emptyLength; i++) printf(" ");
    printf("] %.2f%%\n", usage);
}

int main() {
    uint64_t user1, nice1, system1, idle1;
    uint64_t user2, nice2, system2, idle2;

    while (1) {
        // Get CPU statistics before sleep
        getCPUUsage(&user1, &nice1, &system1, &idle1);
        
        // Sleep for a while
        sleep(SLEEP_TIME);
        
        // Get CPU statistics after sleep
        getCPUUsage(&user2, &nice2, &system2, &idle2);
        
        // Calculate CPU usage
        uint64_t total1 = user1 + nice1 + system1 + idle1;
        uint64_t total2 = user2 + nice2 + system2 + idle2;

        uint64_t idleDiff = idle2 - idle1;
        uint64_t totalDiff = total2 - total1;

        double usage = 100.0 * (totalDiff - idleDiff) / totalDiff;

        // Draw CPU Usage Bar
        printf("\033[H\033[J"); // Clear the terminal (ANSI escape sequences)
        drawUsageBar(usage);

        // Sleep to slow down the output
        usleep(500000); // Sleep for 0.5 seconds
    }

    return 0;
}