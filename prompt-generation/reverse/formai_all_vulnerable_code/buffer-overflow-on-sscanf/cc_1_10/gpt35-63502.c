//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_LINE_CHARS 1000
#define INTERVAL_SECONDS 5

int get_ram_usage() {
    FILE* file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Error opening /proc/meminfo");
        exit(1);
    }

    int total_mem_kb = 0, free_mem_kb = 0, available_mem_kb = 0;
    char line[MAX_LINE_CHARS];

    while (fgets(line, MAX_LINE_CHARS, file)) {
        sscanf(line, "MemTotal: %d kB", &total_mem_kb);
        sscanf(line, "MemFree: %d kB", &free_mem_kb);
        sscanf(line, "MemAvailable: %d kB", &available_mem_kb);
    }

    fclose(file);

    int used_mem_kb = total_mem_kb - free_mem_kb;
    int ram_usage = (int)((float)used_mem_kb / (float)total_mem_kb * 100);

    return ram_usage;
}

void print_ram_usage(int ram_usage) {
    time_t now = time(NULL);
    struct tm* timeinfo = localtime(&now);

    printf("%02d:%02d:%02d RAM usage: %d%%\n",
        timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, ram_usage);
}

int main() {
    while (1) {
        int ram_usage = get_ram_usage();
        print_ram_usage(ram_usage);

        sleep(INTERVAL_SECONDS);
    }

    return 0;
}