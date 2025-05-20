//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to calculate CPU usage
float get_cpu_usage()
{
    FILE* fp;
    char buffer[1024];
    size_t bytes_read;
    unsigned long long idle_time, total_time;
    float cpu_usage;

    fp = fopen("/proc/stat", "r");

    if(fp == NULL)
    {
        perror("Error opening /proc/stat file");
        exit(1);
    }

    // read the first line of /proc/stat file
    bytes_read = fread(buffer, 1, sizeof(buffer), fp);
    fclose(fp);

    if(bytes_read == 0)
    {
        perror("Error reading /proc/stat file");
        exit(1);
    }

    // look for CPU line in the buffer and parse the values
    sscanf(buffer, "cpu %llu %*llu %*llu %*llu %llu", &idle_time, &total_time);

    cpu_usage = ((total_time - idle_time) * 100.0) / total_time;

    return cpu_usage;
}

int main()
{
    float cpu_usage;
    time_t current_time;

    while(1)
    {
        cpu_usage = get_cpu_usage();
        time(&current_time);

        printf("CPU Usage: %.2f%% | Date and Time: %s", cpu_usage, ctime(&current_time));

        // wait for 1 second
        sleep(1);
    }

    return 0;
}