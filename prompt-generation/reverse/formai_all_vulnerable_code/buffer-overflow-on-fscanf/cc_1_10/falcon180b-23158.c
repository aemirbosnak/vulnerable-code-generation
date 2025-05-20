//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>

#define CPUS 4

typedef struct {
    int cpu_num;
    int user_percent;
    int system_percent;
    int idle_percent;
} cpu_stats;

void get_cpu_stats(cpu_stats *stats) {
    FILE *fp;
    char filename[20];
    sprintf(filename, "/proc/stat");
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fscanf(fp, "cpu %d %d %d %d", &stats->cpu_num, &stats->user_percent, &stats->system_percent, &stats->idle_percent);
    fclose(fp);
}

void print_cpu_stats(cpu_stats *stats) {
    printf("CPU %d: User %d%% System %d%% Idle %d%%\n", stats->cpu_num, stats->user_percent, stats->system_percent, stats->idle_percent);
}

int main() {
    int i;
    cpu_stats stats[CPUS];

    for (i = 0; i < CPUS; i++) {
        get_cpu_stats(&stats[i]);
        printf("Initial CPU Stats:\n");
        print_cpu_stats(&stats[i]);
    }

    while (1) {
        sleep(5);
        for (i = 0; i < CPUS; i++) {
            get_cpu_stats(&stats[i]);
            printf("Current CPU Stats:\n");
            print_cpu_stats(&stats[i]);
        }
    }

    return 0;
}