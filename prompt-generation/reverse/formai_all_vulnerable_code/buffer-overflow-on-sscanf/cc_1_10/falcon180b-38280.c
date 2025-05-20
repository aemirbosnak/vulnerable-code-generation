//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/statvfs.h>

#define BUF_SIZE 4096

void print_cpu_usage() {
    FILE *file;
    char buffer[BUF_SIZE];
    int total = 0, idle = 0, iowait = 0;

    file = fopen("/proc/stat", "r");
    if (file == NULL) {
        printf("Error: Could not open /proc/stat\n");
        exit(1);
    }

    while (fgets(buffer, BUF_SIZE, file)!= NULL) {
        if (strncmp(buffer, "cpu ", 4) == 0) {
            sscanf(buffer, "cpu %d %d %d %d", &total, &idle, &iowait, &iowait); // Ignore iowait for simplicity
            break;
        }
    }

    fclose(file);

    printf("CPU usage: %d%%\n", ((total - idle) * 100) / total);
}

void print_mem_usage() {
    struct statvfs buf;

    if (statvfs("/", &buf) == -1) {
        printf("Error: Could not get memory usage\n");
        exit(1);
    }

    printf("Memory usage: %ldMB used, %ldMB total\n", buf.f_blocks * buf.f_bsize / (1024 * 1024), buf.f_blocks * buf.f_bsize / (1024 * 1024));
}

int main() {
    int interval = 5; // Seconds

    while (1) {
        print_cpu_usage();
        print_mem_usage();
        sleep(interval);
    }

    return 0;
}