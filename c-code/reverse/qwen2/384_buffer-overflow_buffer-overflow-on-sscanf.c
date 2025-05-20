#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) return 1;

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        int mem_total;
        if (sscanf(line, "MemTotal: %d kB", &mem_total) == 1) {
            printf("Memory Total: %d kB\n", mem_total);
        }
    }

    fclose(fp);
    return 0;
}
