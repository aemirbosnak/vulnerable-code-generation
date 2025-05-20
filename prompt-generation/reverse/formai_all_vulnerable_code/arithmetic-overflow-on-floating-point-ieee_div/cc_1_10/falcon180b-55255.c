//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/resource.h>

typedef struct {
    float cpu_percent;
    float mem_percent;
    float swap_percent;
} system_info;

void get_cpu_usage(struct rusage *usage) {
    static system_info prev_info;
    system_info curr_info;
    static int first_time = 1;

    if (first_time) {
        first_time = 0;
        getrusage(RUSAGE_SELF, &prev_info.cpu_percent);
        return;
    }

    getrusage(RUSAGE_SELF, &curr_info.cpu_percent);

    curr_info.cpu_percent -= prev_info.cpu_percent;
    curr_info.mem_percent = (float) (getrusage(RUSAGE_SELF, &usage->ru_maxrss) / 1024.0) / (float) (getpagesize());
    curr_info.swap_percent = (float) (getrusage(RUSAGE_SELF, &usage->ru_maxrss) / 1024.0) / (float) (getpagesize());

    prev_info = curr_info;
}

void print_system_info(system_info *info) {
    printf("CPU Usage: %.2f%%\n", info->cpu_percent);
    printf("Memory Usage: %.2f%%\n", info->mem_percent);
    printf("Swap Usage: %.2f%%\n", info->swap_percent);
}

int main(int argc, char *argv[]) {
    system_info curr_info;
    struct rusage usage;

    printf("Starting CPU Usage Monitor...\n");

    while (1) {
        printf("\n");
        get_cpu_usage(&usage);
        printf("Current CPU Usage:\n");
        print_system_info(&curr_info);
        sleep(5);
    }

    return 0;
}