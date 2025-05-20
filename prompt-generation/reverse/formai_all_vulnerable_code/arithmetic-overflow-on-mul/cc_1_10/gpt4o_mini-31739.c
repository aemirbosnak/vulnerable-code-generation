//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void print_memory_usage() {
    FILE *file;
    long int total_memory, free_memory, used_memory, shared_memory;
    long int memory_info[6];
    
    file = fopen("/proc/self/statm", "r");
    if (file == NULL) {
        perror("Failed to open /proc/self/statm");
        exit(EXIT_FAILURE);
    }

    // Read memory info from the statm file
    fscanf(file, "%ld %ld %ld %ld", &memory_info[0], &memory_info[1], &memory_info[2], &memory_info[3]);
    fclose(file);

    // Calculate total, used, and free memory in pages (system-dependent)
    long int pagesize = sysconf(_SC_PAGE_SIZE); // Get page size
    total_memory = memory_info[0] * pagesize;
    free_memory = memory_info[1] * pagesize;
    used_memory = total_memory - free_memory;
    shared_memory = memory_info[3] * pagesize;

    printf("\nMemory Usage Stats:\n");
    printf("Total Memory: %ld bytes\n", total_memory);
    printf("Used Memory: %ld bytes\n", used_memory);
    printf("Free Memory: %ld bytes\n", free_memory);
    printf("Shared Memory: %ld bytes\n", shared_memory);
}

void print_memory_usage_summary() {
    void print_memory_usage();
    printf("\nPress CTRL+C to exit...\n");
    
    while (1) {
        print_memory_usage();
        sleep(1); // Polling every second
    }
}

int main() {
    printf("C Memory Usage Monitor\n");
    printf("========================\n");
    print_memory_usage_summary();
    return 0;
}