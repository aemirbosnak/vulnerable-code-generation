#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    int mem_total, mem_free;

    FILE *file = fopen("/proc/meminfo", "r");
    if (!file) {
        perror("Error opening /proc/meminfo");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (sscanf(buffer, "MemTotal:        %d kB\n", &mem_total) == 1) {
            break;
        }
    }

    rewind(file);
    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (sscanf(buffer, "MemFree:          %d kB\n", &mem_free) == 1) {
            break;
        }
    }

    printf("Total Memory: %d kB\n", mem_total);
    printf("Free Memory: %d kB\n", mem_free);

    fclose(file);

    char overflow[mem_total + 1];
    strcpy(overflow, buffer); // Buffer overflow vulnerability

    return 0;
}
