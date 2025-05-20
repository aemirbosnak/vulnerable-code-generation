//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MB (1024 * 1024)

int main() {
    long total_ram;
    long used_ram;
    long free_ram;
    long shared_ram;
    long buffer_ram;
    long cached_ram;

    // Open the "/proc/meminfo" file.
    FILE *meminfo = fopen("/proc/meminfo", "r");
    if (meminfo == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the "/proc/meminfo" file.
    char line[1024];
    while (fgets(line, sizeof(line), meminfo) != NULL) {
        // Parse the line.
        char *name = strtok(line, ":");
        char *value = strtok(NULL, "\n");
        if (name == NULL || value == NULL) {
            continue;
        }

        // Get the value.
        long value_long;
        if (sscanf(value, "%ld", &value_long) != 1) {
            continue;
        }

        // Store the value.
        if (strcmp(name, "MemTotal:") == 0) {
            total_ram = value_long;
        } else if (strcmp(name, "MemUsed:") == 0) {
            used_ram = value_long;
        } else if (strcmp(name, "MemFree:") == 0) {
            free_ram = value_long;
        } else if (strcmp(name, "SharedMem:") == 0) {
            shared_ram = value_long;
        } else if (strcmp(name, "Buffers:") == 0) {
            buffer_ram = value_long;
        } else if (strcmp(name, "Cached:") == 0) {
            cached_ram = value_long;
        }
    }

    // Close the "/proc/meminfo" file.
    fclose(meminfo);

    // Print the RAM usage.
    printf("Total RAM: %ld MB\n", total_ram / MB);
    printf("Used RAM: %ld MB\n", used_ram / MB);
    printf("Free RAM: %ld MB\n", free_ram / MB);
    printf("Shared RAM: %ld MB\n", shared_ram / MB);
    printf("Buffer RAM: %ld MB\n", buffer_ram / MB);
    printf("Cached RAM: %ld MB\n", cached_ram / MB);

    return EXIT_SUCCESS;
}