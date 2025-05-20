//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 100
#define MAX_PROCESS_NAME_LENGTH 100

typedef struct process_info {
    int pid;
    char command[MAX_COMMAND_LENGTH];
    char process_name[MAX_PROCESS_NAME_LENGTH];
    float cpu_usage;
} process_info_t;

process_info_t processes[MAX_PROCESSES];
int num_processes = 0;

void read_processes() {
    FILE *fp;
    char line[MAX_COMMAND_LENGTH];
    char process_name[MAX_PROCESS_NAME_LENGTH];
    float cpu_usage;
    int i = 0;

    fp = fopen("/proc/stat", "r");
    if (fp == NULL) {
        printf("Error: Unable to open /proc/stat\n");
        exit(1);
    }

    while (fgets(line, MAX_COMMAND_LENGTH, fp)!= NULL) {
        if (sscanf(line, "cpu %d %s %f", &i, process_name, &cpu_usage) == 3) {
            strcpy(processes[num_processes].command, "");
            strcpy(processes[num_processes].process_name, process_name);
            processes[num_processes].pid = i;
            processes[num_processes].cpu_usage = cpu_usage;
            num_processes++;
        }
    }

    fclose(fp);
}

int main() {
    int i, status;
    pid_t pid;

    read_processes();

    while (1) {
        system("clear");

        printf("Process ID\tCommand\tCPU Usage\n");

        for (i = 0; i < num_processes; i++) {
            printf("%d\t%s\t%.2f%%\n", processes[i].pid, processes[i].process_name, processes[i].cpu_usage);
        }

        sleep(1);
    }

    return 0;
}