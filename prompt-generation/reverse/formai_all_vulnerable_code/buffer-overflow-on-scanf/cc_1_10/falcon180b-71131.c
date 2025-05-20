//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 10
#define MAX_COMMAND_LENGTH 100

typedef struct process {
    char command[MAX_COMMAND_LENGTH];
    int pid;
    int status;
} process_t;

void launch_process(process_t *process) {
    pid_t child_pid = fork();

    if (child_pid == -1) {
        printf("Error forking process.\n");
        exit(1);
    } else if (child_pid == 0) {
        execlp(process->command, process->command, NULL);
        exit(1);
    } else {
        process->pid = child_pid;
    }
}

void wait_for_process(process_t *process) {
    int status;
    waitpid(process->pid, &status, 0);
    process->status = status;
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    while (num_processes < MAX_PROCESSES) {
        printf("Enter command to launch (or type 'done' to finish):\n");
        scanf("%s", processes[num_processes].command);

        if (strcmp(processes[num_processes].command, "done") == 0) {
            break;
        }

        launch_process(&processes[num_processes]);
        num_processes++;
    }

    for (int i = 0; i < num_processes; i++) {
        wait_for_process(&processes[i]);
        printf("Process %d exited with status %d.\n", processes[i].pid, processes[i].status);
    }

    return 0;
}