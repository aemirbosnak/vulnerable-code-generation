//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PROC_DIR "/proc"
#define PROC_CPU_STAT "/cpu_stat"
#define PROC_CPU_STAT_SIZE 1024
#define PROC_CPU_STAT_FMT "%d %d %d %d %d %d %d\n"

int get_cpu_stats(double *user, double *system, double *idle, double *iowait, double *irq, double *softirq, double *steal) {
    char cpu_stat_path[PROC_CPU_STAT_SIZE];
    snprintf(cpu_stat_path, PROC_CPU_STAT_SIZE, "%s/%d/stat", PROC_DIR, getpid());

    int fd = open(cpu_stat_path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    char cpu_stat[PROC_CPU_STAT_SIZE];
    ssize_t bytes_read = read(fd, cpu_stat, PROC_CPU_STAT_SIZE - 1);
    if (bytes_read == -1) {
        perror("read");
        close(fd);
        return -1;
    }

    close(fd);
    cpu_stat[bytes_read] = '\0';

    sscanf(cpu_stat, PROC_CPU_STAT_FMT, user, system, idle, iowait, irq, softirq, steal);

    return 0;
}

int main() {
    double user, system, idle, iowait, irq, softirq, steal;
    if (get_cpu_stats(&user, &system, &idle, &iowait, &irq, &softirq, &steal)) {
        fprintf(stderr, "Error getting CPU stats\n");
        return 1;
    }

    printf("CPU Usage:\n");
    printf("User: %.2f%%\n", user);
    printf("System: %.2f%%\n", system);
    printf("Idle: %.2f%%\n", idle);
    printf("I/O Wait: %.2f%%\n", iowait);
    printf("IRQ: %.2f%%\n", irq);
    printf("Soft IRQ: %.2f%%\n", softirq);
    printf("Steal: %.2f%%\n", steal);

    return 0;
}