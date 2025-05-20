//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <signal.h>
#include <errno.h>

#define SLEEP_INTERVAL 1

void sigint_handler(int sig) {
    printf("\nExiting CPU Usage Monitor...\n");
    exit(0);
}

void display_cpu_usage() {
    long double a[4], b[4], loadavg;
    int i;

    while (1) {
        struct sysinfo info;
        if (sysinfo(&info) == -1) {
            perror("sysinfo");
            exit(1);
        }

        FILE *fp = fopen("/proc/stat", "r");
        if (fp == NULL) {
            perror("fopen");
            exit(1);
        }

        if (fgets((char *)a, sizeof(a), fp) == NULL) {
            perror("fgets");
            fclose(fp);
            exit(1);
        }

        long long idle, total;
        sscanf((char *)a, "cpu %Lf %Lf %Lf %Lf", &b[0], &b[1], &b[2], &b[3]);
        
        idle = b[3];
        total = b[0] + b[1] + b[2] + b[3];

        sleep(SLEEP_INTERVAL);
        
        rewind(fp);
        if (fgets((char *)a, sizeof(a), fp) == NULL) {
            perror("fgets");
            fclose(fp);
            exit(1);
        }

        sscanf((char *)a, "cpu %Lf %Lf %Lf %Lf", &b[0], &b[1], &b[2], &b[3]);
        
        long long idle_diff = b[3] - idle;
        long long total_diff = (b[0] + b[1] + b[2] + b[3]) - total;

        loadavg = (1.0 - (idle_diff / (long double)total_diff)) * 100;

        printf("\rCPU Usage: %.2Lf%%  ", loadavg);
        fflush(stdout);
        fclose(fp);
    }
}

int main() {
    signal(SIGINT, sigint_handler);
    printf("Welcome to the CPU Usage Monitor! Press Ctrl+C to exit.\n");

    display_cpu_usage();

    return 0;
}