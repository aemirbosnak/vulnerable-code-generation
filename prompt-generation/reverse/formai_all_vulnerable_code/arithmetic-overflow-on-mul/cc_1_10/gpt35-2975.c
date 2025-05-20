//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_LENGTH 1024

// function definitions
double get_cpu_time();
unsigned long get_ram_usage_kb();

int main() {
    double start_time, end_time, elapsed_time;
    unsigned long start_ram, end_ram, max_ram = 0;
    char dummy[MAX_LENGTH];

    // get initial cpu time and ram usage
    start_time = get_cpu_time();
    start_ram = get_ram_usage_kb();

    // execute some dummy code
    for (int i=0; i<1000000; i++) {
        sprintf(dummy, "This is a dummy string: %d", i);
    }

    // get final cpu time and ram usage
    end_time = get_cpu_time();
    end_ram = get_ram_usage_kb();

    // calculate elapsed time and maximum ram usage
    elapsed_time = end_time - start_time;
    if (end_ram > max_ram) {
        max_ram = end_ram;
    }

    // print results
    printf("CPU time elapsed: %lf seconds\n", elapsed_time);
    printf("Maximum RAM usage: %lu kilobytes\n", max_ram);

    return 0;
}

// function to get current CPU time
double get_cpu_time() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return ((double) usage.ru_utime.tv_sec + (double) usage.ru_utime.tv_usec / 1000000.0);
}

// function to get current RAM usage in kilobytes
unsigned long get_ram_usage_kb() {
    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    return (pages * page_size) / 1024;
}