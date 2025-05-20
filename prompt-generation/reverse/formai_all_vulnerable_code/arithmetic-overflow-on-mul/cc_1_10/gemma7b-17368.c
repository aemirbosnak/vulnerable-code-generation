//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main() {

    // Define variables for CPU usage statistics
    int cpu_usage = 0;
    int total_usage = 0;
    int current_usage = 0;
    int average_usage = 0;
    int i = 0;
    char filename[256];

    // Open a file to store CPU usage statistics
    FILE *fp = fopen("cpu_usage.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Loop to collect CPU usage statistics
    while (1) {
        // Get the current CPU usage
        cpu_usage = getcpu();

        // Increment total usage and calculate current usage percentage
        total_usage++;
        current_usage = (cpu_usage * 100) / total_usage;

        // Write statistics to the file
        fprintf(fp, "%d, %d\n", time(NULL), current_usage);

        // Sleep for 1 second
        sleep(1);

        // Calculate the average usage
        average_usage = (total_usage - average_usage) / i;

        // Print the average usage
        printf("Average CPU usage: %d%%\n", average_usage);

        // Increment the loop counter
        i++;
    }

    // Close the file
    fclose(fp);

    return 0;
}