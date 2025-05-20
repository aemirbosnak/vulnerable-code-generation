//GPT-4o-mini DATASET v1.0 Category: CPU usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

void get_cpu_usage(double *cpu_usage) {
    long double a[4], b[4];
    FILE *fp;

    // Open the file to read CPU statistics
    fp = fopen("/proc/stat", "r");
    
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        return;
    }
    
    fscanf(fp, "cpu %Lf %Lf %Lf %Lf", &a[0], &a[1], &a[2], &a[3]);
    fclose(fp);
    
    // Sleep for a while before reading again for comparison
    usleep(100000); // Sleep for 100 milliseconds

    fp = fopen("/proc/stat", "r");
    
    if (fp == NULL) {
        perror("Failed to open /proc/stat");
        return;
    }
    
    fscanf(fp, "cpu %Lf %Lf %Lf %Lf", &b[0], &b[1], &b[2], &b[3]);
    fclose(fp);

    // Calculate the usage
    long double idle_time = b[3] - a[3];
    long double total_time = (b[0] + b[1] + b[2] + b[3]) - (a[0] + a[1] + a[2] + a[3]);
    
    *cpu_usage = (1 - (idle_time / total_time)) * 100.0;
}

void print_header() {
    printf("\n");
    printf("=========================================\n");
    printf("         CPU Usage Monitor              \n");
    printf("=========================================\n");
    printf("           Happy CPU Monitoring!       \n");
    printf("=========================================\n");
}

void print_cpu_usage(double usage) {
    printf("Current CPU Usage: %.2lf%%\n", usage);
}

void monitor_cpu_usage(int interval) {
    double cpu_usage;

    while (1) {
        get_cpu_usage(&cpu_usage);
        print_cpu_usage(cpu_usage);
        sleep(interval);
    }
}

int main(int argc, char *argv[]) {
    int interval = 1; // Default to 1 second

    // Check for command line argument for interval
    if (argc > 1) {
        interval = atoi(argv[1]);
        
        if (interval <= 0) {
            printf("Interval should be a positive integer. Defaulting to 1 second.\n");
            interval = 1;
        }
    }

    print_header();
    monitor_cpu_usage(interval);
    
    return 0;
}