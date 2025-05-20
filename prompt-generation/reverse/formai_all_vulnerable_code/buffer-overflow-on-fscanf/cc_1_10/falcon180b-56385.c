//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define BUF_SIZE 1024

struct stats {
    double cpu_usage;
    double mem_usage;
    double swap_usage;
};

void get_cpu_usage(struct stats *stats) {
    FILE *fp;
    char filename[BUF_SIZE];
    snprintf(filename, BUF_SIZE, "/proc/%d/stat", getpid());
    fp = fopen(filename, "r");
    if (fp!= NULL) {
        int count = fscanf(fp, "cpu %*d %*d %*d %*d %lu %lu %lu %lu", &stats->cpu_usage, &stats->cpu_usage, &stats->cpu_usage, &stats->cpu_usage);
        fclose(fp);
    }
}

void get_mem_usage(struct stats *stats) {
    FILE *fp;
    char filename[BUF_SIZE];
    snprintf(filename, BUF_SIZE, "/proc/%d/statm", getpid());
    fp = fopen(filename, "r");
    if (fp!= NULL) {
        int count = fscanf(fp, "%lu", &stats->mem_usage);
        fclose(fp);
    }
}

void get_swap_usage(struct stats *stats) {
    FILE *fp;
    char filename[BUF_SIZE];
    snprintf(filename, BUF_SIZE, "/proc/%d/statm", getpid());
    fp = fopen(filename, "r");
    if (fp!= NULL) {
        int count = fscanf(fp, "%lu", &stats->swap_usage);
        fclose(fp);
    }
}

int main() {
    struct stats stats;
    while (1) {
        get_cpu_usage(&stats);
        get_mem_usage(&stats);
        get_swap_usage(&stats);
        printf("CPU usage: %.2f%%\n", stats.cpu_usage);
        printf("Memory usage: %.2f%%\n", stats.mem_usage);
        printf("Swap usage: %.2f%%\n", stats.swap_usage);
        sleep(1);
    }
    return 0;
}