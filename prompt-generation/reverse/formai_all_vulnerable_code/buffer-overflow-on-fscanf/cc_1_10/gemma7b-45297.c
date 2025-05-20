//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>

#define PROC_NAME "my_proc"
#define SAMPLE_TIME 5

int main()
{
    long int prev_user, prev_system, prev_idle, prev_total;
    long int user, system, idle, total;
    long int i = 0;

    FILE *fp = fopen("/proc/stat", "r");

    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    prev_user = prev_system = prev_idle = prev_total = 0;

    while (i < SAMPLE_TIME)
    {
        fscanf(fp, "%ld %ld %ld %ld", &user, &system, &idle, &total);

        user = system = idle = total = 0;

        prev_user = user;
        prev_system = system;
        prev_idle = idle;
        prev_total = total;

        sleep(1);
        i++;
    }

    fclose(fp);

    printf("Average CPU usage:\n");
    printf("  User: %.2f%%  System: %.2f%%  Idle: %.2f%%  Total: %.2f%%",
           (prev_user - user) * 100.0 / prev_total,
           (prev_system - system) * 100.0 / prev_total,
           (prev_idle - idle) * 100.0 / prev_total,
           (prev_total - user - system - idle) * 100.0 / prev_total);

    return 0;
}