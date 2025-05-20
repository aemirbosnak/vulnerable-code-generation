//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUF_SIZE 128

double calculate_cpu_percentage(long idle_jiffies, long total_jiffies)
{
    static long prev_idle_jiffies = 0, prev_total_jiffies = 0;
    double cpu_percentage = 0;
    if (prev_idle_jiffies && prev_total_jiffies)
    {
        long idle_diff = idle_jiffies - prev_idle_jiffies;
        long total_diff = total_jiffies - prev_total_jiffies;
        cpu_percentage = (double) 100 * (1 - ((double) idle_diff / total_diff));
    }
    prev_idle_jiffies = idle_jiffies;
    prev_total_jiffies = total_jiffies;
    return cpu_percentage;
}

int get_cpu_jiffies(long cpu_jiffies[])
{
    FILE *file_pointer;
    char buffer[MAX_BUF_SIZE];
    long jiffies[10];
    file_pointer = fopen("/proc/stat", "r");
    if (!file_pointer)
    {
        return 0;
    }
    fgets(buffer, MAX_BUF_SIZE, file_pointer);
    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
        &jiffies[0], &jiffies[1], &jiffies[2], &jiffies[3], &jiffies[4],
        &jiffies[5], &jiffies[6], &jiffies[7], &jiffies[8], &jiffies[9]);
    fclose(file_pointer);
    memcpy(cpu_jiffies, jiffies, sizeof(long) * 10);
    return 1;
}

int main()
{
    long cpu_jiffies[10];
    if (get_cpu_jiffies(cpu_jiffies))
    {
        long idle_jiffies = cpu_jiffies[3];
        long total_jiffies = 0;
        for (int i = 0; i < 10; i++)
        {
            total_jiffies += cpu_jiffies[i];
        }
        printf("CPU Usage: %.2f%%\n", calculate_cpu_percentage(idle_jiffies, total_jiffies));
        sleep(1);
    }
    return 0;
}