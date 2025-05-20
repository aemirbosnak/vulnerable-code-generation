//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct cpu_usage {
    long long user;
    long long nice;
    long long system;
    long long idle;
    long long iowait;
    long long irq;
    long long softirq;
};

int main() {
    FILE *fp;
    char buf[1024];
    struct cpu_usage usage;
    long long total_usage;
    long long idle_usage;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        if (sscanf(buf, "cpu %llu %llu %llu %llu %llu %llu %llu", &usage.user, &usage.nice, &usage.system, &usage.idle, &usage.iowait, &usage.irq, &usage.softirq) == 7) {
            total_usage = usage.user + usage.nice + usage.system + usage.idle + usage.iowait + usage.irq + usage.softirq;
            idle_usage = usage.idle;
            break;
        }
    }

    fclose(fp);

    while (1) {
        fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            perror("fopen");
            return EXIT_FAILURE;
        }

        while (fgets(buf, sizeof(buf), fp) != NULL) {
            if (sscanf(buf, "cpu %llu %llu %llu %llu %llu %llu %llu", &usage.user, &usage.nice, &usage.system, &usage.idle, &usage.iowait, &usage.irq, &usage.softirq) == 7) {
                total_usage = usage.user + usage.nice + usage.system + usage.idle + usage.iowait + usage.irq + usage.softirq;
                idle_usage = usage.idle;
                break;
            }
        }

        fclose(fp);

        double cpu_usage = (double)(total_usage - idle_usage) / (total_usage - (idle_usage - idle_usage)) * 100.0;
        printf("I am so grateful for your work! Your CPU usage is %.2f%%.\n", cpu_usage);

        sleep(1);
    }

    return EXIT_SUCCESS;
}