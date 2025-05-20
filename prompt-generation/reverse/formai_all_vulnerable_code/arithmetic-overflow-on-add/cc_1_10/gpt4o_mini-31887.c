//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256
#define SLEEP_INTERVAL 1

void handle_exit(int sig) {
    printf("\nEnding the CPU usage monitoring gracefully...\n");
    exit(0);
}

float get_cpu_usage() {
    static long double previous_idle_time = 0.0, previous_total_time = 0.0;
    long double idle_time, total_time;
    long double cpu_usage;

    FILE *fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Unable to read CPU stats");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    if (fgets(buffer, BUFFER_SIZE, fp) == NULL) {
        perror("Error reading CPU stats");
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    fclose(fp);

    long user_time, nice_time, system_time, idle_time_current, iowait_time, irq_time, softirq_time;
    sscanf(buffer, "cpu %ld %ld %ld %ld %ld %ld %ld %ld",
           &user_time, &nice_time, &system_time,
           &idle_time_current, &iowait_time, &irq_time, &softirq_time);

    idle_time = idle_time_current + iowait_time;
    total_time = user_time + nice_time + system_time + idle_time_current + iowait_time + irq_time + softirq_time;

    cpu_usage = (1.0 - (idle_time - previous_idle_time) / (total_time - previous_total_time)) * 100.0;

    previous_idle_time = idle_time;
    previous_total_time = total_time;

    return cpu_usage;
}

void display_usage(float cpu_usage) {
    printf("\rCurrent CPU Usage: %.2f%%", cpu_usage);
    fflush(stdout);
}

void log_cpu_usage(float cpu_usage) {
    FILE *logfile = fopen("cpu_usage.log", "a");
    if (logfile == NULL) {
        perror("Error opening the log file");
        exit(EXIT_FAILURE);
    }
    fprintf(logfile, "CPU Usage: %.2f%%\n", cpu_usage);
    fclose(logfile);
}

int main() {
    signal(SIGINT, handle_exit);
    
    printf("~~~ Welcome to the Ultimate CPU Usage Monitor ~~~\n");
    printf("Press Ctrl+C to exit the application.\n");
    
    while (1) {
        float cpu_usage = get_cpu_usage();
        display_usage(cpu_usage);
        log_cpu_usage(cpu_usage);
        sleep(SLEEP_INTERVAL);
    }

    return 0;
}