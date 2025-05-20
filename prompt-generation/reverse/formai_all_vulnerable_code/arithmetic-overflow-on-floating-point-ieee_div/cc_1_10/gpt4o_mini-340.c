//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/sysinfo.h>
#include <time.h>

#define MAX_CPU 100.0
#define SLEEP_INTERVAL 1 // seconds

void signal_handler(int signal) {
    if (signal == SIGINT) {
        printf("\nHappy Monitoring! Thanks for checking CPU usage!\n");
        exit(0);
    }
}

double get_cpu_usage() {
    FILE *fp;
    char line[128];
    double total_idle = 0.0, total_cpu = 0.0;
    unsigned long long int user, nice, system, idle, iowait, irq, softirq;

    fp = fopen("/proc/stat", "r");
    if (!fp) {
        perror("Could not open /proc/stat");
        return -1;
    }
    fgets(line, sizeof(line), fp);
    sscanf(line, "cpu %llu %llu %llu %llu %llu %llu %llu",
           &user, &nice, &system, &idle, &iowait, &irq, &softirq);

    total_idle = idle + iowait;
    total_cpu = user + nice + system + idle + iowait + irq + softirq;

    fclose(fp);

    return ((total_cpu - total_idle) / total_cpu) * MAX_CPU;
}

void print_cpu_usage(double cpu_usage) {
    printf("\rCurrent CPU Usage: ");
    int bar_width = 50;
    int pos = bar_width * (cpu_usage / MAX_CPU);
    
    printf("[");
    for (int i = 0; i < bar_width; ++i) {
        if (i < pos) {
            printf("=");
        } else {
            printf(" ");
        }
    }
    printf("] %.2f%%", cpu_usage);
    fflush(stdout);
}

int main() {
    signal(SIGINT, signal_handler);
    
    printf("🌟 Welcome to the Cheerful CPU Usage Monitor! 🌟\n");
    printf("Press Ctrl+C at any time to exit.\n");

    while (1) {
        double cpu_usage = get_cpu_usage();
        if (cpu_usage >= 0) {
            print_cpu_usage(cpu_usage);
        } else {
            printf("\nOops! Could not retrieve CPU usage. 🤷\n");
        }
        sleep(SLEEP_INTERVAL);
    }

    return 0;
}