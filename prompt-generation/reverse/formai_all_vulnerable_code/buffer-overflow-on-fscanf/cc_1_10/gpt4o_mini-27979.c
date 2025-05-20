//GPT-4o-mini DATASET v1.0 Category: RAM usage monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 256

// Function to get the memory usage of the current process
void get_memory_usage() {
    FILE *file;
    char buffer[BUFFER_SIZE];
    size_t total_memory = 0, used_memory = 0;

    // Open the status file for the current process in the proc filesystem
    snprintf(buffer, sizeof(buffer), "/proc/%d/statm", getpid());
    file = fopen(buffer, "r");
    
    if (file) {
        // Read total memory and used memory from the file
        fscanf(file, "%lu %lu", &total_memory, &used_memory);
        fclose(file);
        
        // Note: Each memory page is typically 4KB
        size_t page_size = sysconf(_SC_PAGE_SIZE);
        total_memory *= page_size; // Total memory in bytes
        used_memory *= page_size;   // Used memory in bytes

        // Print the results
        printf("Total Memory: %.2f MB\n", total_memory / (1024.0 * 1024.0));
        printf("Used Memory: %.2f MB\n", used_memory / (1024.0 * 1024.0));
        printf("Free Memory: %.2f MB\n", (total_memory - used_memory) / (1024.0 * 1024.0));
    } else {
        fprintf(stderr, "Error opening memory information file.\n");
        exit(EXIT_FAILURE);
    }
}

// Function to simulate memory usage for demonstration
void simulate_memory_usage() {
    size_t size = 100 * 1024 * 1024; // Allocate 100MB
    char *memory_block = malloc(size);
    if (memory_block) {
        memset(memory_block, 0, size); // Zero out the allocated memory

        // Output message to indicate memory allocation
        printf("Simulated memory allocation: %zu bytes allocated.\n", size);
        sleep(3); // Keep the memory allocated for 3 seconds

        // Free the allocated memory
        free(memory_block);
        printf("Simulated memory freed.\n");
    } else {
        fprintf(stderr, "Memory allocation failed.\n");
    }
}

// Main function
int main(int argc, char *argv[]) {
    printf("Welcome to the RAM Usage Monitor!\n");

    // Get the user's choice for monitoring frequency
    int frequency;
    printf("Enter memory usage monitoring frequency (in seconds, e.g., 5): ");
    scanf("%d", &frequency);

    // Run the monitor and simulate memory usage
    while (1) {
        get_memory_usage();
        simulate_memory_usage();
        sleep(frequency); // Wait for the user-defined frequency
    }

    return 0;
}