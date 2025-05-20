//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 100

typedef struct {
    int pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} process_t;

int main() {
    int num_processes = 0;
    process_t processes[MAX_PROCESSES];

    while (num_processes < MAX_PROCESSES) {
        printf("Enter process ID (or -1 to quit): ");
        int pid;
        scanf("%d", &pid);

        if (pid == -1) {
            break;
        }

        if (num_processes >= MAX_PROCESSES) {
            printf("Maximum number of processes reached.\n");
            continue;
        }

        processes[num_processes] = (process_t) {.pid = pid };
        num_processes++;
    }

    for (int i = 0; i < num_processes; i++) {
        int status;
        waitpid(processes[i].pid, &status, WNOHANG);

        if (WIFEXITED(status)) {
            printf("Process %d exited with status %d.\n", processes[i].pid, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Process %d was terminated by signal %d.\n", processes[i].pid, WTERMSIG(status));
        } else {
            printf("Process %d is still running.\n", processes[i].pid);
        }
    }

    return 0;
}