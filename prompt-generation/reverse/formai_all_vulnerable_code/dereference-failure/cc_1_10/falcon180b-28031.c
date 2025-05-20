//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(int argc, char *argv[])
{
    int i;
    int cpu_count;
    int *cpu_percent;
    int *cpu_time;
    struct rusage usage;
    FILE *file;
    char filename[10];
    char line[100];
    char *token;

    // Get CPU count
    if (sysconf(_SC_NPROCESSORS_ONLN) <= 0)
    {
        printf("Error: Unable to determine CPU count.\n");
        exit(1);
    }
    cpu_count = sysconf(_SC_NPROCESSORS_ONLN);

    // Allocate memory for CPU usage data
    cpu_percent = (int *)malloc(cpu_count * sizeof(int));
    cpu_time = (int *)malloc(cpu_count * sizeof(int));

    // Initialize CPU usage data
    for (i = 0; i < cpu_count; i++)
    {
        cpu_percent[i] = 0;
        cpu_time[i] = 0;
    }

    // Open file for writing
    sprintf(filename, "cpu_usage.txt");
    if ((file = fopen(filename, "w")) == NULL)
    {
        printf("Error: Unable to open output file.\n");
        exit(1);
    }

    // Write header to file
    fprintf(file, "CPU Usage Monitor\n\n");
    fprintf(file, "CPU %  Idle %\n");

    // Main loop
    while (1)
    {
        // Get CPU usage data
        if (getrusage(RUSAGE_SELF, &usage) == -1)
        {
            printf("Error: Unable to get CPU usage data.\n");
            exit(1);
        }

        // Calculate CPU usage for each core
        for (i = 0; i < cpu_count; i++)
        {
            cpu_time[i] = usage.ru_utime.tv_sec * 100;
        }

        // Write CPU usage data to file
        fprintf(file, "\n");
        for (i = 0; i < cpu_count; i++)
        {
            fprintf(file, "CPU %d: %d%% %d%%\n", i + 1, (int)(cpu_time[i] * 100.0 / usage.ru_utime.tv_sec), (100 - cpu_time[i]));
        }

        // Sleep for 1 second
        sleep(1);
    }

    // Close file
    fclose(file);

    return 0;
}