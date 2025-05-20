//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main() {
    FILE *fp;
    char buf[BUF_SIZE];
    int pid;
    int status;
    int i;
    int j;
    int k;
    float cpu_usage;

    printf("Enter the PID of the process to monitor: ");
    scanf("%d", &pid);

    fp = fopen("/proc/stat", "r");

    if (fp == NULL) {
        printf("Error opening /proc/stat\n");
        exit(1);
    }

    while (fgets(buf, BUF_SIZE, fp)!= NULL) {
        if (strncmp(buf, "cpu ", 4) == 0) {
            sscanf(buf, "cpu %d %d %d %d", &i, &j, &k, &i);
            break;
        }
    }

    fclose(fp);

    while (1) {
        sleep(1);

        fp = fopen("/proc/stat", "r");

        if (fp == NULL) {
            printf("Error opening /proc/stat\n");
            exit(1);
        }

        while (fgets(buf, BUF_SIZE, fp)!= NULL) {
            if (strncmp(buf, "cpu ", 4) == 0) {
                sscanf(buf, "cpu %d %d %d %d", &i, &j, &k, &i);
                break;
            }
        }

        fclose(fp);

        cpu_usage = ((float) (k - j) / (i - j)) * 100;

        printf("CPU usage: %.2f%%\n", cpu_usage);
    }

    return 0;
}