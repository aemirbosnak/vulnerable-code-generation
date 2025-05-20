//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PROC_NUM 256

int main()
{
    int proc_num, i, j, k, cpu_usage, total_usage = 0;
    char proc_name[256];

    FILE *fp;
    fp = fopen("/proc/stat", "r");

    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    printf("------------------------------------------------------------\n");
    printf("Process ID\t\tCPU Usage (%) \t\tProcess Name\n");
    printf("------------------------------------------------------------\n");

    for (proc_num = 0; proc_num < MAX_PROC_NUM; proc_num++)
    {
        sprintf(proc_name, "/proc/%d/stat", proc_num);
        fp = fopen(proc_name, "r");

        if (fp == NULL)
        {
            continue;
        }

        fscanf(fp, "%d %d %d ", &i, &j, &k);
        cpu_usage = (i * 100) / (j + k);

        printf("%4d\t\t%3d\t\t%s\n", proc_num, cpu_usage, proc_name);

        fclose(fp);
    }

    fclose(fp);
    total_usage = 0;
    for (i = 0; i < MAX_PROC_NUM; i++)
    {
        total_usage += cpu_usage;
    }

    printf("Total CPU Usage: %.2f%%", (total_usage * 100) / MAX_PROC_NUM);

    return 0;
}