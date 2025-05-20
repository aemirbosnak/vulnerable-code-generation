//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_SAMPLES 100

struct cpu_sample {
    double user;
    double nice;
    double system;
    double idle;
    double iowait;
    double irq;
    double softirq;
    double steal;
    double guest;
    double guest_nice;
};

double calc_cpu_usage(struct cpu_sample *before, struct cpu_sample *after) {
    // Calculate the difference between the before and after samples
    double delta_user = after->user - before->user;
    double delta_nice = after->nice - before->nice;
    double delta_system = after->system - before->system;
    double delta_idle = after->idle - before->idle;
    double delta_iowait = after->iowait - before->iowait;
    double delta_irq = after->irq - before->irq;
    double delta_softirq = after->softirq - before->softirq;
    double delta_steal = after->steal - before->steal;
    double delta_guest = after->guest - before->guest;
    double delta_guest_nice = after->guest_nice - before->guest_nice;

    // Calculate the total difference
    double delta_total = delta_user + delta_nice + delta_system + delta_idle + delta_iowait + delta_irq + delta_softirq + delta_steal + delta_guest + delta_guest_nice;

    // If the total difference is 0, then the CPU usage is 0%
    if (delta_total == 0) {
        return 0.0;
    }

    // Calculate the CPU usage as the percentage of the total difference
    return ((delta_user + delta_nice + delta_system) / delta_total) * 100.0;
}

int main(void) {
    // Create an array to store the CPU samples
    struct cpu_sample samples[MAX_SAMPLES];

    // Get the initial CPU sample
    FILE *fp = fopen("/proc/stat", "r");
    fscanf(fp, "cpu %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
        &samples[0].user, &samples[0].nice, &samples[0].system, &samples[0].idle,
        &samples[0].iowait, &samples[0].irq, &samples[0].softirq, &samples[0].steal,
        &samples[0].guest, &samples[0].guest_nice);
    fclose(fp);

    // Loop to get the CPU samples
    for (int i = 1; i < MAX_SAMPLES; i++) {
        // Sleep for 1 second
        sleep(1);

        // Get the CPU sample
        fp = fopen("/proc/stat", "r");
        fscanf(fp, "cpu %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf",
            &samples[i].user, &samples[i].nice, &samples[i].system, &samples[i].idle,
            &samples[i].iowait, &samples[i].irq, &samples[i].softirq, &samples[i].steal,
            &samples[i].guest, &samples[i].guest_nice);
        fclose(fp);

        // Calculate the CPU usage
        double cpu_usage = calc_cpu_usage(&samples[i - 1], &samples[i]);

        // Print the CPU usage
        printf("CPU usage: %.2f%%\n", cpu_usage);
    }

    return 0;
}