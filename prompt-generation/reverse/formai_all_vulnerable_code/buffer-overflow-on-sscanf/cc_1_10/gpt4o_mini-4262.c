//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 256
#define SLEEP_TIME 2

void parse_meminfo(const char *meminfo_line, long *total, long *free, long *available) {
    char key[BUF_SIZE];
    long value;

    sscanf(meminfo_line, "%s %ld", key, &value);
    
    // Normalize key to account for the fields we care about
    if (strcmp(key, "MemTotal:") == 0) {
        *total = value;
    } else if (strcmp(key, "MemFree:") == 0) {
        *free = value;
    } else if (strcmp(key, "MemAvailable:") == 0) {
        *available = value;
    }
}

void display_memory_usage() {
    FILE *fp;
    char line[BUF_SIZE];
    long total_memory = 0, free_memory = 0, available_memory = 0;

    // Open the /proc/meminfo file for reading
    fp = fopen("/proc/meminfo", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/meminfo");
        return;
    }

    // Read the file line by line
    while (fgets(line, sizeof(line), fp)) {
        parse_meminfo(line, &total_memory, &free_memory, &available_memory);
        
        // We can stop parsing after we have all the necessary fields
        if (total_memory && free_memory && available_memory) {
            break;
        }
    }
    fclose(fp);

    // Calculate used memory
    long used_memory = total_memory - free_memory;
    long used_percentage = (used_memory * 100) / total_memory;

    // Display memory usage
    printf("Total Memory: %ld kB\n", total_memory);
    printf("Free Memory: %ld kB\n", free_memory);
    printf("Available Memory: %ld kB\n", available_memory);
    printf("Used Memory: %ld kB (Percentage: %ld%%)\n\n", used_memory, used_percentage);
}

int main() {
    printf("**** RAM Usage Monitor ****\n");
    printf("Monitoring RAM usage every %d seconds...\n\n", SLEEP_TIME);

    while (1) {
        display_memory_usage();
        sleep(SLEEP_TIME);
    }

    return 0;
}