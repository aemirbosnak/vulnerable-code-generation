//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/times.h>

// Get CPU usage in percentage
double get_cpu_usage() {
    struct tms tms;
    clock_t hz = sysconf(_SC_CLK_TCK);
    if (times(&tms) == -1) {
        perror("times");
        return -1;
    }
    return ((double)(tms.tms_utime + tms.tms_stime) / hz) * 100.0;
}

// Print CPU usage in a dynamic style
void print_cpu_usage(double cpu_usage) {
    int i, j;
    int num_bars = 30;
    int bar_width = 10;
    int num_spaces = 1;

    // Calculate the number of filled bars
    int num_filled_bars = (int)(cpu_usage / 100.0 * num_bars);

    // Print the filled bars
    printf("[");
    for (i = 0; i < num_filled_bars; i++) {
        for (j = 0; j < bar_width; j++) {
            printf("█");
        }
        printf(" ");
    }

    // Print the empty bars
    for (i = num_filled_bars; i < num_bars; i++) {
        for (j = 0; j < bar_width; j++) {
            printf(" ");
        }
        printf(" ");
    }

    // Print the percentage
    printf("] %.1f%%", cpu_usage);
    printf("\r");
}

int main() {
    while (1) {
        double cpu_usage = get_cpu_usage();
        print_cpu_usage(cpu_usage);
        usleep(100000);  // Sleep for 100 milliseconds
    }
    return 0;
}