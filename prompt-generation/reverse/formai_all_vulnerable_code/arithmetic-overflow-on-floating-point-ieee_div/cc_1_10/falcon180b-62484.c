//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <pthread.h>

#define MAX_CPU_USAGE 100

/* Function to get CPU usage */
double get_cpu_usage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    double cpu_usage = ((double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0) / (double)sysconf(_SC_CLK_TCK);
    return cpu_usage;
}

/* Function to print CPU usage */
void print_cpu_usage(double cpu_usage) {
    printf("CPU usage: %.2f%%\n", cpu_usage * 100);
}

/* Function to monitor CPU usage */
void *monitor_cpu_usage(void *arg) {
    while (1) {
        double cpu_usage = get_cpu_usage();
        if (cpu_usage > MAX_CPU_USAGE) {
            printf("CPU usage exceeded maximum limit of %.2f%%\n", MAX_CPU_USAGE * 100);
            exit(1);
        }
        print_cpu_usage(cpu_usage);
        sleep(1);
    }
}

int main() {
    pthread_t thread_id;
    int ret;

    /* Create thread to monitor CPU usage */
    ret = pthread_create(&thread_id, NULL, monitor_cpu_usage, NULL);
    if (ret!= 0) {
        printf("Error creating thread: %s\n", strerror(errno));
        exit(1);
    }

    /* Sleep for 10 seconds before exiting */
    sleep(10);

    return 0;
}