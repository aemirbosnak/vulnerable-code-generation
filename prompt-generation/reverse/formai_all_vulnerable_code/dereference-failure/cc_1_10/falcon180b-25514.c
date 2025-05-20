//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LEN 16

typedef struct {
    pid_t pid;
    char name[MAX_PROCESS_NAME_LEN];
    int cpu_usage;
} Process;

void get_process_info(Process* process, int num_processes) {
    FILE* fp;
    char line[1024];
    char name[MAX_PROCESS_NAME_LEN];
    int found = 0;

    fp = fopen("/proc/self/status", "r");
    if (fp == NULL) {
        printf("Error: Could not open /proc/self/status.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (strncmp(line, "Name:", 5) == 0) {
            strncpy(name, line + 6, MAX_PROCESS_NAME_LEN - 1);
            name[MAX_PROCESS_NAME_LEN - 1] = '\0';
        } else if (strncmp(line, "CPU%:", 5) == 0) {
            sscanf(line, "CPU%: %d", &process[found].cpu_usage);
        }

        if (++found >= num_processes) {
            break;
        }
    }

    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <process_name>\n", argv[0]);
        return 1;
    }

    char process_name[MAX_PROCESS_NAME_LEN];
    strncpy(process_name, argv[1], MAX_PROCESS_NAME_LEN - 1);
    process_name[MAX_PROCESS_NAME_LEN - 1] = '\0';

    int num_processes = 0;
    Process processes[MAX_PROCESSES];

    while (num_processes < MAX_PROCESSES && getpid()!= 1) {
        if (kill(getpid(), 0) == 0) {
            get_process_info(&processes[num_processes], MAX_PROCESSES - num_processes);
            num_processes++;
        }
    }

    int found = 0;
    for (int i = 0; i < num_processes; i++) {
        if (strcmp(processes[i].name, process_name) == 0) {
            found = 1;
            printf("Process %s has CPU usage: %.2f%%\n", processes[i].name, processes[i].cpu_usage);
        }
    }

    if (!found) {
        printf("Process not found.\n");
    }

    return 0;
}