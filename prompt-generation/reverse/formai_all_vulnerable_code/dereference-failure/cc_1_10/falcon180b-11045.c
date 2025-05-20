//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>

#define MAX_CPU_PERCENTAGE 100

void monitor_cpu_usage(int interval) {
    struct rusage usage;
    int cpu_percentage = 0;
    int prev_total_cpu_time = 0;

    while (1) {
        if (getrusage(RUSAGE_SELF, &usage) == -1) {
            printf("Error getting CPU usage\n");
            exit(1);
        }

        int total_cpu_time = usage.ru_utime.tv_sec + usage.ru_stime.tv_sec +
                             usage.ru_utime.tv_usec + usage.ru_stime.tv_usec;

        if (prev_total_cpu_time == 0) {
            prev_total_cpu_time = total_cpu_time;
            continue;
        }

        cpu_percentage = (int) (((float) (total_cpu_time - prev_total_cpu_time) / interval) * MAX_CPU_PERCENTAGE);

        printf("CPU usage: %d%%\n", cpu_percentage);

        prev_total_cpu_time = total_cpu_time;

        usleep(interval * 1000);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <interval_in_seconds>\n", argv[0]);
        return 1;
    }

    int interval = atoi(argv[1]);

    if (interval <= 0) {
        printf("Invalid interval\n");
        return 1;
    }

    monitor_cpu_usage(interval);

    return 0;
}