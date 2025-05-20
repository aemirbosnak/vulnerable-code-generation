//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void clearScreen() {
    // Use ANSI escape codes to clear the terminal screen
    printf("\033[H\033[J");
}

void printHeader() {
    printf("\n");
    printf("=================================\n");
    printf("       RAM Usage Monitor         \n");
    printf("=================================\n");
}

void printMemoryUsage() {
    FILE *file;
    char line[256];
    long totalMemory = 0, freeMemory = 0, usedMemory = 0;

    // Open the memory info file
    file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    // Read memory information from the file
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %ld kB", &totalMemory) == 1) {
            continue;
        }
        if (sscanf(line, "MemFree: %ld kB", &freeMemory) == 1) {
            continue;
        }
    }
    fclose(file);

    // Calculate used memory
    usedMemory = totalMemory - freeMemory;

    // Display memory usage
    printf("Total RAM: %.2f GB\n", totalMemory / 1024.0 / 1024.0);
    printf("Used RAM: %.2f GB\n", usedMemory / 1024.0 / 1024.0);
    printf("Free RAM: %.2f GB\n", freeMemory / 1024.0 / 1024.0);
    printf("=================================\n");
}

int main() {
    // Create a lively loop to continuously monitor RAM usage
    while (1) {
        clearScreen();
        printHeader();
        printMemoryUsage();

        // Sleep for 2 seconds before updating the display
        sleep(2);
    }

    return 0;
}