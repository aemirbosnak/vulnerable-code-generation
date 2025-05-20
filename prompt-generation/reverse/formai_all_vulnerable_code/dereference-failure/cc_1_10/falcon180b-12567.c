//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#define BUF_SIZE 1024

int main() {
    char buf[BUF_SIZE];
    struct statvfs stat;

    printf("RAM Usage Monitor\n");
    printf("=================\n");

    // Get the total and available memory in bytes
    statvfs("/", &stat);
    long total_mem = stat.f_blocks * stat.f_bsize;
    long available_mem = stat.f_bavail * stat.f_bsize;

    // Get the current memory usage in bytes
    FILE *meminfo = fopen("/proc/meminfo", "r");
    if (meminfo == NULL) {
        printf("Error: Could not open /proc/meminfo\n");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    while ((read = getline(&line, &len, meminfo))!= -1) {
        if (strncmp(line, "MemTotal:", 9) == 0) {
            sscanf(line + 9, "%ld kB", &total_mem);
        } else if (strncmp(line, "MemFree:", 8) == 0) {
            sscanf(line + 8, "%ld kB", &available_mem);
        }
    }

    fclose(meminfo);

    // Calculate the used memory in bytes
    long used_mem = total_mem - available_mem;

    // Calculate the memory usage as a percentage
    float usage_pct = (float) used_mem / total_mem * 100.0;

    // Print the results
    printf("\nTotal memory: %ld bytes\n", total_mem);
    printf("Available memory: %ld bytes\n", available_mem);
    printf("Used memory: %ld bytes\n", used_mem);
    printf("Memory usage: %.2f%%\n", usage_pct);

    return 0;
}