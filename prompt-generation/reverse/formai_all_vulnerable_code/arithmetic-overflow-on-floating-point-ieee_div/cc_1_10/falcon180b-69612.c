//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define NUM_SAMPLES 10

// Function prototypes
void get_cpu_usage(double *utime, double *stime);
void print_usage(double utime, double stime);

int main() {
    double utime[NUM_SAMPLES], stime[NUM_SAMPLES];
    int i;

    // Initialize CPU usage arrays
    for (i = 0; i < NUM_SAMPLES; i++) {
        utime[i] = 0.0;
        stime[i] = 0.0;
    }

    // Get initial CPU usage
    get_cpu_usage(utime, stime);

    // Sleep for 5 seconds
    sleep(5);

    // Get final CPU usage
    get_cpu_usage(utime, stime);

    // Print CPU usage
    for (i = 0; i < NUM_SAMPLES; i++) {
        print_usage(utime[i], stime[i]);
    }

    return 0;
}

// Function to get CPU usage
void get_cpu_usage(double *utime, double *stime) {
    struct rusage usage;

    if (getrusage(RUSAGE_SELF, &usage) == -1) {
        perror("getrusage");
        exit(1);
    }

    *utime = usage.ru_utime.tv_sec + usage.ru_utime.tv_usec / 1000000.0;
    *stime = usage.ru_stime.tv_sec + usage.ru_stime.tv_usec / 1000000.0;
}

// Function to print CPU usage
void print_usage(double utime, double stime) {
    double total_time = utime + stime;
    double cpu_usage = (total_time - stime) / total_time * 100.0;

    printf("CPU Usage: %.2f%%\n", cpu_usage);
}