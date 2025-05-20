//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define MAX_PROCESSES 1024

struct process_info {
    int pid;
    char name[16];
    int cpu_usage;
};

void get_processes_info(struct process_info *processes, int num_processes) {
    FILE *fp;
    char line[1024];
    char *token;
    int i = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (sscanf(line, "cpu %d", &processes[i].cpu_usage) == 1) {
            sprintf(processes[i].name, "Process %d", processes[i].cpu_usage);
            i++;
        }
    }

    fclose(fp);
}

int main() {
    int num_processes = 0;
    struct process_info processes[MAX_PROCESSES];

    while (num_processes == 0 || num_processes == MAX_PROCESSES) {
        printf("Enter number of processes to monitor (1-%d): ", MAX_PROCESSES - 1);
        scanf("%d", &num_processes);
    }

    get_processes_info(processes, num_processes);

    while (1) {
        sleep(1);
        get_processes_info(processes, num_processes);

        printf("\nProcess ID\tName\tCPU Usage\n");
        for (int i = 0; i < num_processes; i++) {
            printf("%d\t%s\t%d%%\n", processes[i].pid, processes[i].name, processes[i].cpu_usage);
        }
    }

    return 0;
}