//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_PROCESSES 1024
#define MAX_PROCESS_NAME_LENGTH 128

struct process_info {
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    int cpu_usage;
};

void get_process_info(struct process_info *processes, int num_processes) {
    FILE *fp;
    char line[256];
    char *token;
    int i = 0;
    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: Unable to open /proc/stat\n");
        exit(1);
    }
    fgets(line, 256, fp); // Skip first line (CPU stats)
    while (fgets(line, 256, fp)!= NULL) {
        if (i >= num_processes) {
            break;
        }
        token = strtok(line, " ");
        strcpy(processes[i].name, token);
        processes[i].pid = atoi(token);
        token = strtok(NULL, " ");
        processes[i].cpu_usage = atoi(token);
        i++;
    }
    fclose(fp);
}

int main() {
    int num_processes = 0;
    struct process_info *processes;
    printf("Enter number of processes to monitor: ");
    scanf("%d", &num_processes);
    processes = malloc(num_processes * sizeof(struct process_info));
    if (processes == NULL) {
        printf("Error: Unable to allocate memory\n");
        exit(1);
    }
    get_process_info(processes, num_processes);
    while (1) {
        sleep(1);
        get_process_info(processes, num_processes);
        for (int i = 0; i < num_processes; i++) {
            printf("%s (PID %d): %.2f%%\n", processes[i].name, processes[i].pid, processes[i].cpu_usage);
        }
    }
    return 0;
}