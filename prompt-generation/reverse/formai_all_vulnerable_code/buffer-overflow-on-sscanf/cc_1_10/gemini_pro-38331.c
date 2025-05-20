//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define DELAY_MS 200

int main() {
    FILE *fp;
    char buf[1024];
    int idle, total;
    int old_idle, old_total;

    // Open the file that contains CPU usage information
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the first line of the file, which contains the CPU usage information
    fgets(buf, sizeof(buf), fp);

    // Parse the CPU usage information from the file
    sscanf(buf, "cpu  %d %d", &old_idle, &old_total);

    // Close the file
    fclose(fp);

    // Loop until the user presses Ctrl+C
    while (1) {
        // Open the file that contains CPU usage information
        fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            perror("fopen");
            return EXIT_FAILURE;
        }

        // Read the first line of the file, which contains the CPU usage information
        fgets(buf, sizeof(buf), fp);

        // Parse the CPU usage information from the file
        sscanf(buf, "cpu  %d %d", &idle, &total);

        // Close the file
        fclose(fp);

        // Calculate the CPU usage percentage
        int cpu_usage = 100 - ((idle - old_idle) * 100) / (total - old_total);

        // Print the CPU usage percentage
        printf("CPU usage: %d%%\r", cpu_usage);

        // Update the old CPU usage information
        old_idle = idle;
        old_total = total;

        // Sleep for a short period of time
        usleep(DELAY_MS * 1000);
    }

    return EXIT_SUCCESS;
}