//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 80

typedef struct process {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

int num_processes = 0;
process_t *processes = NULL;

void add_process(pid_t pid, char *command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    process_t *new_process = malloc(sizeof(process_t));
    if (new_process == NULL) {
        printf("Error: Memory allocation failed.\n");
        return;
    }

    new_process->pid = pid;
    strncpy(new_process->command, command, MAX_COMMAND_LENGTH);
    processes[num_processes++] = *new_process;
}

void remove_process(pid_t pid) {
    int i;
    for (i = 0; i < num_processes; i++) {
        if (processes[i].pid == pid) {
            memmove(&processes[i], &processes[i + 1], sizeof(process_t) * (num_processes - i - 1));
            num_processes--;
            return;
        }
    }
}

void print_processes() {
    printf("PID\t\tCommand\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("Enter a command: ");
        scanf("%s", input);

        pid_t pid = fork();
        if (pid == -1) {
            printf("Error: Fork failed.\n");
            continue;
        } else if (pid == 0) {
            if (execlp(input, input, NULL) == -1) {
                printf("Error: Exec failed.\n");
                exit(1);
            }
        } else {
            add_process(pid, input);
        }
    }

    return 0;
}