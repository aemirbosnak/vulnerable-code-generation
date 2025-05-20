//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_SAMPLES 100

// Get the current CPU usage in percentage
double get_cpu_usage() {
    FILE *fp;
    char line[1024];
    double user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
    double total;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        return -1.0;
    }

    fgets(line, sizeof(line), fp);
    sscanf(line, "cpu %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
    fclose(fp);

    total = user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice;
    return (user + nice + system) / total * 100.0;
}

// Get the average CPU usage over a period of time
double get_avg_cpu_usage(int num_samples) {
    double total_cpu_usage = 0.0;
    for (int i = 0; i < num_samples; i++) {
        total_cpu_usage += get_cpu_usage();
        sleep(1);
    }
    return total_cpu_usage / num_samples;
}

// Get the standard deviation of the CPU usage over a period of time
double get_stddev_cpu_usage(int num_samples) {
    double avg_cpu_usage = get_avg_cpu_usage(num_samples);
    double total_squared_diff = 0.0;
    for (int i = 0; i < num_samples; i++) {
        double cpu_usage = get_cpu_usage();
        total_squared_diff += pow(cpu_usage - avg_cpu_usage, 2);
    }
    return sqrt(total_squared_diff / num_samples);
}

// Print a histogram of the CPU usage over a period of time
void print_histogram(int num_samples) {
    double avg_cpu_usage = get_avg_cpu_usage(num_samples);
    double stddev_cpu_usage = get_stddev_cpu_usage(num_samples);

    // Create a histogram with 10 bins
    int histogram[10] = {0};
    for (int i = 0; i < num_samples; i++) {
        double cpu_usage = get_cpu_usage();
        int bin = (int)floor((cpu_usage - avg_cpu_usage) / stddev_cpu_usage);
        if (bin >= 0 && bin < 10) {
            histogram[bin]++;
        }
    }

    // Print the histogram
    for (int i = 0; i < 10; i++) {
        printf("%d-%d: %d\n", (int)(avg_cpu_usage + i * stddev_cpu_usage), (int)(avg_cpu_usage + (i + 1) * stddev_cpu_usage), histogram[i]);
    }
}

int main() {
    // Get the average CPU usage over 100 samples
    double avg_cpu_usage = get_avg_cpu_usage(NUM_SAMPLES);

    // Get the standard deviation of the CPU usage over 100 samples
    double stddev_cpu_usage = get_stddev_cpu_usage(NUM_SAMPLES);

    // Print the average and standard deviation of the CPU usage
    printf("Average CPU usage: %.2f%%\n", avg_cpu_usage);
    printf("Standard deviation of CPU usage: %.2f%%\n", stddev_cpu_usage);

    // Print a histogram of the CPU usage
    print_histogram(NUM_SAMPLES);

    return 0;
}