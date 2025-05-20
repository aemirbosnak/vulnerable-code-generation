//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define INTERVAL 1 // Time interval in seconds between updates

// Function prototypes
void usage(char *program);
void print_cpu_usage(struct rusage *rusage);

int main(int argc, char **argv) {
    if (argc!= 2) {
        usage(argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    if (pid == 0) {
        printf("Invalid PID\n");
        return 1;
    }

    struct rusage rusage;
    while (1) {
        if (getrusage(RUSAGE_SELF, &rusage) == -1) {
            perror("getrusage");
            return 1;
        }

        print_cpu_usage(&rusage);

        sleep(INTERVAL);
    }

    return 0;
}

void usage(char *program) {
    fprintf(stderr, "Usage: %s <PID>\n", program);
}

void print_cpu_usage(struct rusage *rusage) {
    double total_time = rusage->ru_utime.tv_sec + rusage->ru_stime.tv_sec +
                        rusage->ru_utime.tv_usec / 1000000.0 + rusage->ru_stime.tv_usec / 1000000.0;
    double cpu_time = rusage->ru_utime.tv_sec + rusage->ru_utime.tv_usec / 1000000.0;

    printf("CPU usage for PID %d:\n", getpid());
    printf("Total time: %.2f seconds\n", total_time);
    printf("CPU time: %.2f seconds (%.2f%%)\n", cpu_time, cpu_time / total_time * 100.0);
}