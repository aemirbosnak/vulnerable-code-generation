//Code Llama-13B DATASET v1.0 Category: CPU usage monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>

#define NUM_CPUS 4

typedef struct {
    float user;
    float nice;
    float system;
    float idle;
    float iowait;
    float irq;
    float softirq;
    float steal;
    float guest;
    float guest_nice;
} cpu_usage_t;

void get_cpu_usage(cpu_usage_t *usage) {
    int i;
    char line[1024];
    FILE *fp;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: unable to open /proc/stat\n");
        exit(1);
    }

    for (i = 0; i < NUM_CPUS; i++) {
        if (fgets(line, sizeof(line), fp) == NULL) {
            printf("Error: unable to read /proc/stat\n");
            exit(1);
        }

        if (sscanf(line, "cpu%d %f %f %f %f %f %f %f %f %f", &i, &usage[i].user, &usage[i].nice, &usage[i].system, &usage[i].idle, &usage[i].iowait, &usage[i].irq, &usage[i].softirq, &usage[i].steal, &usage[i].guest) != 10) {
            printf("Error: unable to parse /proc/stat\n");
            exit(1);
        }
    }

    fclose(fp);
}

int main() {
    cpu_usage_t usage[NUM_CPUS];
    int i;

    for (i = 0; i < NUM_CPUS; i++) {
        get_cpu_usage(&usage[i]);
        printf("CPU%d usage: user=%f, nice=%f, system=%f, idle=%f, iowait=%f, irq=%f, softirq=%f, steal=%f, guest=%f\n", i, usage[i].user, usage[i].nice, usage[i].system, usage[i].idle, usage[i].iowait, usage[i].irq, usage[i].softirq, usage[i].steal, usage[i].guest);
    }

    return 0;
}