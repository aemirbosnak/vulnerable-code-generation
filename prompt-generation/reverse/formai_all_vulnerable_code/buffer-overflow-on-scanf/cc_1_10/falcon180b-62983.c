//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_PROCESSES 1024

typedef struct {
    char name[32];
    int pid;
    double cpu_usage;
    double mem_usage;
} process_t;

void get_process_info(process_t *processes, int num_processes) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    int i = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error opening /proc/stat\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (i >= num_processes) {
            break;
        }

        token = strtok(line, " ");
        strcpy(processes[i].name, token);
        processes[i].pid = atoi(token);

        token = strtok(NULL, " ");
        processes[i].cpu_usage = atof(token);

        token = strtok(NULL, " ");
        processes[i].mem_usage = atof(token);

        i++;
    }

    fclose(fp);
}

int main() {
    int num_processes = 0;
    process_t processes[MAX_NUM_PROCESSES];

    while (1) {
        printf("Enter the number of processes to monitor (0 to stop): ");
        scanf("%d", &num_processes);

        if (num_processes == 0) {
            break;
        }

        get_process_info(processes, num_processes);

        printf("Process ID\tName\tCPU Usage\tMemory Usage\n");
        for (int i = 0; i < num_processes; i++) {
            printf("%d\t%s\t%.2f%%\t%.2f%%\n", processes[i].pid, processes[i].name, processes[i].cpu_usage, processes[i].mem_usage);
        }
    }

    return 0;
}