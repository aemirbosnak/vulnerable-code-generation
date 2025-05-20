//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PROC_SELF_STAT "/proc/self/stat"
#define PROC_SELF_STATM "/proc/self/statm"

int get_cpu_percent(void) {
    FILE *fp;
    char filename[32];
    int total, idle, percent;

    sprintf(filename, "/proc/%d/stat", getpid());
    fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    fscanf(fp, "cpu %d %d %d %d", &total, &idle, &total, &idle);
    percent = ((total - idle) * 100) / total;

    fclose(fp);
    return percent;
}

int get_memory_percent(void) {
    FILE *fp;
    char filename[32];
    int total, free, percent;

    sprintf(filename, "/proc/%d/statm", getpid());
    fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }

    fscanf(fp, "%d %d %d %d %d %d %d", &total, &free, &total, &free, &total, &free, &total);
    percent = ((total - free) * 100) / total;

    fclose(fp);
    return percent;
}

int main() {
    int cpu_percent, memory_percent;

    while (1) {
        cpu_percent = get_cpu_percent();
        memory_percent = get_memory_percent();

        printf("CPU usage: %d%%\n", cpu_percent);
        printf("Memory usage: %d%%\n", memory_percent);

        sleep(1);
    }

    return 0;
}