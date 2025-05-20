//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MB 1024 * 1024

int main(int argc, char **argv)
{
    // Parse arguments
    int interval = 5;
    if (argc > 1) {
        interval = atoi(argv[1]);
        if (interval <= 0) {
            fprintf(stderr, "Invalid interval: %s\n", argv[1]);
            return 1;
        }
    }

    // Open /proc/meminfo
    FILE *meminfo = fopen("/proc/meminfo", "r");
    if (meminfo == NULL) {
        perror("fopen");
        return 1;
    }

    // Read meminfo into a buffer
    char buffer[4096];
    fread(buffer, sizeof(buffer), 1, meminfo);
    fclose(meminfo);

    // Parse meminfo
    unsigned long total_ram = 0;
    unsigned long free_ram = 0;
    char *line = buffer;
    while (line) {
        char *key = strtok(line, ":");
        if (strcmp(key, "MemTotal") == 0) {
            total_ram = atol(strtok(NULL, " "));
        } else if (strcmp(key, "MemFree") == 0) {
            free_ram = atol(strtok(NULL, " "));
        }
        line = strtok(NULL, "\n");
    }

    // Calculate RAM usage
    unsigned long used_ram = total_ram - free_ram;
    unsigned long usage = (used_ram * 100) / total_ram;

    // Print RAM usage
    printf("RAM usage: %lu%%\n", usage);

    // Loop forever, printing RAM usage every interval seconds
    while (1) {
        sleep(interval);

        // Read meminfo again
        meminfo = fopen("/proc/meminfo", "r");
        if (meminfo == NULL) {
            perror("fopen");
            return 1;
        }
        fread(buffer, sizeof(buffer), 1, meminfo);
        fclose(meminfo);

        // Parse meminfo
        total_ram = 0;
        free_ram = 0;
        line = buffer;
        while (line) {
            char *key = strtok(line, ":");
            if (strcmp(key, "MemTotal") == 0) {
                total_ram = atol(strtok(NULL, " "));
            } else if (strcmp(key, "MemFree") == 0) {
                free_ram = atol(strtok(NULL, " "));
            }
            line = strtok(NULL, "\n");
        }

        // Calculate RAM usage
        used_ram = total_ram - free_ram;
        usage = (used_ram * 100) / total_ram;

        // Print RAM usage
        printf("RAM usage: %lu%%\n", usage);
    }

    return 0;
}