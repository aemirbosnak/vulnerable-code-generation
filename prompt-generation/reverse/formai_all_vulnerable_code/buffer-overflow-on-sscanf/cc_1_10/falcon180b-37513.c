//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define NUM_PROCESSES 10
#define DELAY_TIME 1

int main()
{
    FILE *file;
    char buffer[BUFFER_SIZE];
    pid_t pids[NUM_PROCESSES];
    int i, j, num_processes = 0;
    float cpu_usage[NUM_PROCESSES];

    file = fopen("/proc/stat", "r");
    if (file == NULL)
    {
        printf("Error opening /proc/stat\n");
        exit(1);
    }

    while (fgets(buffer, BUFFER_SIZE, file)!= NULL)
    {
        if (strncmp(buffer, "cpu", 3) == 0)
        {
            sscanf(buffer, "cpu %d %d %d %d", &cpu_usage[num_processes], &cpu_usage[num_processes], &cpu_usage[num_processes], &cpu_usage[num_processes]);
            num_processes++;
        }
    }

    fclose(file);

    for (i = 0; i < num_processes; i++)
    {
        for (j = i + 1; j < num_processes; j++)
        {
            if (cpu_usage[j] > cpu_usage[i])
            {
                float temp = cpu_usage[i];
                cpu_usage[i] = cpu_usage[j];
                cpu_usage[j] = temp;
            }
        }
    }

    printf("Process\tCPU Usage\n");
    for (i = 0; i < num_processes; i++)
    {
        printf("%d\t%.2f%%\n", i, cpu_usage[i]);
    }

    return 0;
}