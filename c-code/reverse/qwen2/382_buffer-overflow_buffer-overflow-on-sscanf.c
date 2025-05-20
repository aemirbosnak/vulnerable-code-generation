#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "MemTotal:")) {
            int mem_total;
            sscanf(line, "MemTotal: %d kB", &mem_total);
            printf("Memory Total: %d kB\n", mem_total);
        } else if (strstr(line, "MemFree:")) {
            int mem_free;
            sscanf(line, "MemFree: %d kB", &mem_free);
            printf("Memory Free: %d kB\n", mem_free);
        }
    }

    fclose(fp);
    return 0;
}
