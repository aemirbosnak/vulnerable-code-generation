//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

struct sys_info {
    long uptime_seconds;
    double cpu_load;
};

void print_stats(struct sys_info *info)
{
    printf("Uptime: %ld seconds\n", info->uptime_seconds);
    printf("CPU Usage: %.2f%%\n", info->cpu_load);
}

void get_sys_info(struct sys_info *info)
{
    struct sysinfo si;
    if (sysinfo(&si) != 0) {
        fprintf(stderr, "Error getting system information.\n");
        exit(EXIT_FAILURE);
    }

    info->uptime_seconds = si.uptime;

    double load = (double)(si.loads[0]) / (double)(1 << SI_LOAD_SHIFT);
    info->cpu_load = (load / (double)si.procs) * 100.0;
}

int main(void)
{
    struct sys_info info;
    memset(&info, 0, sizeof(info));

    while (1) {
        get_sys_info(&info);
        system("clear"); // Clears the console screen

        printf("Current System Stats:\n");
        printf("========================\n\n");
        print_stats(&info);
        printf("\n\n");

        sleep(1); // Wait for 1 second
    }

    return 0;
}