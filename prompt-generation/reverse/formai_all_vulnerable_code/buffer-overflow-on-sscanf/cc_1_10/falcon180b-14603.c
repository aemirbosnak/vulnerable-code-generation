//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

// Function to get current CPU usage percentage
float get_cpu_usage() {
    FILE *file;
    char line[1024];
    float cpu_percent = 0.0;

    file = fopen("/proc/stat", "r");
    if (file == NULL) {
        printf("Error: Could not open /proc/stat\n");
        exit(1);
    }

    fgets(line, sizeof(line), file);
    fgets(line, sizeof(line), file);
    fgets(line, sizeof(line), file);
    fgets(line, sizeof(line), file);

    sscanf(line, "cpu %d %d %d %d", &cpu_percent, &cpu_percent, &cpu_percent, &cpu_percent);

    fclose(file);
    return cpu_percent / (double)cpu_percent;
}

int main() {
    int i;
    float cpu_usage;

    // Initialize random seed
    srand(time(NULL));

    // Loop indefinitely
    while (TRUE) {
        // Get current CPU usage percentage
        cpu_usage = get_cpu_usage();

        // Print CPU usage in a funny way
        for (i = 0; i < 8; i++) {
            if (cpu_usage >= i * 0.125) {
                printf("|");
            } else {
                printf(" ");
            }
        }

        printf("\n");
        fflush(stdout);

        // Sleep for a random amount of time
        usleep(rand() % 500000);
    }

    return 0;
}