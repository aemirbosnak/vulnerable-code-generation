//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define BUF_SIZE 4096

int main() {
    FILE *fp;
    char buf[BUF_SIZE];
    int user, nice, system, idle, iowait, irq, softirq, steal;
    char *s;
    long double prev_total, prev_idle;
    long double cpu_usage;

    while (1) {
        fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            perror("fopen");
            return EXIT_FAILURE;
        }

        s = fgets(buf, BUF_SIZE, fp);
        while (s != NULL && strncmp(s, "cpu ", 4) != 0) {
            s = fgets(buf, BUF_SIZE, fp);
        }

        if (s == NULL) {
            fclose(fp);
            perror("fgets");
            return EXIT_FAILURE;
        }

        sscanf(s, "cpu %d %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
        fclose(fp);

        long double total = (long double)(user + nice + system + idle + iowait + irq + softirq + steal);
        long double delta_idle = (long double)(idle - prev_idle);
        long double delta_total = (long double)(total - prev_total);

        cpu_usage = 100.0 * (delta_total - delta_idle) / delta_total;

        prev_total = total;
        prev_idle = idle;

        printf("CPU usage: %.2Lf%%\n", cpu_usage);

        sleep(1);
    }

    return EXIT_SUCCESS;
}