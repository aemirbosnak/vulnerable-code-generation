//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MB 1048576 // 1 MB in bytes

int main() {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int total_memory;
    int used_memory;

    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    // Get total memory
    if ((read = getline(&line, &len, fp)) != -1) {
        sscanf(line, "MemTotal: %d kB", &total_memory);
        total_memory /= 1024; // Convert to MB
    }

    // Get used memory
    if ((read = getline(&line, &len, fp)) != -1) {
        sscanf(line, "MemAvailable: %d kB", &used_memory);
        used_memory = total_memory - (used_memory / 1024); // Convert to MB
    }

    // Close file
    fclose(fp);

    // Display results
    printf("Total Memory: %d MB\n", total_memory);
    printf("Used Memory: %d MB\n", used_memory);

    // Monitor memory usage every 10 seconds
    while (1) {
        fp = fopen("/proc/meminfo", "r");
        if (fp == NULL) {
            perror("Error opening file\n");
            exit(EXIT_FAILURE);
        }

        // Get used memory
        if ((read = getline(&line, &len, fp)) != -1) {
            sscanf(line, "MemAvailable: %d kB", &used_memory);
            used_memory = total_memory - (used_memory / 1024); // Convert to MB
        }

        // Close file
        fclose(fp);

        // Display results
        printf("Used Memory: %d MB\n", used_memory);

        // Sleep for 10 seconds
        sleep(10);
    }

    return 0;
}