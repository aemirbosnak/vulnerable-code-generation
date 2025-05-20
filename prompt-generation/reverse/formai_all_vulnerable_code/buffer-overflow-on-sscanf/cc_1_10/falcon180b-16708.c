//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_PROCESSES 1000
#define MAX_COMMAND_LENGTH 1024

struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
};

int num_processes = 0;
struct process processes[MAX_PROCESSES];

void add_process(int pid, char* command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    processes[num_processes].pid = pid;
    strncpy(processes[num_processes].command, command, MAX_COMMAND_LENGTH);
    num_processes++;
}

void remove_process(int pid) {
    int i;

    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            memmove(&processes[i], &processes[i+1], sizeof(struct process) * (num_processes - i - 1));
            num_processes--;
            break;
        }
    }
}

void print_processes() {
    printf("PID\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    FILE* fp;
    char line[1024];
    int pid;

    printf("Enter a command to search for processes:\n");
    fgets(command, MAX_COMMAND_LENGTH, stdin);

    fp = popen(command, "r");

    if (fp == NULL) {
        printf("Error: Failed to execute command.\n");
        return 1;
    }

    while (fgets(line, 1024, fp)!= NULL) {
        sscanf(line, "%d", &pid);
        add_process(pid, command);
    }

    pclose(fp);

    print_processes();

    return 0;
}