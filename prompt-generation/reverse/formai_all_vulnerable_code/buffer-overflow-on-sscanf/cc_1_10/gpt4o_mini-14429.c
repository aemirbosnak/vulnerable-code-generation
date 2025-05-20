//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MEMORY_SIZE 1024 // Max memory blocks to monitor
#define STATUS_SIZE 256  // String size for status

typedef struct {
    size_t total;
    size_t used;
    size_t free;
} MemoryStats;

typedef struct {
    char* process_name;
    size_t memory_usage;
} ProcessUsage;

void get_memory_stats(MemoryStats* stats) {
    FILE* file = fopen("/proc/meminfo", "r");
    if (!file) {
        perror("Could not open /proc/meminfo");
        exit(EXIT_FAILURE);
    }

    char line[STATUS_SIZE];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "MemTotal: %lu kB", &stats->total) == 1) {
            stats->total *= 1024; // Convert to bytes
        } else if (sscanf(line, "MemAvailable: %lu kB", &stats->free) == 1) {
            stats->free *= 1024; // Convert to bytes
        }
    }
    fclose(file);

    stats->used = stats->total - stats->free;
}

void fetch_process_memory_usage(ProcessUsage* usages, int* count) {
    FILE* file = fopen("/proc/self/statm", "r");
    if (!file) {
        perror("Could not open /proc/self/statm");
        exit(EXIT_FAILURE);
    }

    size_t memory_page_size = sysconf(_SC_PAGE_SIZE); // Number of bytes per page
    char line[STATUS_SIZE];
    fgets(line, sizeof(line), file);
    fclose(file);

    size_t total_memory = 0;
    size_t num_elements = 0;

    char *token = strtok(line, " ");
    while (token != NULL && num_elements < MEMORY_SIZE) {
        usages[num_elements].memory_usage = atoi(token) * memory_page_size;
        usages[num_elements].process_name = "Current Process";
        
        total_memory += usages[num_elements].memory_usage;
        num_elements++;
        token = strtok(NULL, " ");
    }
    
    *count = num_elements;
}

void display_memory_usage(const MemoryStats* stats, const ProcessUsage* usages, int process_count) {
    printf("Total Memory: %lu bytes\n", stats->total);
    printf("Used Memory: %lu bytes\n", stats->used);
    printf("Free Memory: %lu bytes\n", stats->free);
    printf("Memory Usage by Processes:\n");

    for (int i = 0; i < process_count; i++) {
        printf("- %s: %lu bytes\n", usages[i].process_name, usages[i].memory_usage);
    }
    printf("--------------------------------------------------\n");
}

int main() {
    MemoryStats system_memory;
    get_memory_stats(&system_memory);

    ProcessUsage process_memory[MEMORY_SIZE];
    int process_count = 0;
    fetch_process_memory_usage(process_memory, &process_count);

    while (1) {
        system("clear"); // Clear the terminal for fresh output
        display_memory_usage(&system_memory, process_memory, process_count);
        sleep(5); // Sleep for a while before updating
    }
    
    return 0;
}