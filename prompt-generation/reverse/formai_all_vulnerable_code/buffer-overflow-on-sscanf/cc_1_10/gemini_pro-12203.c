//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: peaceful
// CPU usage monitor, delicately crafted to soothe and inform
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define FRAME_COUNT 100
#define FRAME_INTERVAL 100000 // Microseconds
#define BAR_WIDTH 50

// Calculate CPU usage for a specified frame
float get_cpu_usage(void) {
    FILE *fp;
    char buf[1024];
    float user, nice, system, idle;

    // Read /proc/stat to get CPU time information
    fp = fopen("/proc/stat", "r");
    fgets(buf, sizeof(buf), fp);
    sscanf(buf, "cpu %f %f %f %f", &user, &nice, &system, &idle);
    fclose(fp);

    // Calculate CPU usage as (user + nice + system) / (user + nice + system + idle)
    return (user + nice + system) / (user + nice + system + idle);
}

int main(void) {
    // Buffer for CPU usage history
    float cpu_usage_history[FRAME_COUNT];
    int frame_index = 0;

    // Main monitoring loop
    while (1) {
        // Get current CPU usage
        float cpu_usage = get_cpu_usage();

        // Store CPU usage in history buffer
        cpu_usage_history[frame_index++] = cpu_usage;
        frame_index %= FRAME_COUNT;

        // Render CPU usage bar
        printf("\nCPU Usage: [");
        for (int i = 0; i < BAR_WIDTH; i++) {
            if (i < BAR_WIDTH * cpu_usage) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("] %.2f%%\n", cpu_usage * 100);

        // Sleep for specified frame interval
        usleep(FRAME_INTERVAL);
    }

    return EXIT_SUCCESS;
}