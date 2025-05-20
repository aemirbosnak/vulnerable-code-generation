//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: beginner-friendly
// RAM usage monitor in C

#include <stdio.h>
#include <stdlib.h>

// Get the current RAM usage
int getRAMUsage() {
    // Open the /proc/meminfo file
    FILE *meminfo = fopen("/proc/meminfo", "r");
    if (meminfo == NULL) {
        perror("Error opening /proc/meminfo");
        return -1;
    }

    // Read the first line of the file, which contains the total RAM usage
    char line[1024];
    if (fgets(line, sizeof(line), meminfo) == NULL) {
        perror("Error reading /proc/meminfo");
        fclose(meminfo);
        return -1;
    }

    // Close the /proc/meminfo file
    fclose(meminfo);

    // Parse the line to get the total RAM usage
    int totalRAM;
    if (sscanf(line, "MemTotal: %d kB", &totalRAM) != 1) {
        perror("Error parsing /proc/meminfo");
        return -1;
    }

    // Return the total RAM usage
    return totalRAM;
}

// Print the RAM usage
void printRAMUsage(int ramUsage) {
    // Convert the RAM usage to megabytes
    float ramUsageMB = ramUsage / 1024.0;

    // Print the RAM usage
    printf("RAM usage: %.2f MB\n", ramUsageMB);
}

// Main function
int main() {
    // Get the current RAM usage
    int ramUsage = getRAMUsage();

    // Print the RAM usage
    printRAMUsage(ramUsage);

    return 0;
}