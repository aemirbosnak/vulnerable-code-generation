//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_PROCESSES 100

int main(int argc, char *argv[]) {
    int num_processes = 0;
    int process_ids[MAX_PROCESSES];
    int i = 0;
    struct rusage usage;
    struct timeval start_time;
    struct timeval end_time;

    gettimeofday(&start_time, NULL);

    // Get the process IDs of all running processes
    FILE *fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: could not open /proc/self/status\n");
        exit(1);
    }

    while (fscanf(fp, "%d", &process_ids[i])!= EOF) {
        i++;
        if (i == MAX_PROCESSES) {
            printf("Error: too many processes running\n");
            exit(1);
        }
    }

    fclose(fp);

    while (1) {
        for (int j = 0; j < num_processes; j++) {
            if (process_ids[j] == 0) {
                continue;
            }

            if (getrusage(RUSAGE_CHILDREN, &usage) == -1) {
                printf("Error: could not get usage for process %d\n", process_ids[j]);
                exit(1);
            }

            printf("Process %d: CPU usage %.2f%%\n", process_ids[j], (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0 * 100.0);
        }

        gettimeofday(&end_time, NULL);
        double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;

        if (elapsed_time >= 5.0) {
            break;
        }

        usleep(1000000);
    }

    return 0;
}