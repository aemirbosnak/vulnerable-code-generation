//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50
#define MAX_COMMAND_LENGTH 100

struct process {
    int pid;
    char name[MAX_PROCESS_NAME_LENGTH];
    char command[MAX_COMMAND_LENGTH];
};

int num_processes = 0;
struct process processes[MAX_PROCESSES];

void print_processes() {
    printf("PID\tName\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%s\n", processes[i].pid, processes[i].name, processes[i].command);
    }
}

void add_process(int pid, char* name, char* command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    processes[num_processes].pid = pid;
    strncpy(processes[num_processes].name, name, MAX_PROCESS_NAME_LENGTH);
    strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH);

    num_processes++;
}

void remove_process(int pid) {
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            for (int j = i; j < num_processes - 1; j++) {
                processes[j] = processes[j + 1];
            }

            num_processes--;
            break;
        }
    }
}

int main() {
    FILE* procfile = fopen("/proc/self/status", "r");
    if (procfile == NULL) {
        printf("Error: Unable to open /proc/self/status.\n");
        return 1;
    }

    char name[MAX_PROCESS_NAME_LENGTH];
    char command[MAX_COMMAND_LENGTH];

    while (fscanf(procfile, "Name:\t%s\n", name)!= EOF) {
        fscanf(procfile, "Command:\t%s\n", command);

        add_process(getpid(), name, command);
    }

    fclose(procfile);

    while (1) {
        print_processes();
        sleep(5);
    }

    return 0;
}