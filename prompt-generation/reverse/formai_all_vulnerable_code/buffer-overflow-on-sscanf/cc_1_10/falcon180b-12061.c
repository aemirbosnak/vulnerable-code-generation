//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAX_CPU_USAGE 100

struct cpu_usage {
    int cpu_percent;
    char cpu_status;
};

void get_cpu_usage(struct cpu_usage *cpu_usage) {
    FILE *fp;
    char line[1024];
    int total_cpu_time = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/stat.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strstr(line, "cpu")!= NULL) {
            sscanf(line, "cpu %d", &total_cpu_time);
            break;
        }
    }

    fclose(fp);

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/stat.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strstr(line, "cpu")!= NULL) {
            sscanf(line, "cpu %d", &cpu_usage->cpu_percent);
            break;
        }
    }

    fclose(fp);

    if (cpu_usage->cpu_percent > MAX_CPU_USAGE) {
        cpu_usage->cpu_percent = MAX_CPU_USAGE;
    }

    if (cpu_usage->cpu_percent > 75) {
        cpu_usage->cpu_status = 'H';
    } else if (cpu_usage->cpu_percent > 50) {
        cpu_usage->cpu_status = 'M';
    } else {
        cpu_usage->cpu_status = 'L';
    }
}

int main() {
    struct cpu_usage cpu_usage;
    int i;

    for (i = 0; i < 10; i++) {
        get_cpu_usage(&cpu_usage);
        printf("CPU Usage: %d%%\n", cpu_usage.cpu_percent);
        printf("CPU Status: %c\n", cpu_usage.cpu_status);
        printf("\n");
        sleep(1);
    }

    return 0;
}