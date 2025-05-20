//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define INTERVAL_TIME 1

// Function to get the CPU usage in percentage
int get_cpu_usage(int pid) {
    struct rusage usage;
    if (getrusage(RUSAGE_SELF, &usage) == -1) {
        return -1;
    }
    return (int) ((usage.ru_utime.tv_sec + usage.ru_stime.tv_sec) * 100 / INTERVAL_TIME);
}

// Function to print the CPU usage in a shocked style
void print_cpu_usage(int cpu_usage) {
    if (cpu_usage < 0) {
        printf("CPU Usage: -1%\n");
    } else if (cpu_usage == 0) {
        printf("CPU Usage: 0%\n");
    } else {
        printf("CPU Usage: %d%%\n", cpu_usage);
    }
}

// Function to monitor the CPU usage of a given process
void monitor_cpu_usage(int pid) {
    int cpu_usage;
    while (1) {
        cpu_usage = get_cpu_usage(pid);
        if (cpu_usage == -1) {
            printf("Error getting CPU usage\n");
            exit(1);
        }
        print_cpu_usage(cpu_usage);
        sleep(INTERVAL_TIME);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <process_id>\n", argv[0]);
        exit(1);
    }
    int pid = atoi(argv[1]);
    if (pid <= 0) {
        printf("Invalid process ID\n");
        exit(1);
    }
    printf("Monitoring CPU usage of process %d...\n", pid);
    monitor_cpu_usage(pid);
    return 0;
}