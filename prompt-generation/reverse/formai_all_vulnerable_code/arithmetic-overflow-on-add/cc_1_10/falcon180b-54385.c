//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <fcntl.h>

#define MB (1024*1024)

/* Function to get disk usage */
long long get_disk_usage(char *path) {
    struct statvfs buf;
    int fd = open(path, O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(1);
    }

    if (fstatvfs(fd, &buf) == -1) {
        perror("fstatvfs");
        exit(1);
    }

    long long total = buf.f_blocks * buf.f_frsize;
    long long free = buf.f_bavail * buf.f_frsize;

    close(fd);

    return total - free;
}

/* Function to get memory usage */
long long get_memory_usage() {
    struct sysinfo info;
    if (sysinfo(&info) == -1) {
        perror("sysinfo");
        exit(1);
    }

    return info.totalram - info.freeram;
}

/* Function to get swap usage */
long long get_swap_usage() {
    struct sysinfo info;
    if (sysinfo(&info) == -1) {
        perror("sysinfo");
        exit(1);
    }

    return info.totalswap - info.freeswap;
}

/* Function to print usage */
void print_usage(char *name, long long usage, long long total) {
    double percent = (double)usage / total * 100.0;

    printf("%s usage: ", name);
    printf("%lld / %lld (%3.2f%%)\n", usage, total, percent);
}

/* Main function */
int main() {
    char *root = "/";
    long long memory_usage = get_memory_usage();
    long long swap_usage = get_swap_usage();
    long long disk_usage = get_disk_usage(root);

    printf("RAM usage:\n");
    print_usage("RAM", memory_usage, memory_usage + swap_usage);

    printf("\nSwap usage:\n");
    print_usage("Swap", swap_usage, memory_usage + swap_usage);

    printf("\nDisk usage:\n");
    print_usage("Disk", disk_usage, disk_usage);

    return 0;
}