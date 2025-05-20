//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>

void display_cpu_usage() {
    FILE *fp;
    char line[128];
    unsigned long long total_user, total_user_nice, total_sys, total_idle, total_iowait, total_steal, total_guest, total_guest_nice;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        return;
    }

    fgets(line, sizeof(line), fp); // Read the first line

    sscanf(line, "cpu %llu %llu %llu %llu %llu %llu %llu %llu", 
           &total_user, &total_user_nice, &total_sys, &total_idle, 
           &total_iowait, &total_steal, &total_guest, &total_guest_nice);
    
    fclose(fp);

    unsigned long long total_cpu = total_user + total_user_nice + total_sys + total_idle + total_iowait + total_steal;
    unsigned long long total_idle_cpu = total_idle + total_iowait;
    double cpu_usage = 100.0 * (1.0 - (double)(total_idle_cpu) / (double)(total_cpu));

    printf("Current CPU Usage: %.2f%%\n", cpu_usage);
}

void peaceful_wait(int seconds) {
    printf("Taking a moment to enjoy a peaceful pause...\n");
    for (int i = seconds; i > 0; --i) {
        printf("Waiting for %d second%s...\n", i, (i > 1) ? "s" : "");
        sleep(1);
    }
}

int main() {
    int monitor_duration;
    printf("Welcome to the peaceful CPU Usage Monitor.\n");
    printf("How many seconds would you like to monitor CPU usage? ");
    scanf("%d", &monitor_duration);

    if (monitor_duration < 1) {
        printf("Please enter a positive number of seconds.\n");
        return 1;
    }

    int interval = 5; // Refresh interval in seconds
    int iterations = monitor_duration / interval;

    for (int i = 0; i < iterations; i++) {
        display_cpu_usage();
        peaceful_wait(interval);
    }

    printf("Thank you for checking your CPU usage with us. Have a calm day!\n");
    return 0;
}