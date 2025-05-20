//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <signal.h>
#include <stdbool.h>
#include <time.h>

#define INTERVAL_SEC 1

volatile sig_atomic_t keepRunning = true;

void handleSignal(int signal) {
    if (signal == SIGINT) {
        keepRunning = false;
    }
}

void getCpuUsage(float *usage) {
    FILE *fp;
    long total1, total2, idle1, idle2;
    char buffer[1024];

    // Read CPU stats from /proc/stat
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    // Read the first line (cpu)
    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "cpu %ld %*s %*s %ld", &total1, &idle1);
    fclose(fp);

    sleep(INTERVAL_SEC);

    // Read CPU stats again after interval
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        exit(EXIT_FAILURE);
    }

    fgets(buffer, sizeof(buffer), fp);
    sscanf(buffer, "cpu %ld %*s %*s %ld", &total2, &idle2);
    fclose(fp);

    // Calculate CPU usage
    long total_time = total2 - total1;
    long idle_time = idle2 - idle1;
    *usage = 100.0 * (total_time - idle_time) / total_time;
}

void displayCpuUsage() {
    float cpuUsage;
    time_t now;
    char timeString[100];

    while (keepRunning) {
        getCpuUsage(&cpuUsage);
        now = time(NULL);
        strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", localtime(&now));
        
        printf("\r[%s] CPU Usage: %.2f%%       ", timeString, cpuUsage);
        fflush(stdout);
    }
    printf("\nExiting...\n");
}

int main() {
    signal(SIGINT, handleSignal);

    printf("Starting CPU usage monitor. Press Ctrl+C to stop.\n");
    displayCpuUsage();

    return 0;
}