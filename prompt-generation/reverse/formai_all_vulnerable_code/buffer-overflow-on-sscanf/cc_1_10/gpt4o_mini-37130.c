//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_LEN 256

// Function to get the total and used RAM in kilobytes
void getRAMUsage(long *total, long *used) {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Could not open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LEN];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %ld kB", total) == 1) {
            // Extracting total memory
            continue;
        }
        if (sscanf(line, "MemAvailable: %ld kB", used) == 1) {
            // Extracting the available memory
            *used = *total - *used;  // Used memory = Total - Available
            break;
        }
    }

    fclose(file);
}

int main() {
    long totalRAM = 0, usedRAM = 0;

    // Infinite loop to monitor RAM usage
    while (1) {
        getRAMUsage(&totalRAM, &usedRAM); // Function call to get RAM

        printf("\033[2J\033[H"); // Clear screen and move the cursor to home
        printf("============= RAM Usage Monitor =============\n");
        printf("Total RAM: %ld kB\n", totalRAM);
        
        if (totalRAM != 0) {
            // Calculate percentage of used RAM
            double usagePercent = ((double)usedRAM / totalRAM) * 100;
            printf("Used RAM: %ld kB (%.2f%%)\n", usedRAM, usagePercent);
        } else {
            printf("Unable to load RAM data!\n");
        }

        printf("==============================================\n");

        sleep(1); // Wait for 1 second before updating
    }

    return 0; // Exit
}