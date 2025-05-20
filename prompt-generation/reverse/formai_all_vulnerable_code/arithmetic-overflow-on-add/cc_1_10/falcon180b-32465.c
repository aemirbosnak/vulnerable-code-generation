//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <sys/resource.h>

#define PAGE_SIZE (4*1024) // page size is 4KB

// Function to get current time in microseconds
unsigned long long int get_current_time_us() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000LL) + tv.tv_usec;
}

// Function to get CPU usage as a percentage
float get_cpu_usage(pid_t pid) {
    FILE *fp;
    char filename[20];
    sprintf(filename, "/proc/%d/stat", pid);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        return -1;
    }
    int utime, stime, cutime, cstime;
    if (fscanf(fp, "%*d %*s %*c %*d %*d %*d %*d %*d %d %d %d %d", &utime, &stime, &cutime, &cstime)!= 4) {
        fclose(fp);
        return -1;
    }
    float cpu_usage = (float)(utime + stime + cutime + cstime) / (float)get_current_time_us();
    fclose(fp);
    return cpu_usage;
}

// Function to get RAM usage as a percentage
float get_ram_usage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    float ram_usage = (float)usage.ru_maxrss / (float)(getpagesize() * getpagesize());
    return ram_usage;
}

// Function to print system information
void print_system_info() {
    printf("System Information:\n");
    printf("CPU Usage: %.2f%%\n", get_cpu_usage(getpid()));
    printf("RAM Usage: %.2f%%\n", get_ram_usage());
}

int main() {
    int interval = 5; // interval in seconds
    while (1) {
        print_system_info();
        sleep(interval);
    }
    return 0;
}