//Code Llama-13B DATASET v1.0 Category: CPU usage monitor ; Style: Claude Shannon
/*
 * CPU Usage Monitor
 *
 * This program will monitor the CPU usage of a Linux system and log it to a file.
 * It will use the proc filesystem to gather information about the CPU usage and
 * the time spent in different states.
 *
 * Usage:
 * ./cpu_usage_monitor [interval]
 *
 * where [interval] is the time interval in seconds between each measurement.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <interval>\n", argv[0]);
        exit(1);
    }

    int interval = atoi(argv[1]);

    FILE *fp = fopen("cpu_usage.log", "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    while (1) {
        char buf[BUF_SIZE];
        int fd = open("/proc/stat", O_RDONLY);
        if (fd < 0) {
            perror("Error opening /proc/stat");
            exit(1);
        }

        int n = read(fd, buf, BUF_SIZE);
        if (n < 0) {
            perror("Error reading /proc/stat");
            exit(1);
        }

        buf[n] = '\0';
        fprintf(fp, "%s\n", buf);

        close(fd);

        sleep(interval);
    }

    fclose(fp);

    return 0;
}