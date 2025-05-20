#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MEMINFO_PATH "/proc/meminfo"

void parse_meminfo(long *total, long *free) {
    FILE *fp = fopen(MEMINFO_PATH, "r");
    if (!fp) {
        perror("Failed to open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "MemTotal:", 9) == 0) {
            sscanf(line, "MemTotal: %ld kB", total);
        } else if (strncmp(line, "MemFree:", 8) == 0) {
            sscanf(line, "MemFree: %ld kB", free);
        }
    }

    fclose(fp);
}

int main() {
    long total_memory, free_memory;

    while (1) {
        parse_meminfo(&total_memory, &free_memory);

        double used_memory = (double)(total_memory - free_memory) / 1024;
        printf("Memory Usage: %.2f MB\n", used_memory);

        sleep(1);
    }

    return 0;
}
