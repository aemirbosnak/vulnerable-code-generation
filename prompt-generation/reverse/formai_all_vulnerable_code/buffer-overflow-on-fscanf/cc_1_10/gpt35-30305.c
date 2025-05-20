//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main()
{
    char stat_file_path[32], buf[BUF_SIZE], *token;
    int pid, utime, stime, total_time, system_time, uptime, hertz;
    float cpu_usage;

    // Get the PID of this process
    pid = getpid();

    // Get the system uptime and the number of ticks per second
    FILE *uptime_fp = fopen("/proc/uptime", "r");
    fscanf(uptime_fp, "%d", &uptime);
    fclose(uptime_fp);

    FILE *hertz_fp = fopen("/sys/devices/system/cpu/cpu0/cpufreq/scaling_max_freq", "r");
    fscanf(hertz_fp, "%d", &hertz);
    fclose(hertz_fp);

    // Construct the path to the /proc/<pid>/stat file
    sprintf(stat_file_path, "/proc/%d/stat", pid);

    while(1)
    {
        // Open the /proc/<pid>/stat file
        FILE *stat_fp = fopen(stat_file_path, "r");

        if(stat_fp == NULL)
        {
            fprintf(stderr, "Failed to open %s\n", stat_file_path);
            exit(EXIT_FAILURE);
        }

        // Read the contents of the file into a buffer
        fgets(buf, BUF_SIZE, stat_fp);
        fclose(stat_fp);

        // Extract the CPU time values from the buffer
        token = strtok(buf, " ");
        for(int i = 1; i < 14; ++i)
        {
            token = strtok(NULL, " ");
        }
        utime = atoi(token);
        token = strtok(NULL, " ");
        stime = atoi(token);
        total_time = utime + stime;

        // Calculate the CPU usage
        system_time = uptime - (total_time / hertz);
        cpu_usage = ((float)total_time / hertz) / system_time * 100;

        printf("CPU Usage: %.2f%%\n", cpu_usage);

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}