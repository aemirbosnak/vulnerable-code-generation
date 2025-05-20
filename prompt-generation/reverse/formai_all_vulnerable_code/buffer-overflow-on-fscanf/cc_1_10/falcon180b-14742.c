//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define CPU_USAGE_FILE "/proc/stat"
#define TOTAL_CPU_USAGE_FILE "/proc/stat"
#define NUM_CPUS 4

int main() {
    FILE *file;
    char filename[20];
    float total_cpu_usage = 0.0;
    float cpu_usage[NUM_CPUS] = {0.0};
    int i, j;

    // Open the CPU usage file for reading
    sprintf(filename, "%s", CPU_USAGE_FILE);
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open CPU usage file.\n");
        exit(1);
    }

    // Read the CPU usage data
    for (i = 0; i < NUM_CPUS; i++) {
        for (j = 0; j < 2; j++) {
            fscanf(file, "%f", &cpu_usage[i]);
        }
    }

    // Calculate the total CPU usage
    for (i = 0; i < NUM_CPUS; i++) {
        total_cpu_usage += cpu_usage[i];
    }

    // Print the CPU usage data
    printf("CPU usage:\n");
    for (i = 0; i < NUM_CPUS; i++) {
        printf("CPU%d: %.2f%%\n", i+1, cpu_usage[i] / total_cpu_usage * 100);
    }

    // Close the CPU usage file
    fclose(file);

    return 0;
}