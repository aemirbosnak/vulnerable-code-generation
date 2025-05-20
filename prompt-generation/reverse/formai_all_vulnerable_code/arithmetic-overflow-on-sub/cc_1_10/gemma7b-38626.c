//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>

#define BUFFER_SIZE 256

int main()
{
    char buffer[BUFFER_SIZE];
    FILE *fp;
    long int cpu_usage = 0;
    long int prev_cpu_usage = 0;
    long int total_time = 0;
    long int i = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Get the previous CPU usage
    fscanf(fp, "%ld ", &prev_cpu_usage);

    // Loop to get the CPU usage over time
    while (1)
    {
        // Get the current CPU usage
        fscanf(fp, "%ld ", &cpu_usage);

        // Calculate the time spent
        long int time_spent = cpu_usage - prev_cpu_usage;

        // Add the time spent to the total time
        total_time += time_spent;

        // Update the previous CPU usage
        prev_cpu_usage = cpu_usage;

        // Sleep for a while
        sleep(1);

        // Print the CPU usage
        printf("CPU usage: %.2f%%", (float)total_time / total_time * 100);

        // Reset the total time
        total_time = 0;

        // Increment the loop index
        i++;

        // Check if the user wants to exit
        if (i >= 10)
        {
            break;
        }
    }

    fclose(fp);

    return EXIT_SUCCESS;
}