#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parse_meminfo() {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "MemTotal:", 9) == 0) {
            long total_memory = atol(line + 10);
            printf("Total Memory: %ld kB\n", total_memory);
        } else if (strncmp(line, "MemFree:", 8) == 0) {
            long free_memory = atol(line + 9);
            printf("Free Memory: %ld kB\n", free_memory);
        } else if (strncmp(line, "Buffers:", 8) == 0) {
            long buffers = atol(line + 9);
            printf("Buffers: %ld kB\n", buffers);
        } else if (strncmp(line, "Cached:", 7) == 0) {
            long cached = atol(line + 8);
            printf("Cached: %ld kB\n", cached);
        }
    }

    fclose(fp);
}

int main() {
    parse_meminfo();
    return 0;
}
