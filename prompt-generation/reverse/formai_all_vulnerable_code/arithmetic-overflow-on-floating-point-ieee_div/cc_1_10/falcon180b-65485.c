//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024

int main() {
    char buf[BUF_SIZE];
    FILE *fp;
    double cpu_percent = 0.0, prev_idle = 0.0, prev_total = 0.0;
    int i, j, count = 0;

    // Open /proc/stat file for reading
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: Unable to open /proc/stat\n");
        exit(1);
    }

    // Read the first line of /proc/stat to get the total number of processors
    fgets(buf, BUF_SIZE, fp);
    sscanf(buf, "cpu %d", &count);

    // Loop through each processor and calculate the CPU usage
    for (i = 0; i < count; i++) {
        while (fgets(buf, BUF_SIZE, fp)!= NULL) {
            if (strncmp(buf, "cpu", 3) == 0) {
                sscanf(buf, "cpu%d %lf %lf %lf %lf", &i, &cpu_percent, &prev_idle, &prev_total, &j);
                break;
            }
        }
        if (i == count) {
            printf("Error: Unable to find CPU%d\n", i);
            exit(1);
        }
    }

    // Calculate the current CPU usage
    usleep(100000); // Wait for 100ms to get a more accurate reading
    fgets(buf, BUF_SIZE, fp);
    sscanf(buf, "cpu %d %lf %lf %lf %lf", &i, &cpu_percent, &prev_idle, &prev_total, &j);
    cpu_percent = (100.0 - (prev_idle + prev_total - cpu_percent)) / (double)count;

    // Print the CPU usage
    printf("CPU Usage: %.2f%%\n", cpu_percent);

    fclose(fp);
    return 0;
}