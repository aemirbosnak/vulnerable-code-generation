//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

struct cpu_usage_seconds
{
    double user;
    double nice;
    double system;
    double idle;
};

struct cpu_usage
{
    struct cpu_usage_seconds start;
    struct cpu_usage_seconds end;
    struct timespec start_time;
    struct timespec end_time;
};

int get_cpu_usage(struct cpu_usage *usage)
{
    FILE *fp;
    char line[256];
    char *token;
    int i;

    /* open "/proc/stat" file */
    fp = fopen("/proc/stat", "r");
    if (fp == NULL)
        return -1;

    /* read the first line */
    if (fgets(line, sizeof(line), fp) == NULL)
        return -1;

    /* split the first line by space */
    token = strtok(line, " ");
    i = 0;
    while (token != NULL)
    {
        switch (i)
        {
        case 0:
            usage->start.user = atol(token);
            break;
        case 1:
            usage->start.nice = atol(token);
            break;
        case 2:
            usage->start.system = atol(token);
            break;
        case 3:
            usage->start.idle = atol(token);
            break;
        }
        i++;
        token = strtok(NULL, " ");
    }

    /* get the current time */
    clock_gettime(CLOCK_MONOTONIC, &usage->start_time);

    /* close the file */
    fclose(fp);

    return 0;
}

int main()
{
    struct cpu_usage usage;
    double cpu_usage_percent;
    double elapsed_seconds;

    /* get the initial CPU usage */
    if (get_cpu_usage(&usage) == -1)
    {
        perror("get_cpu_usage");
        return 1;
    }

    /* sleep for 1 second */
    sleep(1);

    /* get the final CPU usage */
    if (get_cpu_usage(&usage) == -1)
    {
        perror("get_cpu_usage");
        return 1;
    }

    /* calculate the elapsed seconds */
    elapsed_seconds = (usage.end_time.tv_sec - usage.start_time.tv_sec) +
                      (usage.end_time.tv_nsec - usage.start_time.tv_nsec) / 1000000000.0;

    /* calculate the CPU usage percentage */
    cpu_usage_percent = 100.0 * ((usage.end.user + usage.end.nice + usage.end.system) -
                                  (usage.start.user + usage.start.nice + usage.start.system)) /
                                 elapsed_seconds;

    /* print the CPU usage percentage */
    printf("CPU usage: %f%%\n", cpu_usage_percent);

    return 0;
}