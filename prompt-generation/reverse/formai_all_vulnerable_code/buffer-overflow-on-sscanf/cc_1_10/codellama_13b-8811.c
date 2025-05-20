//Code Llama-13B DATASET v1.0 Category: CPU usage monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_CPU_COUNT 10

struct cpu_usage {
    int cpu_num;
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
};

struct cpu_usage get_cpu_usage(int cpu_num) {
    FILE *fp;
    char line[1024];
    struct cpu_usage usage;

    memset(&usage, 0, sizeof(struct cpu_usage));

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strncmp(line, "cpu", 3) == 0) {
            sscanf(line, "cpu%d %f %f %f %f %f %f %f %f %f %f", &usage.cpu_num, &usage.user, &usage.nice, &usage.system, &usage.idle, &usage.iowait, &usage.irq, &usage.softirq, &usage.steal, &usage.guest, &usage.guest_nice);
            break;
        }
    }

    fclose(fp);

    return usage;
}

int main(void) {
    int i;
    struct cpu_usage usage;

    for (i = 0; i < MAX_CPU_COUNT; i++) {
        usage = get_cpu_usage(i);
        printf("CPU%d: user=%f, nice=%f, system=%f, idle=%f, iowait=%f, irq=%f, softirq=%f, steal=%f, guest=%f, guest_nice=%f\n", usage.cpu_num, usage.user, usage.nice, usage.system, usage.idle, usage.iowait, usage.irq, usage.softirq, usage.steal, usage.guest, usage.guest_nice);
    }

    return 0;
}