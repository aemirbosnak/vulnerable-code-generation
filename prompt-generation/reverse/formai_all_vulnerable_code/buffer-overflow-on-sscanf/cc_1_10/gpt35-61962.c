//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CPU_NUM 8
#define STAT_FILE "/proc/stat"

/* function to get the CPU usage information */
void get_cpu_usage(unsigned long long *prev_total_time, unsigned long long *prev_idle_time,
    unsigned long long *curr_total_time, unsigned long long *curr_idle_time)
{
    FILE *fp;
    unsigned long long cpu_user_time, cpu_system_time, cpu_idle_time, cpu_iowait_time, cpu_others_time;

    fp = fopen(STAT_FILE, "r");
    if (!fp) {
        printf("Failed to open %s file.\n", STAT_FILE);
        exit(EXIT_FAILURE);
    }

    char buf[1024];
    while (fgets(buf, sizeof(buf), fp)) {
        if (!strncmp(buf, "cpu ", 4)) {
            sscanf(buf, "cpu  %llu %llu %llu %llu %llu", &cpu_user_time, &cpu_system_time, &cpu_idle_time,
                &cpu_iowait_time, &cpu_others_time);
            break;
        }
    }
    fclose(fp);

    *curr_total_time = cpu_user_time + cpu_system_time + cpu_idle_time + cpu_iowait_time + cpu_others_time;
    *curr_idle_time = cpu_idle_time;

    if (*prev_total_time == 0) {
        *prev_total_time = *curr_total_time;
        *prev_idle_time = *curr_idle_time;
    }
}

/* main function */
int main(int argc, char *argv[])
{
    unsigned long long prev_total_time[MAX_CPU_NUM] = {0}, prev_idle_time[MAX_CPU_NUM] = {0};
    unsigned long long curr_total_time[MAX_CPU_NUM], curr_idle_time[MAX_CPU_NUM];

    printf("\n");

    for (;;) {
        /* Clear the screen */
        printf("\033c");

        /* Print the header */
        printf("CPU\t\tUsage\n");

        for (int cpuid = 0; cpuid < MAX_CPU_NUM; cpuid++) {
            /* Get the CPU usage */
            get_cpu_usage(&prev_total_time[cpuid], &prev_idle_time[cpuid], &curr_total_time[cpuid], &curr_idle_time[cpuid]);

            /* Calculate the CPU usage percentage */
            float cpu_usage_pct = (curr_total_time[cpuid] - prev_total_time[cpuid]) > 0 ? 
                                ((float)(curr_total_time[cpuid] - prev_total_time[cpuid]) - 
                                (float)(curr_idle_time[cpuid] - prev_idle_time[cpuid])) /
                                (float)(curr_total_time[cpuid] - prev_total_time[cpuid]) * 100 : 0;

            /* Print the CPU usage */
            printf("CPU%d\t\t%.2f%%\n", cpuid, cpu_usage_pct);
        }

        /* Sleep for 1 second */
        sleep(1);
    }

    return EXIT_SUCCESS;
}