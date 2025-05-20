//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>
#include <sys/resource.h>

#define MAX_CPU_USAGE 100

// Function to get the current CPU usage in percentage
float get_cpu_usage() {
    struct tms buffer;
    clock_t t = times(&buffer);
    float cpu_usage = ((float) (buffer.tms_utime + buffer.tms_stime) / (float) t) * 100;
    return cpu_usage;
}

int main() {
    int i = 0;
    float cpu_usage;
    struct rusage usage;

    // Get the current CPU usage and print it
    getrusage(RUSAGE_SELF, &usage);
    printf("Initial CPU usage: %.2f%%\n", usage.ru_utime.tv_sec + usage.ru_stime.tv_sec * 100);

    // Start monitoring the CPU usage
    while(1) {
        cpu_usage = get_cpu_usage();

        // Print the current CPU usage
        printf("CPU usage: %.2f%%\n", cpu_usage);

        // Change the color of the terminal based on the CPU usage
        if(cpu_usage <= 50) {
            printf("\033[32mCPU usage is low\033[0m\n");
        }
        else if(cpu_usage > 50 && cpu_usage <= 80) {
            printf("\033[33mCPU usage is moderate\033[0m\n");
        }
        else {
            printf("\033[31mCPU usage is high\033[0m\n");
        }

        // Wait for 1 second before updating the CPU usage again
        sleep(1);

        // Check if the program has been running for too long
        i++;
        if(i >= MAX_CPU_USAGE) {
            break;
        }
    }

    return 0;
}