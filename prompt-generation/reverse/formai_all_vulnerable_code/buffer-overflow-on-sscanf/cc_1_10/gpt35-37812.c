//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: shocked
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct _cpu_stat
{
    uint64_t user;
    uint64_t nice;
    uint64_t system;
    uint64_t idle;
    uint64_t iowait;
    uint64_t irq;
    uint64_t softirq;
    uint64_t steal;
} cpu_stat;

int main(void)
{
    cpu_stat curr, prev;
    char line[256];
    FILE* fp;
    double usage;

    fp = fopen("/proc/stat", "r");
    if(fp == NULL)
    {
        fprintf(stderr, "Failed to open /proc/stat!\n");
        exit(EXIT_FAILURE);
    }

    memset(&prev, 0, sizeof(cpu_stat));

    while(fgets(line, sizeof(line), fp) != NULL)
    {
        if(strncmp(line, "cpu ", 4) == 0)
        {
            sscanf(line, "cpu %lu %lu %lu %lu %lu %lu %lu %lu",
                &prev.user, &prev.nice, &prev.system, &prev.idle,
                &prev.iowait, &prev.irq, &prev.softirq, &prev.steal);
        }
    }

    while(1)
    {
        sleep(1);

        rewind(fp);

        memset(&curr, 0, sizeof(cpu_stat));

        while(fgets(line, sizeof(line), fp) != NULL)
        {
            if(strncmp(line, "cpu ", 4) == 0)
            {
                sscanf(line, "cpu %lu %lu %lu %lu %lu %lu %lu %lu",
                    &curr.user, &curr.nice, &curr.system, &curr.idle,
                    &curr.iowait, &curr.irq, &curr.softirq, &curr.steal);
            }
        }

        uint64_t total_diff = 0;
        uint64_t idle_diff = curr.idle - prev.idle;

        for(int i = 0; i < sizeof(cpu_stat) / sizeof(uint64_t); i++)
        {
            uint64_t* prev_ptr = (uint64_t*)&prev + i;
            uint64_t* curr_ptr = (uint64_t*)&curr + i;
            total_diff += (*curr_ptr - *prev_ptr);
        }

        usage = 100.0 * (total_diff - idle_diff) / total_diff;
        printf("CPU Usage: %.2lf%%\n", usage);

        prev = curr;
    }

    fclose(fp);

    return 0;
}