//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>
#include <sys/resource.h>
#include <string.h>

#define NUM_PROCS 10
#define NUM_ITER 10

int main() {
    int i, j, k, user_time, system_time, total_time;
    struct tms buffer;
    double cpu_usage[NUM_PROCS][NUM_ITER];
    char proc_name[NUM_PROCS][20];
    FILE *fp;

    // Initialize process names
    strcpy(proc_name[0], "Process 1");
    strcpy(proc_name[1], "Process 2");
    strcpy(proc_name[2], "Process 3");
    strcpy(proc_name[3], "Process 4");
    strcpy(proc_name[4], "Process 5");
    strcpy(proc_name[5], "Process 6");
    strcpy(proc_name[6], "Process 7");
    strcpy(proc_name[7], "Process 8");
    strcpy(proc_name[8], "Process 9");
    strcpy(proc_name[9], "Process 10");

    // Open output file
    fp = fopen("cpu_usage.txt", "w");
    if (fp == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Loop through processes
    for (i = 0; i < NUM_PROCS; i++) {
        // Loop through iterations
        for (j = 0; j < NUM_ITER; j++) {
            // Get process ID
            pid_t pid = getpid();

            // Get CPU usage
            times(&buffer);
            user_time = buffer.tms_utime;
            system_time = buffer.tms_stime;
            total_time = user_time + system_time;
            cpu_usage[i][j] = (double) total_time / (double) CLOCKS_PER_SEC;

            // Write to file
            fprintf(fp, "Process %d - Iteration %d: CPU usage = %.2f%%\n", i+1, j+1, cpu_usage[i][j]);
        }
    }

    // Close output file
    fclose(fp);

    return 0;
}