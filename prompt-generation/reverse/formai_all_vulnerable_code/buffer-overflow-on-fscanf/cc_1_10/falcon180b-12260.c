//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#define PROC_PATH "/proc/self/stat"
#define PROC_STATM "/proc/self/statm"

int main()
{
    FILE* proc_file = NULL;
    int num_processors = 0;
    long total_memory = 0;
    long free_memory = 0;
    long shared_memory = 0;
    long text_size = 0;
    long data_size = 0;
    long stack_size = 0;
    long cpu_usage = 0;
    char buffer[1024];

    if ((proc_file = fopen(PROC_PATH, "r")) == NULL)
    {
        printf("Error opening %s\n", PROC_PATH);
        exit(1);
    }

    if (fscanf(proc_file, "%d", &num_processors)!= 1)
    {
        printf("Error reading number of processors\n");
        exit(1);
    }

    if (fscanf(proc_file, "%*s %*s %*s %*s %*s %*s %*s %ld %ld", &text_size, &data_size)!= 2)
    {
        printf("Error reading process size\n");
        exit(1);
    }

    if ((proc_file = fopen(PROC_STATM, "r")) == NULL)
    {
        printf("Error opening %s\n", PROC_STATM);
        exit(1);
    }

    if (fscanf(proc_file, "%ld %ld %ld %ld %ld %ld", &total_memory, &shared_memory, &text_size, &data_size, &stack_size, &cpu_usage)!= 6)
    {
        printf("Error reading process memory usage\n");
        exit(1);
    }

    fclose(proc_file);

    // Calculate CPU usage percentage
    cpu_usage /= num_processors;
    cpu_usage *= 100;

    printf("Number of processors: %d\n", num_processors);
    printf("Total memory: %ld bytes\n", total_memory);
    printf("Free memory: %ld bytes\n", free_memory);
    printf("Shared memory: %ld bytes\n", shared_memory);
    printf("Text size: %ld bytes\n", text_size);
    printf("Data size: %ld bytes\n", data_size);
    printf("Stack size: %ld bytes\n", stack_size);
    printf("CPU usage: %ld%%\n", cpu_usage);

    return 0;
}