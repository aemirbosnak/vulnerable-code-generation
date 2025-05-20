//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void displayMemoryUsage() {
    FILE *file;
    char buffer[256];

    // Open the meminfo file to read memory statistics
    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Could not open /proc/meminfo");
        exit(EXIT_FAILURE);
    }
    
    // Buffer to hold the data
    long totalMemory = 0, freeMemory = 0, availableMemory = 0;

    // Read the first three lines and store the values
    for (int i = 0; i < 3; i++) {
        fgets(buffer, sizeof(buffer), file);
        if (i == 0) {
            sscanf(buffer, "MemTotal: %ld kB", &totalMemory);
        } else if (i == 1) {
            sscanf(buffer, "MemFree: %ld kB", &freeMemory);
        } else if (i == 2) {
            sscanf(buffer, "MemAvailable: %ld kB", &availableMemory);
        }
    }
    
    // Close the file after reading
    fclose(file);

    // Calculate the used memory
    long usedMemory = totalMemory - freeMemory;

    // Display the results
    printf("\033[H\033[J"); // Clear the terminal screen
    printf("******* RAM Usage Monitor *******\n");
    printf("Total Memory:     %ld kB\n", totalMemory);
    printf("Free Memory:      %ld kB\n", freeMemory);
    printf("Available Memory:  %ld kB\n", availableMemory);
    printf("Used Memory:      %ld kB\n", usedMemory);
    printf("**********************************\n");
}

int main() {
    printf("Starting RAM Usage Monitor. Press Ctrl+C to stop.\n");
    
    while (1) {
        displayMemoryUsage();
        sleep(1); // Sleep for 1 second before next update
    }

    return 0;
}