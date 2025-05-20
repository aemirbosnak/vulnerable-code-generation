//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

process_t processes[MAX_PROCESSES];
int num_processes = 0;

void add_process(int pid, char* command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    process_t* new_process = &processes[num_processes];
    new_process->pid = pid;
    strncpy(new_process->command, command, MAX_COMMAND_LENGTH);
    num_processes++;
}

void remove_process(int pid) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            memmove(&processes[i], &processes[i+1], sizeof(process_t) * (num_processes - i - 1));
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
    while (1) {
        printf("Enter command to run or type 'list' to view processes:\n");
        scanf("%s", command);

        if (strcmp(command, "list") == 0) {
            print_processes();
        } else {
            pid_t pid = fork();

            if (pid == -1) {
                printf("Error: Failed to fork.\n");
            } else if (pid == 0) {
                execlp(command, command, NULL);
                printf("Error: Failed to execute command.\n");
                exit(1);
            } else {
                add_process(pid, command);
            }
        }
    }

    return 0;
}