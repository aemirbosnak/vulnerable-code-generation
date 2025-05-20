//MISTRAL-7B DATASET v1.0 Category: CPU usage monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>

#define PROC_STAT "/proc/stat"
#define CPUID "cpu"
#define BUF_SIZE 128

fd_set master_set;
int fd;
char buf[BUF_SIZE];

int get_cpu_usage(int *prev_total, int *prev_idle) {
    int total, idle, i;
    FILE *fp;

    fp = fopen(PROC_STAT, "r");
    if (!fp) {
        perror("Error opening proc stat file");
        exit(EXIT_FAILURE);
    }

    fgets(buf, BUF_SIZE, fp);
    sscanf(buf, "%s %*s %d %d", CPUID, &total, &idle);

    if (prev_total && prev_idle) {
        int delta_total = total - prev_total[0];
        int delta_idle = idle - prev_idle[0];

        return (delta_total - delta_idle) * 100 / total;
    }

    prev_total[0] = total;
    prev_idle[0] = idle;

    fclose(fp);
    return 0;
}

int main() {
    int prev_total[1], prev_idle[1];
    int cpu_usage;

    FD_ZERO(&master_set);
    fd = open(PROC_STAT, O_RDONLY);
    FD_SET(fd, &master_set);

    while (1) {
        int ready_fds = select(fd + 1, &master_set, NULL, NULL, NULL);
        if (ready_fds < 0) {
            perror("Error in select()");
            exit(EXIT_FAILURE);
        }

        if (FD_ISSET(fd, &master_set)) {
            cpu_usage = get_cpu_usage(prev_total, prev_idle);
            printf("CPU usage: %d%%\n", cpu_usage);
        }

        usleep(100000);
    }

    close(fd);
    return 0;
}