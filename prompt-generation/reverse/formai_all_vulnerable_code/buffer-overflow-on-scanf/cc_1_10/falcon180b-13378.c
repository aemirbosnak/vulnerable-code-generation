//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_CPU_USAGE 100

void monitor_cpu_usage(int interval) {
    struct rusage usage;
    int i, j;
    double cpu_usage[MAX_CPU_USAGE];
    double current_cpu_usage = 0.0;

    for (i = 0; i < MAX_CPU_USAGE; i++) {
        cpu_usage[i] = 0.0;
    }

    while (1) {
        if (getrusage(RUSAGE_SELF, &usage) == -1) {
            perror("getrusage");
            exit(1);
        }

        current_cpu_usage = ((double) usage.ru_utime.tv_sec + (double) usage.ru_utime.tv_usec / 1000000.0) / interval;

        for (i = 0; i < MAX_CPU_USAGE; i++) {
            cpu_usage[i] = cpu_usage[i + 1];
        }

        cpu_usage[MAX_CPU_USAGE - 1] = current_cpu_usage;

        for (j = 0; j < MAX_CPU_USAGE; j++) {
            printf("%5.2f%% ", cpu_usage[j] * 100.0);
        }

        printf("\n");

        sleep(interval);
    }
}

int main() {
    int interval;

    printf("Enter the interval in seconds: ");
    scanf("%d", &interval);

    monitor_cpu_usage(interval);

    return 0;
}