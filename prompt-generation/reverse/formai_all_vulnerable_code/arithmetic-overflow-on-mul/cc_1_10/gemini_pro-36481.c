//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: complex
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/resource.h>

// Custom data structure to track memory usage
typedef struct {
    size_t total_memory;
    size_t current_memory;
    size_t peak_memory;
} MemoryUsage;

// Initialize memory usage data structure
MemoryUsage memoryUsage = {0, 0, 0};

// Function to get current memory usage
void getMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    memoryUsage.current_memory = usage.ru_maxrss * 1024;
    if (memoryUsage.current_memory > memoryUsage.peak_memory) {
        memoryUsage.peak_memory = memoryUsage.current_memory;
    }
}

// Function to print memory usage
void printMemoryUsage() {
    printf("Total memory allocated: %.2f MB\n", (double)memoryUsage.total_memory / (1024 * 1024));
    printf("Current memory usage: %.2f MB\n", (double)memoryUsage.current_memory / (1024 * 1024));
    printf("Peak memory usage: %.2f MB\n", (double)memoryUsage.peak_memory / (1024 * 1024));
}

// Main function
int main() {
    // Allocate memory
    char *largeBuffer = malloc(100 * 1024 * 1024);  // 100 MB buffer
    memoryUsage.total_memory += 100 * 1024 * 1024;

    // Do some memory-intensive operations
    for (int i = 0; i < 100000000; i++) {
        memset(largeBuffer, 'A', 100 * 1024 * 1024);
        getMemoryUsage();
    }

    // Free memory
    free(largeBuffer);
    memoryUsage.total_memory -= 100 * 1024 * 1024;

    // Print memory usage
    printMemoryUsage();

    return 0;
}