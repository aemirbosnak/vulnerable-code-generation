//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LEN 20

typedef struct {
    char name[MAX_PROCESS_NAME_LEN];
    int pid;
    float cpu_usage;
} Process;

int main() {
    int num_processes = 0;
    Process processes[MAX_PROCESSES];
    struct rusage usage;
    FILE *fp;
    char line[1024];

    // Read process list from /proc/ directory
    fp = fopen("/proc/self/stat", "r");
    if (fp == NULL) {
        printf("Error: Failed to open /proc/self/stat\n");
        exit(1);
    }
    fscanf(fp, "%*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %d %*s", &processes[num_processes].pid);
    fclose(fp);

    // Read process name from /proc/ directory
    sprintf(line, "/proc/%d/cmdline", processes[num_processes].pid);
    fp = fopen(line, "r");
    if (fp == NULL) {
        printf("Error: Failed to open %s\n", line);
        exit(1);
    }
    fgets(processes[num_processes].name, MAX_PROCESS_NAME_LEN, fp);
    fclose(fp);
    processes[num_processes].name[strcspn(processes[num_processes].name, "\n")] = '\0';

    // Initialize CPU usage to 0
    processes[num_processes].cpu_usage = 0.0;

    // Read initial CPU usage
    if (getrusage(RUSAGE_SELF, &usage)!= 0) {
        printf("Error: Failed to getrusage\n");
        exit(1);
    }
    processes[num_processes].cpu_usage = ((float) usage.ru_utime.tv_sec + (float) usage.ru_utime.tv_usec / 1000000.0) / (float) usage.ru_stime.tv_sec + (float) usage.ru_stime.tv_usec / 1000000.0;

    while (1) {
        // Read current CPU usage
        if (getrusage(RUSAGE_SELF, &usage)!= 0) {
            printf("Error: Failed to getrusage\n");
            exit(1);
        }
        processes[num_processes].cpu_usage = ((float) usage.ru_utime.tv_sec + (float) usage.ru_utime.tv_usec / 1000000.0) / (float) usage.ru_stime.tv_sec + (float) usage.ru_stime.tv_usec / 1000000.0;

        // Print CPU usage for each process
        printf("Process Name\tPID\tCPU Usage\n");
        for (int i = 0; i < num_processes; i++) {
            printf("%s\t%d\t%.2f\n", processes[i].name, processes[i].pid, processes[i].cpu_usage);
        }
        printf("\n");

        // Sleep for 1 second
        sleep(1);
    }

    return 0;
}