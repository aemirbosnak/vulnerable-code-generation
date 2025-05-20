//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MEGABYTE 1024 * 1024

int main(void)
{
    // Let's peek into the RAM's secret stash!
    FILE *mem = fopen("/proc/meminfo", "r");
    if (!mem) {
        printf("Oops! No peeking allowed. Memory's a shy one today!\n");
        return EXIT_FAILURE;
    }

    // Time to decipher the memory's secret code...
    char buffer[512];
    uint64_t total_ram, free_ram;
    while (fgets(buffer, sizeof(buffer), mem)) {
        if (!strncmp(buffer, "MemTotal:", 9)) {
            sscanf(buffer, "MemTotal: %llu kB", &total_ram);
        } else if (!strncmp(buffer, "MemFree:", 8)) {
            sscanf(buffer, "MemFree: %llu kB", &free_ram);
        }
    }

    // Let's reveal the RAM's treasure...
    fclose(mem);
    printf("Total RAM: %llu MB\n", total_ram / MEGABYTE);
    printf("Free RAM: %llu MB\n", free_ram / MEGABYTE);
    printf("Used RAM: %llu MB\n", (total_ram - free_ram) / MEGABYTE);

    // Now let's sip some tea and watch the RAM work its magic...
    sleep(10);

    // A second peek into the RAM's world...
    mem = fopen("/proc/meminfo", "r");
    if (!mem) {
        printf("Oh no! The memory's gone into hiding. What a shy one!\n");
        return EXIT_FAILURE;
    }

    // Time to decode the RAM's secret language again...
    while (fgets(buffer, sizeof(buffer), mem)) {
        if (!strncmp(buffer, "MemTotal:", 9)) {
            sscanf(buffer, "MemTotal: %llu kB", &total_ram);
        } else if (!strncmp(buffer, "MemFree:", 8)) {
            sscanf(buffer, "MemFree: %llu kB", &free_ram);
        }
    }

    // Let's uncover the RAM's secrets once more...
    fclose(mem);
    printf("Updated Total RAM: %llu MB\n", total_ram / MEGABYTE);
    printf("Updated Free RAM: %llu MB\n", free_ram / MEGABYTE);
    printf("Updated Used RAM: %llu MB\n", (total_ram - free_ram) / MEGABYTE);

    // Voila! We've unveiled the RAM's secrets. Now let's leave it to its solitude...
    return EXIT_SUCCESS;
}