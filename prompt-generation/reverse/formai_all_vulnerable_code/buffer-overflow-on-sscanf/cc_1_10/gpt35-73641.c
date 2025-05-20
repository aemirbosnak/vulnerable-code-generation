//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// To store the RAM usage data
struct memory_stats {
    unsigned long long total_memory;
    unsigned long long free_memory;
    unsigned long long used_memory;
};

// Function to read the memory stats of the system from /proc/meminfo
struct memory_stats read_memory_stats() {
    struct memory_stats stats;
    char buffer[1024];

    FILE* meminfo_file = fopen("/proc/meminfo", "r");
    if (meminfo_file == NULL) {
        perror("Unable to read /proc/meminfo");
        exit(1);
    }

    fgets(buffer, sizeof(buffer), meminfo_file);
    sscanf(buffer, "MemTotal: %llu kB", &stats.total_memory);

    fgets(buffer, sizeof(buffer), meminfo_file);
    sscanf(buffer, "MemFree: %llu kB", &stats.free_memory);

    fclose(meminfo_file);
    stats.used_memory = stats.total_memory - stats.free_memory;

    return stats;
}

// Function to print the memory stats in a readable format
void print_memory_stats(struct memory_stats stats) {
    printf("\n\n========== Memory Stats ==========\n");
    printf("Total Memory: %llu kB\n", stats.total_memory);
    printf("Free Memory: %llu kB\n", stats.free_memory);
    printf("Used Memory: %llu kB\n", stats.used_memory);
}

int main() {
    while (1) {
        struct memory_stats stats = read_memory_stats();
        print_memory_stats(stats);
        sleep(1);
        system("clear");    // Clear the terminal to avoid cluttering
    }

    return 0;
}