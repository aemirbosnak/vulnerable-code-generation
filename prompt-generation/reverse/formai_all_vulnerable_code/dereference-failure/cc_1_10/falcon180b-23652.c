//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 1024
#define MAX_NAME_LENGTH 32

typedef struct process {
    int pid;
    char name[MAX_NAME_LENGTH];
} Process;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <process_name>\n", argv[0]);
        return 1;
    }

    char *process_name = argv[1];
    int num_processes = 0;
    Process *processes = malloc(MAX_PROCESSES * sizeof(Process));

    if (processes == NULL) {
        printf("Error: Could not allocate memory for processes.\n");
        return 1;
    }

    FILE *fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/self/status.\n");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            char *name_start = line + 6;
            char *name_end = strchr(name_start, '\n');
            *name_end = '\0';
            strcpy(processes[num_processes].name, name_start);
        } else if (strncmp(line, "Pid:", 4) == 0) {
            char *pid_start = line + 5;
            char *pid_end = strchr(pid_start, '\n');
            *pid_end = '\0';
            processes[num_processes].pid = atoi(pid_start);
            num_processes++;
        }
    }

    fclose(fp);

    int i;
    for (i = 0; i < num_processes; i++) {
        if (strcmp(processes[i].name, process_name) == 0) {
            printf("Process %s (PID %d)\n", processes[i].name, processes[i].pid);
            break;
        }
    }

    free(processes);
    return 0;
}