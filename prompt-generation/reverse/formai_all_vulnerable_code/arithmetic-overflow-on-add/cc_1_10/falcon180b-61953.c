//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define BUF_SIZE 256

int main() {
    int i;
    double total_cpu = 0.0;
    double prev_total_cpu = 0.0;
    char buffer[BUF_SIZE];
    FILE *fp;

    while (1) {
        fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            printf("Error opening /proc/stat.\n");
            exit(1);
        }

        fgets(buffer, BUF_SIZE, fp);
        fclose(fp);

        sscanf(buffer, "cpu %lf %lf %lf %lf", &total_cpu, &total_cpu, &total_cpu, &total_cpu);

        if (i == 0) {
            prev_total_cpu = total_cpu;
        } else {
            double idle_cpu = (total_cpu - prev_total_cpu) / (double) i;
            double busy_cpu = 1.0 - idle_cpu;

            printf("CPU Usage: %.2f%%\n", busy_cpu * 100.0);

            prev_total_cpu = total_cpu;
        }

        usleep(1000000); // 1 second
        i++;
    }

    return 0;
}