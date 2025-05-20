//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define MAX_CPU_USAGE 100

struct rusage cpu_usage;

void get_cpu_usage(int pid) {
    if (getrusage(RUSAGE_SELF, &cpu_usage) == -1) {
        perror("getrusage");
        exit(EXIT_FAILURE);
    }
}

double calculate_cpu_usage(struct rusage current_usage, struct rusage previous_usage) {
    double cpu_percentage = 0.0;
    double idle_percentage = 0.0;
    double total_percentage = 0.0;

    if (current_usage.ru_utime.tv_sec - previous_usage.ru_utime.tv_sec > 0) {
        cpu_percentage = ((double)(current_usage.ru_utime.tv_sec - previous_usage.ru_utime.tv_sec) * 100) / (double)(current_usage.ru_utime.tv_sec);
    }
    if (current_usage.ru_stime.tv_sec - previous_usage.ru_stime.tv_sec > 0) {
        idle_percentage = ((double)(current_usage.ru_stime.tv_sec - previous_usage.ru_stime.tv_sec) * 100) / (double)(current_usage.ru_stime.tv_sec);
    }
    total_percentage = cpu_percentage + idle_percentage;
    return total_percentage;
}

void print_cpu_usage(double cpu_percentage) {
    printf("CPU Usage: %.2f%%\n", cpu_percentage);
}

int main(int argc, char *argv[]) {
    int pid = getpid();
    struct rusage previous_usage;
    struct rusage current_usage;
    double cpu_percentage = 0.0;
    int i = 0;

    if (argc!= 2) {
        printf("Usage: %s <interval in seconds>\n", argv[0]);
        return 1;
    }

    get_cpu_usage(pid);
    previous_usage = cpu_usage;

    while (1) {
        sleep(atoi(argv[1]));

        get_cpu_usage(pid);
        current_usage = cpu_usage;

        cpu_percentage = calculate_cpu_usage(current_usage, previous_usage);

        if (cpu_percentage > MAX_CPU_USAGE) {
            printf("CPU usage is too high!\n");
        } else {
            print_cpu_usage(cpu_percentage);
        }

        previous_usage = current_usage;
    }

    return 0;
}