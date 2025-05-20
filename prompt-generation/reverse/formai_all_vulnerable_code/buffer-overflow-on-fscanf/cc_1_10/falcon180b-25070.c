//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>

#define TOTAL_PROCESSES 1024

int main() {
    int num_processes = 0;
    struct rusage usage;
    pid_t pids[TOTAL_PROCESSES];
    FILE *fp;
    char command[1024];

    if ((fp = fopen("/proc/self/status", "r")) == NULL) {
        printf("Cannot open /proc/self/status\n");
        exit(1);
    }

    if (fscanf(fp, "Name:\t%s", command)!= 1) {
        printf("Error reading command name\n");
        exit(1);
    }

    if (fclose(fp)!= 0) {
        printf("Error closing file\n");
        exit(1);
    }

    num_processes = getrusage(RUSAGE_CHILDREN, &usage);

    if (num_processes > TOTAL_PROCESSES) {
        printf("Error: Too many processes\n");
        exit(1);
    }

    printf("PID\tCPU (%)\tMEM (KB)\tCOMMAND\n");

    for (int i = 0; i < num_processes; i++) {
        if (getrusage(RUSAGE_CHILDREN, &usage)!= 0) {
            printf("Error getting usage\n");
            exit(1);
        }

        snprintf(command, sizeof(command), "/proc/%d/cmdline", pids[i]);

        if ((fp = fopen(command, "r")) == NULL) {
            printf("Cannot open %s\n", command);
            exit(1);
        }

        if (fscanf(fp, "%*s")!= 0) {
            printf("Error reading command\n");
            exit(1);
        }

        if (fclose(fp)!= 0) {
            printf("Error closing file\n");
            exit(1);
        }

        printf("%d\t%.2f\t%d\t%s\n", pids[i], (double)usage.ru_utime.tv_sec * 100.0, usage.ru_maxrss, command);
    }

    return 0;
}