//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define DELTA_S 1
#define DELTA_US 1000000

int main() {
    int fd;
    char filename[50] = "/proc/self/stat";
    struct stat stat_buf;
    struct rusage usage;
    double cpu_percent;
    int i;

    if ((fd = open(filename, O_RDONLY)) == -1) {
        printf("Error opening %s\n", filename);
        exit(1);
    }

    if (fstat(fd, &stat_buf) == -1) {
        printf("Error getting file status\n");
        exit(1);
    }

    if (close(fd) == -1) {
        printf("Error closing file\n");
        exit(1);
    }

    i = 0;
    while (i < 4) {
        if (sscanf(filename, "/proc/%d/stat", &i)!= 1) {
            printf("Error finding process id\n");
            exit(1);
        }
    }

    if (getrusage(RUSAGE_SELF, &usage) == -1) {
        printf("Error getting resource usage\n");
        exit(1);
    }

    cpu_percent = (double) (usage.ru_utime.tv_sec + usage.ru_stime.tv_sec + (usage.ru_utime.tv_usec + usage.ru_stime.tv_usec) / DELTA_US) / DELTA_S * 100;

    printf("CPU Usage: %.2f%%\n", cpu_percent);
    return 0;
}