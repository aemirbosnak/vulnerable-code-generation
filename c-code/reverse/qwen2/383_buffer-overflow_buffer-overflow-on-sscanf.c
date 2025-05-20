#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *fp;
    char line[256];
    unsigned long total_memory = 0, free_memory = 0, available_memory = 0;

    while (1) {
        fp = fopen("/proc/meminfo", "r");
        if (!fp) {
            perror("Failed to open /proc/meminfo");
            exit(EXIT_FAILURE);
        }

        while (fgets(line, sizeof(line), fp)) {
            if (sscanf(line, "MemTotal: %lu kB", &total_memory) == 1) {
                total_memory /= 1024; // Convert KB to MB
            } else if (sscanf(line, "MemFree: %lu kB", &free_memory) == 1) {
                free_memory /= 1024; // Convert KB to MB
            } else if (sscanf(line, "MemAvailable: %lu kB", &available_memory) == 1) {
                available_memory /= 1024; // Convert KB to MB
            }
        }

        fclose(fp);

        printf("Total Memory: %lu MB\n", total_memory);
        printf("Free Memory: %lu MB\n", free_memory);
        printf("Available Memory: %lu MB\n", available_memory);

        sleep(1);
    }

    return 0;
}
