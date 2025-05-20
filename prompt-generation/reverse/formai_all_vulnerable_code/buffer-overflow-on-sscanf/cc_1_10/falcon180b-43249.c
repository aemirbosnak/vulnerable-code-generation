//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

#define PROC_STAT "/proc/stat"
#define PROC_SELF_STAT "/proc/self/stat"
#define PROC_PID_STAT(pid) "/proc/" #pid "/stat"

struct proc_stat {
    unsigned long long cpu_user;
    unsigned long long cpu_nice;
    unsigned long long cpu_system;
    unsigned long long cpu_idle;
    unsigned long long cpu_iowait;
    unsigned long long cpu_irq;
    unsigned long long cpu_softirq;
    unsigned long long cpu_steal;
    unsigned long long cpu_guest;
    unsigned long long cpu_guest_nice;
};

int get_proc_stat(const char* filename, struct proc_stat* stat) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return -1;
    }

    char line[1024];
    ssize_t n = read(fd, line, sizeof(line));
    if (n <= 0) {
        close(fd);
        return -1;
    }

    close(fd);

    sscanf(line, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu",
           &stat->cpu_user, &stat->cpu_nice, &stat->cpu_system, &stat->cpu_idle,
           &stat->cpu_iowait, &stat->cpu_irq, &stat->cpu_softirq, &stat->cpu_steal,
           &stat->cpu_guest, &stat->cpu_guest_nice);

    return 0;
}

int get_cpu_percent(const struct proc_stat* stat) {
    unsigned long long total = stat->cpu_user + stat->cpu_nice + stat->cpu_system + stat->cpu_idle + stat->cpu_iowait + stat->cpu_irq + stat->cpu_softirq + stat->cpu_steal + stat->cpu_guest + stat->cpu_guest_nice;
    return (total > 0)? (stat->cpu_user * 100) / total : 0;
}

int main() {
    struct proc_stat stat;

    if (get_proc_stat(PROC_STAT, &stat) == -1) {
        printf("Error reading %s\n", PROC_STAT);
        return 1;
    }

    printf("CPU usage: %d%%\n", get_cpu_percent(&stat));

    return 0;
}