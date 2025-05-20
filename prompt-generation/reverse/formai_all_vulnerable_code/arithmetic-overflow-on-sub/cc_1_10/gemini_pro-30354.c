//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Macros for ANSI escape codes
#define CLEAR_SCREEN "\033[2J"
#define MOVE_CURSOR_TO(x, y) "\033["#x";"#y"f"

// Function to get CPU usage
double get_cpu_usage() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    int idle, total;

    // Open the proc/stat file
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Error opening /proc/stat");
        exit(1);
    }

    // Get the first line of the file (CPU usage)
    nread = getline(&line, &len, fp);
    if (nread == -1) {
        perror("Error reading /proc/stat");
        exit(1);
    }

    // Parse the line and get the idle and total CPU time
    sscanf(line, "cpu %d %d", &idle, &total);

    // Caluculate the CPU usage as a percentage
    double usage = 100.0 * (total - idle) / total;

    // Close the file
    fclose(fp);

    // Return the CPU usage
    return usage;
}

int main(void) {
    // Clear the screen
    printf(CLEAR_SCREEN);

    // Main loop
    while (1) {
        // Get the CPU usage
        double usage = get_cpu_usage();

        // Move the cursor to the top of the screen
        printf(MOVE_CURSOR_TO(0, 0));

        // Print the CPU usage
        printf("CPU Usage: %.2f%%\n", usage);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}