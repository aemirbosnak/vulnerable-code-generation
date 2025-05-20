//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Convert bytes to a human-readable string.
char *bytes_to_string(uint64_t bytes) {
    char *str = malloc(256);
    if (!str) return NULL;

    if (bytes < 1024) {
        snprintf(str, 256, "%lu B", bytes);
    } else if (bytes < 1024 * 1024) {
        snprintf(str, 256, "%.2f KB", (double)bytes / 1024);
    } else if (bytes < 1024 * 1024 * 1024) {
        snprintf(str, 256, "%.2f MB", (double)bytes / (1024 * 1024));
    } else {
        snprintf(str, 256, "%.2f GB", (double)bytes / (1024 * 1024 * 1024));
    }

    return str;
}

// Get the current RAM usage.
uint64_t get_ram_usage() {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (!fp) return -1;

    char line[256];
    uint64_t total_ram = 0;
    uint64_t free_ram = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (!strncmp(line, "MemTotal:", 9)) {
            sscanf(line + 9, "%lu", &total_ram);
        } else if (!strncmp(line, "MemFree:", 8)) {
            sscanf(line + 8, "%lu", &free_ram);
        }
    }

    fclose(fp);

    return total_ram - free_ram;
}

// Print the RAM usage.
void print_ram_usage() {
    uint64_t ram_usage = get_ram_usage();
    if (ram_usage == -1) {
        printf("Error getting RAM usage.\n");
        return;
    }

    char *str = bytes_to_string(ram_usage);
    if (!str) {
        printf("Error converting bytes to string.\n");
        return;
    }

    printf("RAM usage: %s\n", str);
    free(str);
}

// Main function.
int main() {
    print_ram_usage();
    return 0;
}