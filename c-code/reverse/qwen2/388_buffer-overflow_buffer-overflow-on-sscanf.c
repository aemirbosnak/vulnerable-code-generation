#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        return EXIT_FAILURE;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        unsigned long total, free, available;
        if (sscanf(line, "MemTotal: %lu kB", &total) != 1 ||
            sscanf(line, "MemFree: %lu kB", &free) != 1 ||
            sscanf(line, "MemAvailable: %lu kB", &available) != 1) {
            continue;
        }
        printf("Total: %lu MB, Free: %lu MB, Available: %lu MB\n",
               total / 1024, free / 1024, available / 1024);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}
