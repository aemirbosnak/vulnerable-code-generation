//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Struct to store CPU usage information
typedef struct {
    unsigned long long user;
    unsigned long long nice;
    unsigned long long system;
    unsigned long long idle;
    unsigned long long iowait;
    unsigned long long irq;
    unsigned long long softirq;
    unsigned long long steal;
    unsigned long long guest;
    unsigned long long guest_nice;
} cpu_usage_t;

// Function to retrieve CPU usage information
int get_cpu_usage(cpu_usage_t *usage) {
    // Open the /proc/stat file
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) {
        return -1;
    }

    // Read the first line of the file
    char line[1024];
    if (!fgets(line, sizeof(line), fp)) {
        fclose(fp);
        return -1;
    }

    // Parse the fields from the line
    int num_fields = sscanf(line, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
        &usage->user, &usage->nice, &usage->system, &usage->idle, &usage->iowait, &usage->irq,
        &usage->softirq, &usage->steal, &usage->guest, &usage->guest_nice);

    // Check if the number of fields parsed is correct
    if (num_fields != 10) {
        fclose(fp);
        return -1;
    }

    // Close the file
    fclose(fp);

    return 0;
}

// Function to print CPU usage information
void print_cpu_usage(const cpu_usage_t *usage) {
    printf("CPU Usage:\n");
    printf("  User: %llu\n", usage->user);
    printf("  Nice: %llu\n", usage->nice);
    printf("  System: %llu\n", usage->system);
    printf("  Idle: %llu\n", usage->idle);
    printf("  Iowait: %llu\n", usage->iowait);
    printf("  Irq: %llu\n", usage->irq);
    printf("  Softirq: %llu\n", usage->softirq);
    printf("  Steal: %llu\n", usage->steal);
    printf("  Guest: %llu\n", usage->guest);
    printf("  Guest Nice: %llu\n", usage->guest_nice);
}

// Main function
int main(void) {
    // Retrieve CPU usage information
    cpu_usage_t usage;
    if (get_cpu_usage(&usage) != 0) {
        fprintf(stderr, "Error: Could not retrieve CPU usage information.\n");
        return EXIT_FAILURE;
    }

    // Print CPU usage information
    print_cpu_usage(&usage);

    return EXIT_SUCCESS;
}