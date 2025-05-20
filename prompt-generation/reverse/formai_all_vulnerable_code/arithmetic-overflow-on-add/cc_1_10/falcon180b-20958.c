//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/resource.h>

#define INTERVAL 1 // seconds

void print_cpu_usage(double cpu_percent) {
    printf("CPU Usage: %.2f%%\n", cpu_percent);
}

int main() {
    int fd;
    struct rusage usage;
    double cpu_percent;

    if ((fd = open("/proc/self/stat", O_RDONLY)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (fstat(fd, &usage) == -1) {
        perror("fstat");
        exit(EXIT_FAILURE);
    }

    gettimeofday(&usage.ru_utime, NULL);
    gettimeofday(&usage.ru_stime, NULL);

    close(fd);

    cpu_percent = (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) / (double)INTERVAL * 100.0;

    print_cpu_usage(cpu_percent);

    while (1) {
        sleep(INTERVAL);
        if ((fd = open("/proc/self/stat", O_RDONLY)) == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        if (fstat(fd, &usage) == -1) {
            perror("fstat");
            exit(EXIT_FAILURE);
        }

        gettimeofday(&usage.ru_utime, NULL);
        gettimeofday(&usage.ru_stime, NULL);

        close(fd);

        cpu_percent = (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) / (double)INTERVAL * 100.0;

        print_cpu_usage(cpu_percent);
    }

    return 0;
}