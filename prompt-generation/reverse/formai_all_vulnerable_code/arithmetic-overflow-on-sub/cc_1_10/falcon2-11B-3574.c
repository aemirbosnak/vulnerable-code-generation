//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize system
    int njobs = 5;
    int ncpus = 4;
    int job[5][3] = {
        {1, 2, 3},
        {2, 3, 4},
        {3, 4, 5},
        {4, 5, 6},
        {5, 6, 7}
    };

    // Initialize time
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Sort jobs by arrival time
    for (int i = 0; i < njobs; i++) {
        for (int j = i + 1; j < njobs; j++) {
            if (job[j][0] < job[i][0]) {
                int temp = job[i][0];
                job[i][0] = job[j][0];
                job[j][0] = temp;
                temp = job[i][1];
                job[i][1] = job[j][1];
                job[j][1] = temp;
                temp = job[i][2];
                job[i][2] = job[j][2];
                job[j][2] = temp;
            }
        }
    }

    // Schedule jobs using shortest job first algorithm
    for (int i = 0; i < njobs; i++) {
        int cpu = -1;
        for (int j = 0; j < ncpus; j++) {
            if (job[i][2] < job[cpu][2]) {
                cpu = j;
            }
        }
        if (cpu!= -1) {
            printf("Job %d started on CPU %d at %ld.%06ld\n", i + 1, cpu + 1, job[i][0] / 1000, job[i][0] % 1000);
        } else {
            printf("Job %d started at %ld.%06ld\n", i + 1, job[i][0] / 1000, job[i][0] % 1000);
        }
    }

    // Get end time
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate execution time
    double exec_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) * 1e-9;

    // Print execution time
    printf("Execution time: %f seconds\n", exec_time);

    return 0;
}