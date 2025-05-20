//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

void printCPUUsage(int percent)
{
    printf("\rCPU Usage: [%-50s] %d%%", "--------------------------------------------------" + (50 - percent / 2), percent);
    fflush(stdout);
}

int calculateCPUUsage()
{
    static clock_t prev_total_ticks = 0, prev_idle_ticks = 0;
    clock_t total_ticks, idle_ticks, diff_total_ticks, diff_idle_ticks;

    FILE *fp = fopen("/proc/stat", "r");
    fscanf(fp, "cpu %ld %ld %ld %ld", &total_ticks, &idle_ticks, &diff_total_ticks, &diff_idle_ticks);
    fclose(fp);

    if (prev_total_ticks > 0)
    {
        float diff_idle = idle_ticks - prev_idle_ticks;
        float diff_total = total_ticks - prev_total_ticks;
        float usage = 100.0 * (diff_total - diff_idle) / diff_total;
        return (int)usage;
    }

    prev_total_ticks = total_ticks;
    prev_idle_ticks = idle_ticks;

    return -1;
}

int main()
{
    int seconds = 1;
    int duration = 20;

    printf("CPU Usage Monitor\n");
    printf("------------------\n");
    printf("Monitoring CPU usage every %d seconds for %d seconds\n", seconds, duration);

    int total_loops = duration / seconds;
    int current_loop = 0;

    int *usage_history = (int *)malloc(total_loops * sizeof(int));
    memset(usage_history, 0, total_loops * sizeof(int));

    while (current_loop < total_loops)
    {
        int cpu_usage = calculateCPUUsage();
        if (cpu_usage >= 0)
        {
            usage_history[current_loop] = cpu_usage;
            current_loop++;
        }
        printCPUUsage(cpu_usage);
        sleep(seconds);
    }

    long long int sum_usage = 0;
    int max_usage = 0;
    int min_usage = 100;

    printf("\n\nCPU Usage History\n");
    printf("------------------\n");

    for (int i = 0; i < total_loops; i++)
    {
        printf("%d s: %d%%\n", i * seconds, usage_history[i]);

        sum_usage += usage_history[i];

        if (usage_history[i] > max_usage)
        {
            max_usage = usage_history[i];
        }

        if (usage_history[i] < min_usage)
        {
            min_usage = usage_history[i];
        }
    }

    printf("\nAverage CPU usage: %.2f%%\n", (float)sum_usage / total_loops);
    printf("Maximum CPU usage: %d%%\n", max_usage);
    printf("Minimum CPU usage: %d%%\n", min_usage);

    free(usage_history);

    return 0;
}