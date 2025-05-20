//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

#define NUM_PROCS 10
#define SLEEP_TIME 2

int main(int argc, char *argv[]) {
    int i, j;
    int proc_count = 0;
    int proc_id[NUM_PROCS];
    char command[100];
    FILE *fp;
    struct rusage usage;

    // Get the process ID of the current process
    proc_id[proc_count++] = getpid();

    // Read the remaining process IDs from the command line arguments
    for (i = 1; i < argc; i++) {
        sprintf(command, "pgrep %s", argv[i]);
        fp = popen(command, "r");
        fscanf(fp, "%d", &proc_id[proc_count++]);
        pclose(fp);
    }

    // Loop through each process and monitor its CPU usage
    while (1) {
        for (i = 0; i < proc_count; i++) {
            // Get the current CPU usage for the process
            if (getrusage(RUSAGE_SELF, &usage) == -1) {
                printf("Error getting CPU usage for process %d\n", proc_id[i]);
                continue;
            }

            // Calculate the CPU usage percentage
            double cpu_percent = (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0;
            cpu_percent /= (double)SLEEP_TIME;
            cpu_percent *= 100.0;

            // Print the process ID and CPU usage percentage
            printf("Process %d is using %.2f%% of the CPU\n", proc_id[i], cpu_percent);
        }

        // Sleep for SLEEP_TIME seconds before checking again
        sleep(SLEEP_TIME);
    }

    return 0;
}