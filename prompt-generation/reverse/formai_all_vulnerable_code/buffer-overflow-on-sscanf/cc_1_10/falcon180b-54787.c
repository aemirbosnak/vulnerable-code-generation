//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    int cpu_percentage = 0;
    int prev_idle = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fgets(buffer, BUFFER_SIZE, fp)!= NULL) {
        if (strncmp(buffer, "cpu ", 4) == 0) {
            sscanf(buffer, "cpu %d %d %d %d", &cpu_percentage, &prev_idle, &prev_idle, &prev_idle);
            break;
        }
    }

    fclose(fp);

    while (1) {
        sleep(1);

        fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            printf("Error opening file!\n");
            exit(1);
        }

        while (fgets(buffer, BUFFER_SIZE, fp)!= NULL) {
            if (strncmp(buffer, "cpu ", 4) == 0) {
                sscanf(buffer, "cpu %d %d %d %d", &cpu_percentage, &prev_idle, &prev_idle, &prev_idle);
                break;
            }
        }

        fclose(fp);

        if (cpu_percentage > 0) {
            printf("CPU usage: %.2f%%\n", (float)cpu_percentage / (cpu_percentage + prev_idle) * 100.0);
        } else {
            printf("CPU usage: 0.00%%\n");
        }
    }

    return 0;
}