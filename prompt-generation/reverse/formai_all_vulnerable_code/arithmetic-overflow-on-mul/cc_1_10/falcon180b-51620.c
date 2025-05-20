//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PROC_FILE "/proc/stat"
#define PROC_SELF "/proc/self/stat"

struct proc_stat {
    long int cpu_user;
    long int cpu_nice;
    long int cpu_system;
    long int cpu_idle;
    long int cpu_iowait;
    long int cpu_irq;
    long int cpu_softirq;
    long int cpu_steal;
    long int cpu_guest;
    long int cpu_guest_nice;
};

int main(int argc, char *argv[]) {
    int fd;
    char buffer[1024];
    struct proc_stat proc_stat;

    fd = open(PROC_FILE, O_RDONLY);
    if (fd == -1) {
        printf("Error opening %s\n", PROC_FILE);
        exit(1);
    }

    if (read(fd, buffer, sizeof(buffer)) == -1) {
        printf("Error reading %s\n", PROC_FILE);
        exit(1);
    }

    close(fd);

    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
           &proc_stat.cpu_user, &proc_stat.cpu_nice, &proc_stat.cpu_system,
           &proc_stat.cpu_idle, &proc_stat.cpu_iowait, &proc_stat.cpu_irq,
           &proc_stat.cpu_softirq, &proc_stat.cpu_steal, &proc_stat.cpu_guest,
           &proc_stat.cpu_guest_nice);

    fd = open(PROC_SELF, O_RDONLY);
    if (fd == -1) {
        printf("Error opening %s\n", PROC_SELF);
        exit(1);
    }

    if (read(fd, buffer, sizeof(buffer)) == -1) {
        printf("Error reading %s\n", PROC_SELF);
        exit(1);
    }

    close(fd);

    sscanf(buffer, "cpu %ld %ld %ld %ld", &proc_stat.cpu_user, &proc_stat.cpu_nice,
           &proc_stat.cpu_system, &proc_stat.cpu_idle);

    printf("CPU Usage:\n");
    printf("User: %ld%%\n", (proc_stat.cpu_user - proc_stat.cpu_idle) * 100 / (proc_stat.cpu_user + proc_stat.cpu_nice + proc_stat.cpu_system + proc_stat.cpu_idle));
    printf("Nice: %ld%%\n", (proc_stat.cpu_nice - proc_stat.cpu_idle) * 100 / (proc_stat.cpu_user + proc_stat.cpu_nice + proc_stat.cpu_system + proc_stat.cpu_idle));
    printf("System: %ld%%\n", (proc_stat.cpu_system - proc_stat.cpu_idle) * 100 / (proc_stat.cpu_user + proc_stat.cpu_nice + proc_stat.cpu_system + proc_stat.cpu_idle));
    printf("Idle: %ld%%\n", (proc_stat.cpu_idle - proc_stat.cpu_idle) * 100 / (proc_stat.cpu_user + proc_stat.cpu_nice + proc_stat.cpu_system + proc_stat.cpu_idle));

    return 0;
}