//MISTRAL-7B DATASET v1.0 Category: CPU usage monitor ; Style: relaxed
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <time.h>

#define CPU_PERIOD 1000 // in ms
#define CPU_SAMPLES 10

struct cpu_data {
    long long user;
    long long nice;
    long long sys;
    long long idle;
    long long iowait;
    long long irq;
    long long softirq;
    long long steal;
    long long total;
    long long sum;
};

void print_cpu_usage(struct cpu_data *data) {
    printf("CPU Usage:\n");
    double total_usage = ((data->user + data->nice + data->sys) * 100.0 / data->total);
    printf("Total Usage: %.2f%%\n", total_usage);
    double idle_usage = ((data->idle) * 100.0 / data->total);
    printf("Idle: %.2f%%\n", idle_usage);
    double iowait_usage = ((data->iowait) * 100.0 / data->total);
    printf("I/O Wait: %.2f%%\n", iowait_usage);
    printf("\n");
}

int main() {
    struct cpu_data cpu_data[CPU_SAMPLES];
    int i;

    printf("CPU Usage Monitor v1.0\n");
    printf("------------------------\n");

    for (i = 0; i < CPU_SAMPLES; i++) {
        sysinfo(&cpu_data[i]);
        usleep(CPU_PERIOD);
    }

    struct cpu_data *current_data = &cpu_data[CPU_SAMPLES - 1];

    for (i = 0; i < CPU_SAMPLES - 1; i++) {
        current_data->sum += cpu_data[i].total;
    }

    current_data->total = current_data->sum;
    print_cpu_usage(current_data);

    while (1) {
        usleep(CPU_PERIOD);
        sysinfo(&cpu_data[0]);

        for (i = 1; i < CPU_SAMPLES; i++) {
            cpu_data[i - 1] = cpu_data[i];
        }

        cpu_data[CPU_SAMPLES - 1] = cpu_data[0];

        struct cpu_data *current_data = &cpu_data[CPU_SAMPLES - 1];

        current_data->sum += cpu_data[0].total;

        if (current_data->sum > cpu_data[CPU_SAMPLES - 2].sum) {
            current_data->idle -= cpu_data[0].idle;
            current_data->total += cpu_data[0].total;

            print_cpu_usage(current_data);
        }
    }

    return 0;
}