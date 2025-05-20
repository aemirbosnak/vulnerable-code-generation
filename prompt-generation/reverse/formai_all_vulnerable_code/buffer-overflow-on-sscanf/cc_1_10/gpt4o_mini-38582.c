//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

void parse_meminfo(char *line, long *total_memory, long *free_memory, long *used_memory) {
    char key[BUFFER_SIZE];
    long value;
    
    sscanf(line, "%s %ld kB", key, &value);

    if (strcmp(key, "MemTotal:") == 0) {
        *total_memory = value;
    } else if (strcmp(key, "MemFree:") == 0) {
        *free_memory = value;
    }
}

void calculate_memory_usage(long total_memory, long free_memory, long *used_memory) {
    *used_memory = total_memory - free_memory;
}

void display_memory_usage(long total_memory, long free_memory, long used_memory) {
    printf("Total Memory: %ld kB\n", total_memory);
    printf("Free Memory: %ld kB\n", free_memory);
    printf("Used Memory: %ld kB\n", used_memory);
    
    float used_memory_percentage = ((float)used_memory / (float)total_memory) * 100;
    printf("Used Memory Percentage: %.2f %%\n", used_memory_percentage);
}

void monitor_memory_usage() {
    FILE *file = fopen("/proc/meminfo", "r");
    if (file == NULL) {
        perror("Could not open /proc/meminfo");
        exit(EXIT_FAILURE);
    }
    
    long total_memory = 0, free_memory = 0, used_memory = 0;

    while (!feof(file)) {
        char line[BUFFER_SIZE];
        if (fgets(line, sizeof(line), file) != NULL) {
            parse_meminfo(line, &total_memory, &free_memory, &used_memory);
        }
    }

    fclose(file);
    calculate_memory_usage(total_memory, free_memory, &used_memory);
    display_memory_usage(total_memory, free_memory, used_memory);
}

int main() {
    while (1) {
        monitor_memory_usage();
        printf("\n\n");
        sleep(5);  // Refresh every 5 seconds
    }
    
    return 0;
}