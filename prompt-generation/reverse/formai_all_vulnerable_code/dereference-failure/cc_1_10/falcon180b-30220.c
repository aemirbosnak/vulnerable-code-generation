//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

#define MAX_PROCESSES 10
#define MAX_COMMAND_LENGTH 1024
#define MAX_PROCESS_NAME_LENGTH 16

struct process {
    pid_t pid;
    char command[MAX_COMMAND_LENGTH];
    char process_name[MAX_PROCESS_NAME_LENGTH];
    int status;
};

void print_processes(struct process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("PID: %d\n", processes[i].pid);
        printf("Command: %s\n", processes[i].command);
        printf("Process Name: %s\n", processes[i].process_name);
        printf("Status: %d\n\n", processes[i].status);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    printf("Enter the number of processes to monitor: ");
    scanf("%d", &num_processes);

    for (int i = 0; i < num_processes; i++) {
        printf("Enter the command for process %d: ", i + 1);
        scanf("%s", processes[i].command);
        processes[i].process_name[0] = '\0';
        strncpy(processes[i].process_name, basename(processes[i].command), MAX_PROCESS_NAME_LENGTH - 1);
    }

    printf("Starting process monitoring...\n");

    while (1) {
        for (int i = 0; i < num_processes; i++) {
            pid_t pid = fork();

            if (pid == -1) {
                printf("Error forking process %d\n", i + 1);
                continue;
            } else if (pid > 0) {
                int status;
                waitpid(pid, &status, WNOHANG);
                processes[i].status = status;
            } else {
                execlp(processes[i].command, processes[i].command, NULL);
                exit(1);
            }
        }

        sleep(1);
    }

    return 0;
}